import { ConsoleLogger, Injectable } from '@nestjs/common';
import { CreateMessageDto } from './dto/create-message.dto';
import prisma from '../../prisma/prisma.client';
import { Message } from './entities/message.entity';
import { DateTime } from 'luxon';
import { find } from 'rxjs';
import * as bcrypt from 'bcrypt';

export const saltOrRounds = 10;

@Injectable()
export class MessagesService {

	async updateUserAllChatConnectionStatus( userId: number, isConnect: boolean) {
		const channelUsers = await prisma.channelUser.findMany({
			where: {
				userID: userId,
			}
		})
		if (!channelUsers)
			throw "We experiencing issues. We will get back to you as soon as possible. in updateUserAllChatConnectionStatus, channelUsers are null "
		await prisma.channelUser.updateMany({
			where: {userID: {in: channelUsers.map(channelUser => channelUser.userID)}},
			data: {
				isConnect: isConnect,
			}
		})
	}

	async updateUserChatConnectionStatus( userId: number, channelId: number, isConnect: boolean) {
		const channelUser = await prisma.channelUser.findFirst({
			where: {
				channelId: channelId,
				userID: userId,
			}
		})
		if (!channelUser)
			throw "We experiencing issues. We will get back to you as soon as possible. in updateUserChatConnectionStatus, channelUsers is null"
		await prisma.channelUser.update({
			where: {id: channelUser.id},
			data: {
				isConnect: isConnect,
			}
		})
	}

	async identify(userId: number, channelId: number) {
		const channel = await this.findChannelById(channelId);
		if (!channel)
			throw `this channel does not exist.`
		const user = await this.findUserInfo(userId, null);
		if (!user)
			throw "cant find user."
		const channelUser = await prisma.channelUser.findFirst({
			where: {
				userName: user.username,
				channelId: channel.id,
			},
		})
		if (!channelUser && channel.status !== "public" && channel.status !== "protected")
			throw "you cannot join this channel !"
		else if (!channelUser)
		{
			const createUser = await prisma.channelUser.create({
				data: {
					userName: user.username,
					user: {
						connect: { id: user.id}
					},
					channel: {
						connect: { id: channel.id}
					}
				}
			})
			await prisma.user.update({
				where: {id: user.id},
				data : {
					channelUsers: {
						 connect: {id: createUser.id}
					}
				}
			})
			await prisma.channel.update({
				where: {id: channel.id},
				data: {
					users: {
						connect: {id: createUser.id}
					}
				}
			})
		}
		const isPunished = await this.checkUserPunishment(userId, channel.id);
		if (isPunished && isPunished.type != "mute") {
			throw `you are ${isPunished.type}, remaining time = ${isPunished.minutesRemaining} minutes`;
		}
		return {ChannelName: channel.ChannelName, id: channel.id};
	}

	async checkUserPunishment(userId: number, channelId: number) {
		const userPunishments = await prisma.punishment.findMany({
			where: {
				punishedId: userId,
				channelId: channelId,
			}
		})
		if (!userPunishments)
			return null;
		let index = userPunishments.findIndex(punishment => punishment.type === "ban");
		if (index === -1) {
			index = userPunishments.findIndex(punishment => punishment.type === "mute");
		}
		// console.log(`index: ${index} ,punishments: ${JSON.stringify(userPunishments)}`)
		if (index === -1)
			return null;
		const punishment = userPunishments[index];
		const dateNow = DateTime.now().toMillis();
		if (punishment.punishmentExpiration > dateNow) {
			const diffMilliseconds = (punishment.punishmentExpiration).getTime() - dateNow;
			const minutesRemaining = Math.floor(diffMilliseconds / (1000 * 60));
			return {type: punishment.type, minutesRemaining: minutesRemaining};
		}
		else {
			await prisma.punishment.delete({
				where: {id: punishment.id}
			})
		}
		return null;
	}

	async createDM(firstUserId: number, secondUserId: number)
	{
		if (firstUserId === secondUserId)
			throw `You cannot DM yourself!`

		const firstUser = await this.findUserInfo(firstUserId, null);

		if (!firstUser)
			throw "We experiencing issues. We will get back to you as soon as possible."
		const secondUser = await this.findUserInfo(secondUserId, null);

		if (!secondUser)
			throw "We experiencing issues. We will get back to you as soon as possible."

		const channelName = firstUser.username + "|" + secondUser.username;

		const hashedEmptyChannelPassword = await bcrypt.hash("", saltOrRounds);
		console.log(`\nCreating DM channel with name [${channelName}] and password [${hashedEmptyChannelPassword}].`)
		const createChannel = await prisma.channel.create({
			data: {
				ChannelName: channelName,
				password: hashedEmptyChannelPassword,
				status: "dm",
			}
		})
		if (!createChannel) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		const firstUserChannel = await prisma.channelUser.create({
			data: {
				userName: firstUser.username,
				status: "user",
				channel: {
					connect: {
						id: createChannel.id,
					},
				},
				user: {
					connect: {
						id: firstUser.id,
					}
				}
			},
		})
		if (!firstUserChannel) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		const secondUserChannel = await prisma.channelUser.create({
			data: {
				userName: secondUser.username,
				status: "user",
				channel: {
					connect: {
						id: createChannel.id,
					},
				},
				user: {
					connect: {
						id: secondUser.id,
					}
				}
			},
		})
		if (!secondUserChannel) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		return {channelId: createChannel.id, firstUserUserName: firstUser.username, secondUserUserName: secondUser.username };
	}

	async createChannel(userId: number, ChannelName: string, Channelpass: string)
	{
		if (!ChannelName || ChannelName.length < 1 || ChannelName.length > 10)
			throw "Channel name must be between 1 and 10 characters long."
		const channel = await prisma.channel.findFirst({
			where: {
				ChannelName: ChannelName,
			},
		})
		if (channel){
			throw  `a channel with "${ChannelName}" as name already exists`
		}
		const hashedChannelPassword = await bcrypt.hash(Channelpass, saltOrRounds);
		console.log(`\nCreating channel with name [${ChannelName}] and password [${hashedChannelPassword}].`)
		const createChannel = await prisma.channel.create({
			data: {
				status: "protected",
				ChannelName: ChannelName,
				password: hashedChannelPassword,
			}
		})
		if (!createChannel) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		const user = await this.findUserInfo(userId, null);
		if (!user)
			throw "cant find user."
		const createUser = await prisma.channelUser.create({
			data: {
				userName: user.username,
				status: "owner",
				channel: {
					connect: {
						id: createChannel.id,
					},
				},
				user: {
					connect: {
						id: user.id,
					}
				}
			},
		})
		if (!createUser) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		return {ChannelName: createChannel.ChannelName, id: createChannel.id};
	}

	async findWhoDontBlockedMe(userId: number, channelId: number)
	{
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			throw  "We experiencing issues. We will get back to you as soon as possible. in findWhodDontBlockme, channel is null"
		}
		const user = await this.findUserInfo(userId, null);
		if (!user)
			throw  "We experiencing issues. We will get back to you as soon as possible."
		const channelUser = await prisma.channelUser.findFirst({
			where: {
				userName: user.username,
				channelId: channel.id
			}
		})
		if (!channelUser) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		const blockedByUsers = await prisma.block.findMany({
			where: {
				blocked: channelUser.userID,
			},
			// include: {
			// 	blockedBy: true,
			// },
		});
		if (blockedByUsers){
			const channelUsers = await prisma.channelUser.findMany({
				where: {
					channelId: channel.id,
					NOT: {
						userID: {
							in: blockedByUsers.map((blcokedUser) => blcokedUser.blocker)
						}
					}
				},
			})
			return channelUsers;
		}
		const channelUsers = await prisma.channelUser.findMany({
			where: {
				channelId: channel.id,
			},
		})
		return channelUsers;
	}

	async findwhoIDontBlocked(userId: number, channelId: number)
	{
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			throw  "We experiencing issues. We will get back to you as soon as possible. in findwhoIDontBlocked, channel is null"
		}
		const user = await this.findUserInfo(userId, null);
		if (!user)
			throw  "We experiencing issues. We will get back to you as soon as possible."
		const channelUser = await prisma.channelUser.findFirst({
			where: {
				userName: user.username,
				channelId: channel.id
			}
		})
		if (!channelUser) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		const blockedByUsers = await prisma.block.findMany({
			where: {
				blocker: channelUser.userID,
			},
			// include: {
			// 	blockedUser: true,
			// },
		});
		if (blockedByUsers){
			// console.log(`users blocked by user ${userId}: ${JSON.stringify(blockedByUsers)}`)
			const channelUsers = await prisma.channelUser.findMany({
				where: {
					channelId: channel.id,
					NOT: {
						userID: {
							in: blockedByUsers.map((blcokedUser) => blcokedUser.blocked)
						}
					}
				},
			})
			return channelUsers;
		}
		const channelUsers = await prisma.channelUser.findMany({
			where: {
				channelId: channel.id,
			},
		})
		return channelUsers;
	}

	async findChannelUser(userId: number, channelId: number)
	{
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			throw  "We experiencing issues. We will get back to you as soon as possible. findChannelUsers, channel is null"
		}
		const user = await this.findUserInfo(userId, null);
		if (!user)
			throw  "We experiencing issues. We will get back to you as soon as possible."
		const channelUser = await prisma.channelUser.findFirst({
			where: {
				userName: user.username,
				channelId: channel.id
			}
		})
		if (!channelUser)
			return false;
		return true;
	}

	async findChannels(userId: number) {
		const channelUsers = await prisma.channelUser.findMany({
			where: {
			  userID: userId,
			  channel: {
				NOT: {
					status: "dm"
				}
			  }
			},
			include: {
			  channel: true
			}
		  });
		if (channelUsers.length === 0) {
			return [];
		}
		const channelList = channelUsers.map(channelUser => {
			const { ChannelName, id} = channelUser.channel;
			return { ChannelName, id };
		});
		return channelList;
	}

	async findDirectMessageChannels(userId: number) {
		const channelUsers = await prisma.channelUser.findMany({
			where: {
				userID: userId,
				channel: {
					status: "dm"
				}
			},
			include: {
				channel: {
					include: {
						users: {
							where: {
								userID: { not: userId }
							},
							select: {
								userName: true,
								userID: true,
							},
							take: 1
						}
					}
				}
			}
		});

		if (!channelUsers && channelUsers.length === 0 ) {
			return [];
		}
		const channelList = channelUsers.map((channelUser) => {
			const { id, users } = channelUser.channel; 
			const otherUser = users[0];
			// console.log(`channelUser.channel.id: ${id}, channelUser.channel.users: ${JSON.stringify(users)}.`)
			return {channelId: id, otherUserId: otherUser.userID, otherUserUsername: otherUser.userName };
		});

		return channelList;
	}


	async findChannelByNameAndPass(ChannelName: string, Channelpass: string)
	{
		const hashedChannelPassword = await bcrypt.hash(Channelpass, saltOrRounds);
		// console.log(`\nSearching for channel with name [${ChannelName}] and password [${hashedChannelPassword}].`)
		//First find the channel by name
		const channel = await prisma.channel.findFirst({
			where: {
				ChannelName: ChannelName,
				// password: hashedChannelPassword
			},
			include: {users: true, textChannels: true},
		})
		if (!channel)
			throw ` (${ChannelName}) channel does not exist.`
		//Then check if the provided password matches the hashed password
		const passwordsMatch = await bcrypt.compare(Channelpass, channel.password)
		// console.log(`passwordsMatch is ${passwordsMatch}`)
		if (passwordsMatch === false)
			throw `Provided password does not match ${ChannelName}'s password.`
		return channel;
	}

	async findChannelById(ChannelId: number)
	{
		const channel = await prisma.channel.findUnique({
			where: {
				id: ChannelId
			},
			include: {users: true, textChannels: true},
		})
		return channel;
	}

	async findAllInvitations(userId: number) {
		const invitations = await prisma.invitation.findMany({
			where: {
				invitedID: userId
			},
		  });
		if (invitations.length === 0) {
			return [];
		}
		return invitations;
	}

	async createInvitaion(userId: number, invitedId: number, type: string, whereID: number) {
		const user = await this.findUserInfo(userId, null);
		if (!user)
			throw  "We experiencing issues. We will get back to you as soon as possible."
		const invitedUser = await this.findUserInfo(invitedId, null);
		if (!invitedUser)
			throw  "We experiencing issues. We will get back to you as soon as possible."
		
		const alreadyInvited = await prisma.invitation.findFirst({
			where: {
				whereID: whereID,
				invitedID: invitedUser.id,
			}
		})
		if (alreadyInvited){
			throw  "this user already have been invited here !";
		}
		const invitation = await prisma.invitation.create({
			data: {
				type: type,
				whereID: whereID,
				whoInviteUserName: user.username,
				invited: {
					connect: {
						id: invitedUser.id
					}
				}
			}
		})
		return invitation;
	}

	async joinInvitation(userId: number, invitationId: number, accepted: boolean) {
		if (accepted == false)
		{
			await prisma.invitation.delete({
				where: {
					id: invitationId
				}
			})
			return false;
		}
		const invitation = await prisma.invitation.findUnique({
			where: {
				id: invitationId
			},
		});
		if (!invitation)
			return false;
		if (invitation.type == "chat")
		{
			const user = await this.findUserInfo(userId, null);
			if (!user)
				throw "cant find user."	
			const channel = await prisma.channel.findUnique({
				where: {id: invitation.whereID}
			})
			const createUser = await prisma.channelUser.create({
				data: {
					userName: user.username,
					user: {
						connect: { id: user.id}
					},
					channel: {
						connect: { id: channel.id}
					}
				}
			})
			await prisma.user.update({
				where: {id: user.id},
				data : {
					channelUsers: {
						 connect: {id: createUser.id}
					}
				}
			})
			await prisma.channel.update({
				where: {id: channel.id},
				data: {
					users: {
						connect: {id: createUser.id}
					}
				}
			})
			await prisma.invitation.delete({
				where: {id: invitation.id}
			})
			return { ChannelName: channel.ChannelName, id: channel.id };
		}
	}

	async findChannelOwner(channelId: number) {
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		const owner = await prisma.channelUser.findFirst({
			where:{
				status: "owner",
				channelId: channel.id
			}
		})
		return owner;
	}

	async findChannelAdmins(channelId: number) {
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			return null;
		}
		const admins = await prisma.channelUser.findMany({
			where:{
				status: "admin",
				channelId: channel.id
			}
		})
		return admins;
	}

	async findUserInfo(userID: number, userName: string) {
		if (userName !== null)
		{
			const user = await prisma.user.findFirst({
				where: {
					username: userName
				}
			})
			return user;
		}
		const user = await prisma.user.findUnique({
			where: {
				id: userID,
			}
		})
		// console.log(user)
		return user;
	}

	async isSuperUser(channelId: number, channelUserId: number) {
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			// console.log(`Channel is null`)
			return false;
		}
		const user = await prisma.channelUser.findFirst({
			where: {
				userID: channelUserId,
				channelId: channelId,
			}
		});
		if (!user) {
			// console.log(`user is null`)
			return false;
		}
		const owner = await this.findChannelOwner(channelId);
		if (owner.id == user.id) {
			// console.log(`owner.id == user.id`)
			return true;
		}
		const admins = await this.findChannelAdmins(channelId);
		if (!admins) {
			// console.log(`Did not found any channel admins`)
			return false;
		}
		// console.log(`admins.some(admin => admin.id == user.id): `, admins.some(admin => admin.id == user.id) )
		return admins.some(admin => admin.id === user.id) 
	}

	async isOwner(channelId, channelUserId: number) {
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			return false;
		}
		const user = await prisma.channelUser.findFirst({
			where: {
				userID: channelUserId,
				channelId: channelId,
			}
		});
		if (!user)
			return false;
		const owner = await this.findChannelOwner(channelId);
		if (owner.id == user.id)
			return true;
		return false;
	}

	async createMessage(createMessageDto: CreateMessageDto, channelId: number, userId: number) {
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		const user = await this.findUserInfo(userId, null);
		if (!user)
			throw  "We experiencing issues. We will get back to you as soon as possible."
		const channelUser = await prisma.channelUser.findFirst({
			where: {
				userName: user.username,
				channelId: channel.id
			}
		})
		if (!channelUser) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		const isPunished = await this.checkUserPunishment(userId, channel.id);
		if (isPunished) {
			throw `you are ${isPunished.type}, remaining time = ${isPunished.minutesRemaining} minutes`;
		}
		const textChannel	= await prisma.textChannel.create({
			data: {
				name: channelUser.userName,
				text: createMessageDto.text,
				channel: {
					connect: { id: channel.id }
				},
				channelUser: {
					connect: {id: channelUser.id}
				},
			}
		});
		if (!textChannel) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		return textChannel;
	}

	async findChannelMessages(channelId: number) {
		const channel = await this.findChannelById(channelId); 
		if (!channel) { 
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}
		return channel.textChannels;
	}

	async findChannelMessagesForMe(userId: number, channelId: number) {

		const channelUsers = await this.findwhoIDontBlocked(userId, channelId);
		// console.log(`NOT blocked users for user ${userId}: [${JSON.stringify(channelUsers.map(user => user.userName))}]`)
		const channelUserIds = channelUsers.map((channelUser) => channelUser.id);
	  
		const textChannels = await prisma.textChannel.findMany({
			where: {
				channelId: channelId,
				channelUserId: {
					in: channelUserIds,
				}
			}
		});
		return textChannels;
	}

	async nobodyInChannel(channelId: number) {
		const channel = await this.findChannelById(channelId);
		if (!channel) 
			return false;
		const channelUsers = await prisma.channelUser.findMany({
			where: {
				channelId: channel.id
			}
		})
		if (channelUsers.length == 0)
			return true;
		return false;
	}

	async setNewChannelOwner(channelId: number) {
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			return ;
		}
		const channelUsers = await prisma.channelUser.findMany({
			where: {
				channelId: channel.id,
				status: { not: "owner"}
			}
		})
		if (channelUsers.length == 0)
			return ;
		const newOwner = await prisma.channelUser.update({
			where: {
				id: channelUsers[0].id
			},
			data: {
				status: "owner"
			}
		})
		return newOwner;
	}

	async removeChannel(channelId: number) {
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			return ;
		}
		await prisma.textChannel.deleteMany({
			where: {
				channelId: channel.id
			}
		})
		await prisma.channelUser.deleteMany({
			where: {
				channelId: channel.id
			}
		})
		await prisma.channel.delete({
			where: {
				id: channel.id
			}
		})
	}

	async removeChannelUser(channelId: number, channelUserId: number) {
		const channel = await this.findChannelById(channelId);
		if (!channel) {
			throw  `We experiencing issues. We will get back to you as soon as possible.`
		}

		const channelUser = await prisma.channelUser.findFirst({
			where: {
				userID: channelUserId,
				channelId: channel.id
			}
		})
		if (!channelUser) {
			throw  "We experiencing issues. We will get back to you as soon as possible."
		}

		await prisma.textChannel.deleteMany({
			where: {
				channelUserId: channelUser.id
			}
		})
		await prisma.channelUser.delete({
			where: {
				id: channelUser.id,
			}
		})
	}
}
