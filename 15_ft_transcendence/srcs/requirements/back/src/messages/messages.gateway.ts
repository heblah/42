import { WebSocketGateway, SubscribeMessage, MessageBody, WebSocketServer, ConnectedSocket } from '@nestjs/websockets';
import { MessagesService } from './messages.service';
import { CreateMessageDto } from './dto/create-message.dto';
import { Server, Socket } from 'socket.io'
import prisma from '../../prisma/prisma.client';
import { DateTime } from 'luxon';
import { type } from 'os';
import { UseGuards } from '@nestjs/common'
import { WebSocketJwtAuthGuard } from '../jwt/jwt.guard'

//const COMMAND_HELPER: string = "to mute => /mute targetName durationInMinutes\n to block";
import { saltOrRounds } from './messages.service';
import * as bcrypt from 'bcrypt';
type SocketUserIDpair = {socket: Socket, userID: number}
const MAX_REQUEST_BODY_SIZE = 2048;


@WebSocketGateway({
	cors: {
		origin: '*',
	},
})

export class MessagesGateway {
	@WebSocketServer()
	server: Server;
	//properties for pong game invites
	//This Array is used to map userIds to socket and vice versa.
	//We're not using dictionnaries so we can have duplicates,
	//this is usefull(maybe even necessary) for testing on the same machine with the same stud account.
	socketUserIDpairs: SocketUserIDpair[] = [];

	constructor(
		private readonly messagesService: MessagesService,
	) {}

	updateSocketUserIDpairs(socket: Socket, userID: number) {
		const index = this.socketUserIDpairs.findIndex((pair) => pair.userID === userID);
		if (index === -1) {
			this.socketUserIDpairs.push({socket, userID});
		}
		else if (socket !== this.socketUserIDpairs[index].socket){
			this.socketUserIDpairs[index].socket = socket;
		}
	}

	getChannelUserSocket(channelUser: any) {
		const index = this.socketUserIDpairs.findIndex((pair) => pair.userID === channelUser.userID);
		if (index === -1) {
			return null;
		}
		return this.socketUserIDpairs[index].socket;
	}

	getUserSocket(userId: number) {
		const index = this.socketUserIDpairs.findIndex((pair) => pair.userID === userId);
		if (index === -1) {
			return null;
		}
		return this.socketUserIDpairs[index].socket;
	}
	checkRequestBodySize(request: any) {
		const requestBodySize = Buffer.byteLength(JSON.stringify(request));
		if (requestBodySize > MAX_REQUEST_BODY_SIZE) {
		  throw 'Request body size exceeds the limit';
		}
	}

	@SubscribeMessage('findChannel')
	@UseGuards(WebSocketJwtAuthGuard)
	async findChannel(
		@MessageBody('channelName') chatName:string,
		@MessageBody('password') password:string,
		@ConnectedSocket() client: Socket,
	){
		try {
			this.checkRequestBodySize({chatName, password});
			const channel = await this.messagesService.findChannelByNameAndPass(chatName, password);
			return channel.id;
		} catch (serverMessage) {
			this.server.to(client.id).emit('formFailed', serverMessage);
			return -1;
		}
	}

	@SubscribeMessage('updateUserAllChatConnectionStatus')
	@UseGuards(WebSocketJwtAuthGuard)
	async updateUserAllChatConnectionStatus(
		@MessageBody('userId') userId:number,
		@MessageBody('newStatus') newStatus: boolean,
		@ConnectedSocket() client: Socket,
	){
		try {
			this.updateSocketUserIDpairs(client, userId);
			//await this.messagesService.updateUserAllChatConnectionStatus(userId,  newStatus);
			return true;
		} catch (serverMessage) {
			this.server.to(client.id).emit('formFailed', serverMessage);
			return false;
		}
	}

	@SubscribeMessage('updateUserChatConnectionStatus')
	@UseGuards(WebSocketJwtAuthGuard)
	async updateUserChatConnectionStatus(
		@MessageBody('userId') userId:number,
		@MessageBody('channelId') channelId: number,
		@MessageBody('isConnect') isConnect: boolean,
		@ConnectedSocket() client: Socket,
	){
		try {
			console.log(`updateUserChatConnectionStatus ${userId} ${channelId} ${isConnect}`)
			this.updateSocketUserIDpairs(client, userId);
			await this.messagesService.updateUserChatConnectionStatus(userId, channelId, isConnect);
			return true;
		} catch (serverMessage) {
			this.server.to(client.id).emit('formFailed', serverMessage);
			return false;
		}
	}

	@SubscribeMessage('join')
	@UseGuards(WebSocketJwtAuthGuard)
	async joinRoom(
			@MessageBody('userId') userId:number,
			@MessageBody('channelId') channelId: number,
			@ConnectedSocket() client: Socket,
		){
			try {
				this.updateSocketUserIDpairs(client, userId);
				if (await this.messagesService.findChannelUser(userId, channelId) === false) {
					const channelInfo = await this.messagesService.identify(userId, channelId);
					this.server.to(client.id).emit('updateChannels', "add", channelInfo);
				} else {
					await this.messagesService.identify(userId, channelId);
				}
				await this.messagesService.updateUserChatConnectionStatus(userId, channelId, true);

			} catch (serverMessage) {
				this.server.to(client.id).emit('formFailed', serverMessage);
				return false;
			}
			//Code for pong game
			// try {
			// 	console.log(`Added user with ID ${userId} and socket ${client.id} in socketUserIDpairs.`)
			// 	this.socketUserIDpairs.push({socket: client, userID: userId})
			// } catch (err) {
			// 	console.error(`Error caught while adding user and socket to userSocketMap: `, err)
			// }
			return true;
	}

	@SubscribeMessage('createMessageChannel')
	@UseGuards(WebSocketJwtAuthGuard)
	async createMessage(
		@MessageBody() createMessageDto: CreateMessageDto,
		@ConnectedSocket() client: Socket,
	) {
		const channelId: number = createMessageDto['channelId'];
		const userId: number = createMessageDto['userId'];

		try {
			this.checkRequestBodySize(createMessageDto);
			this.updateSocketUserIDpairs(client, userId);  
			if (createMessageDto.text.startsWith("/")) {
					await this.execCommandMessage(createMessageDto.text, userId, channelId);
					return true;
			}
			else {
					const message = await this.messagesService.createMessage(createMessageDto, channelId, userId);
					const channelUsers = await this.messagesService.findWhoDontBlockedMe(userId, channelId);
					channelUsers.forEach((channelUser) => {
						const toSendUserSocket = this.getChannelUserSocket(channelUser);
						if (channelUser.isConnect === true && toSendUserSocket && this.server.sockets.sockets.has(toSendUserSocket.id)) {
							this.server.to(toSendUserSocket.id).emit('message',message)
						}
					})
					return true;
				}
		} 
		catch (serverMessage) {
			//this.server.to(client.id).emit('serverMessage', serverMessage);
			let serverMsg: CreateMessageDto = new CreateMessageDto();
			serverMsg.text = serverMessage;
			serverMsg.name = "SERVER";
			console.log(serverMessage);
			this.server.to(client.id).emit('message', serverMsg);
			return (false);
		}
	}

	@SubscribeMessage('findAllChannels')
	@UseGuards(WebSocketJwtAuthGuard)
	async findAllChannels(
		@MessageBody('userId') userId:number,
		@ConnectedSocket() client: Socket,
	){
		this.updateSocketUserIDpairs(client, userId);
		return await this.messagesService.findChannels(userId);
	}

	@SubscribeMessage('findDirectMessageChannels')
	@UseGuards(WebSocketJwtAuthGuard)
	async findDirectMessageChannels(
		@MessageBody('userId') userId:number,
		@ConnectedSocket() client: Socket,
	){
		this.updateSocketUserIDpairs(client, userId);
		return await this.messagesService.findDirectMessageChannels(userId);
	}

	@SubscribeMessage('findUserInfo')
	@UseGuards(WebSocketJwtAuthGuard)
	async findUserInfo(
		@MessageBody('userName') userName:string,
	){
		this.checkRequestBodySize(userName);
		return await this.messagesService.findUserInfo(-1, userName);
	}

	@SubscribeMessage('findAllInvitations')
	@UseGuards(WebSocketJwtAuthGuard)
	async findAllInvitations(
		@MessageBody('userId') userId:number,
		@ConnectedSocket() client: Socket,
	){
		this.updateSocketUserIDpairs(client, userId);
		return await this.messagesService.findAllInvitations(userId);
	}
  
	@SubscribeMessage('joinInvitation')
	@UseGuards(WebSocketJwtAuthGuard)
	async joinInvitation(
		@MessageBody('userId') userId:number,
		@MessageBody('invitationId') invitationId:number,
		@MessageBody('accepted') accepted:boolean,
		@ConnectedSocket() client: Socket,
	){
		try {
			this.updateSocketUserIDpairs(client, userId);
			const chatInfo = await this.messagesService.joinInvitation(userId, invitationId, accepted);
			if (client.connected)
				 client.emit("updateInvitations", "remove", {id: invitationId});
			if (accepted && chatInfo)
				client.emit(`updateChannels`, `add`, chatInfo)
			return true;
		} catch (serverMessage) {
			//this.server.to(client.id).emit('serverMessage', serverMessage);
			this.server.to(client.id).emit('formFailed', serverMessage);
			false;
		}
	}

	@SubscribeMessage('findAllChannelMessages')
	@UseGuards(WebSocketJwtAuthGuard)
	async findAllChanMsg(
		@MessageBody('userId') userId:number,
		@MessageBody('channelId') channelId: number,
		@ConnectedSocket() client: Socket,
	){
		try {
			this.updateSocketUserIDpairs(client, userId);
			return await this.messagesService.findChannelMessagesForMe(userId, channelId);
		}
		catch (serverMessage) {
			//this.server.to(client.id).emit('serverMessage', serverMessage);
			let serverMsg: CreateMessageDto = new CreateMessageDto();
			serverMsg.text = serverMessage;
			serverMsg.name = "SERVER";
			console.log(serverMessage);
			this.server.to(client.id).emit('message', serverMsg);
			return (serverMessage);
		}
	}


	@SubscribeMessage('createChannel')
	@UseGuards(WebSocketJwtAuthGuard)
	async createChannel(
		@MessageBody('userId') userID:number,
		@MessageBody('chatName') chatName:string,
		@MessageBody('password') password:string,
		@ConnectedSocket() client: Socket,
	){
		try {
			this.checkRequestBodySize(chatName);
			this.updateSocketUserIDpairs(client, userID);
			const channelInfo = await this.messagesService.createChannel(userID, chatName, password);
			this.server.to(client.id).emit('updateChannels', "add", channelInfo);
			return true;
		}
		catch (serverMessage) {
			this.server.to(client.id).emit('formFailed', serverMessage);
			return false;
		}
	}

	@SubscribeMessage('createDM')
	@UseGuards(WebSocketJwtAuthGuard)
	async createDM(
		@MessageBody('firstUser') firstUser:number,
		@MessageBody('secondUser') secondUser:number,
		@ConnectedSocket() client: Socket,
	){
		try {
			this.updateSocketUserIDpairs(client, firstUser);
			const dmInfo = await this.messagesService.createDM(firstUser, secondUser);
			const firstUserSocket = this.getUserSocket(firstUser);
			const secondUserSocket = this.getUserSocket(secondUser);
			if (firstUserSocket && this.server.sockets.sockets.has(firstUserSocket.id)) {
				this.server.to(firstUserSocket.id).emit('updateDM', "add", {
					channelId: dmInfo.channelId,
					otherUserId: secondUser,
					otherUserUsername: dmInfo.secondUserUserName,
				});
			}
			if (secondUserSocket && this.server.sockets.sockets.has(secondUserSocket.id)) {
				this.server.to(secondUserSocket.id).emit('updateDM', "add", {
					channelId: dmInfo.channelId,
					otherUserId: firstUser,
					otherUserUsername: dmInfo.firstUserUserName,
				});
			}
			return dmInfo
		}
		catch (serverMessage) {
			//this.server.to(client.id).emit('serverMessage', serverMessage);
			this.server.to(client.id).emit('formFailed', serverMessage);
			return false;
		}
	}

	@SubscribeMessage('typing')
	@UseGuards(WebSocketJwtAuthGuard)
	async typing(
		@MessageBody('userId') userID:number,
		@MessageBody('isTyping') isTyping: boolean,
		@MessageBody('channelId') channelId: number,
		@ConnectedSocket() client: Socket,
		) {
		try {
			const channelExists = await prisma.channel.findUnique({where: {id: channelId}})
			if (!channelExists)
				return true
			this.updateSocketUserIDpairs(client, userID);
			const userInfo = await this.messagesService.findUserInfo(userID, null);
			if (!userInfo)
				throw `User not found ${userID}`;
			const name = userInfo.username;
			const channelUsers = await this.messagesService.findWhoDontBlockedMe(userID, channelId);
			channelUsers.forEach((channelUser) => {
				const toEmitClientSocket = this.getChannelUserSocket(channelUser);;
				if (channelUser.isConnect === true && toEmitClientSocket && userID != channelUser.userID)
					toEmitClientSocket.emit('typing', {name, isTyping})
			})
			return true;
		}
		catch (serverMessage) {
			//this.server.to(client.id).emit('serverMessage', serverMessage);
			let serverMsg: CreateMessageDto = new CreateMessageDto();
			serverMsg.text = serverMessage;
			serverMsg.name = "SERVER";
			console.log(serverMessage);
			this.server.to(client.id).emit('message', serverMsg);
			return (serverMessage);
		}
	}

	/*commands*/
	async execCommandMessage(message: string, userId: number, channelId: number){
		const messageText = message.trim();
		const commandArgs = message.split(" ");

		if (messageText.startsWith("/") && (commandArgs.length > 0 && commandArgs.length <= 3)) {
			const command = commandArgs[0].substring(1);

			switch (command) {
				case "kick":
					console.log("lets kick");
					if (commandArgs.length < 2 ){
						throw  "Invalid argument.\n to kick => /kick targetName"
					} else {
						await this.punish(command, commandArgs[1], '', userId, channelId);
					}
					break;
				case "mute":
					console.log("lets mute");
					if (commandArgs.length < 3 || !(/^[0-9]+$/.test(commandArgs[2]))){
						throw  "Invalid argument.\n to mute => /mute targetName nbMinutes"
					}
					else {
						await this.punish(command, commandArgs[1], commandArgs[2], userId, channelId);
					}
					break;
				case "ban":
					if (commandArgs.length < 3 || !(/^[0-9]+$/.test(commandArgs[2]))){
						throw  "Invalid argument.\n to ban => /ban targetName nbMinutes"
					}
					else {
						await this.punish(command, commandArgs[1], commandArgs[2], userId, channelId);
					}
					break;
				case "block":
					console.log("lets block");
					if (commandArgs.length < 2){
						throw  "Invalid argument.\n to block => /block targetName"
					}
					else {
						await this.block(commandArgs[1], userId, channelId);
					}
					break;
				case "leave":
					console.log("lets leave");
					if (commandArgs.length !== 1){
						throw  "Invalid argument.\n to leave => /leave "
					}
					else {
						await this.leave(userId, channelId);
					}
					break;
				case "assignAdminRole":
					console.log("lets assignAdminRole");
					if (commandArgs.length < 2){
						throw  "Invalid argument.\n to assignAdminRole => /assignAdminRole targetName"
					}
					else {
						await this.assignAdminRole(commandArgs[1], userId, channelId);
					}
					break;
				case "changeChannelName":
					console.log("lets changeChannelName");
					if (commandArgs.length < 2){
						throw  "Invalid argument.\n to changeChannelName => /changeChannelName newName"
					}
					else {
						await this.changeChannelName(commandArgs[1], userId, channelId);
					}
					break;
				case "changeChannelPass":
					console.log("lets changeChannelPass");
					if (commandArgs.length < 2){
						throw  "Invalid argument.\n to changeChannelPass => /changeChannelPass newPass"
					}
					else {
						await this.changeChannelPass(commandArgs[1], userId, channelId);
					}
					break;
				case "invite":
					if (commandArgs.length !== 2){
						throw  "Invalid argument.\n to invite => /invite username"
					}
					else {
						await this.invite(commandArgs[1], userId, channelId);
					}
					break;
				case "changeChannelStatus":
					if (commandArgs.length < 2){
						throw  "Invalid argument.\n to changeChannelStatus => /changeChannelStatus newStatus"
					}
					else {
						await this.changeChannelStatus(commandArgs[1], userId, channelId);
					}
				default:
					throw  "unknown command."
			}
		}
		else {
			throw  "unknown command."
		}
	}

	async invite(target:string, executorId: number, channelId: number) {
		const channel = await this.messagesService.findChannelById(channelId);
		if (!channel){
			throw  "We experiencing issues. We will get back to you as soon as possible. in invite, channel is null"
		}
		else if ( channel.status == "dm") {
			throw  "You cannot invite someone in a dm channel."
		}
		else if ( channel.status == "private"
					&& await this.messagesService.isSuperUser(channelId, executorId) == false) {
			throw  "you need to be the channel owner to execute this command."
		}
		const	executorChannelProfil = await prisma.channelUser.findFirst({
			where: {
				userID: executorId,
				channelId: channel.id
			}
		})
		if (!executorChannelProfil)
			throw  "We experiencing issues. We will get back to you as soon as possible."
		const	targetInfo = await prisma.user.findFirst({
			where:{
				username: target
			}
		})
		//Variable used to check if the target is already in the channel
		const targetInChannel = await prisma.channelUser.findFirst({
			where:{
				userName: target,
				channelId: channelId
			}
		})
		if (!targetInfo){
			throw  `Cant find ${target} !`;
		} else if (targetInfo.username == executorChannelProfil.userName) {
			throw  "You cannot invite yourself.";
		} else if (targetInChannel) {
			throw `user ${target} is already in the channel.`
		}
		const invitationInfo = await this.messagesService.createInvitaion(executorId, targetInfo.id, "chat", channel.id);
		const targetSocket = this.getUserSocket(targetInfo.id);
		if (targetSocket && targetSocket.connected) {
			targetSocket.emit("updateInvitations", "add", invitationInfo);
		}
		throw  `${target} have been invited !`;
	}

	async changeChannelStatus(newStatus: string, executorId: number, channelId: number) {
		const channel = await this.messagesService.findChannelById(channelId);
		if (!channel){
			throw  "We experiencing issues. We will get back to you as soon as possible. in changeChannelStatus, channel is null"
		}
		else if ( channel.status == "dm") {
			throw  "You cannot execute this command in dm channel."
		}
		else if (await this.messagesService.isOwner(channelId, executorId) == false) {
			throw  "you need to be the channel owner to execute this command."
		}
		else if (newStatus != "public" && newStatus != "private" && newStatus != "protected") {
			throw  "Invalid argument.\n you can only set the channel status to public, private or protected."
		}
		const hashedEmptyPassword = await bcrypt.hash("", saltOrRounds)
		await prisma.channel.update({
			where: {
				id: channel.id
			},
			data: {
				status: newStatus,
				password: hashedEmptyPassword
			}
		})
		if (newStatus == "public"){
			throw  "the channel is now public you no longer need a password to join the channel"
		}
		else if (newStatus == "protected") {
			throw  "the channel is now protected, use '/changeChannelPass newPass' to set your channel pass"
		}
		else if (newStatus == "private")
		{
			throw "the channel is now private, use '/invite username' to invite your friends"
		}
	}

	async changeChannelPass(newPass:string, executorId: number, channelId: number) {
		const channel = await this.messagesService.findChannelById(channelId);
		if (!channel){
			throw  "We experiencing issues. We will get back to you as soon as possible. in changeChannelPass, channel is null"
		}
		else if ( channel.status == "dm") {
			throw  "You cannot execute this command in dm channel."
		}
		else if (await this.messagesService.isOwner(channelId, executorId) == false) {
			throw  "you need to be the channel owner to execute this command."
		}
		else if (newPass.length == 0) {
			throw  "Invalid argument.\n you need to set a password."
		}
		else {
			const newHashedChannelPassword = await bcrypt.hash(newPass, saltOrRounds)
			await prisma.channel.update({
				where: {
					id: channel.id
				},
				data: {
					status: "protected",
					password: newHashedChannelPassword,
				}
			})
		}
	}

	async changeChannelName(newName:string, executorId: number, channelId: number) {
		const channel = await this.messagesService.findChannelById(channelId);
		if (!channel){
			throw  "We experiencing issues. We will get back to you as soon as possible. in changeChannelName,  channel is null"
		}
		else if ( channel.status == "dm") {
			throw  "You cannot execute this command in dm channel."
		}
		else if (await this.messagesService.isOwner(channelId, executorId) == false) {
			throw  "you need to be the channel owner to execute this command."
		}
		else if (newName.length == 0) {
			throw  "Invalid argument.\n you need to set a name."
		}
		const isAlreadyExist = await prisma.channel.findFirst({
			where: {
				ChannelName: newName
			}
		})
		if (isAlreadyExist) {
			throw  "a channel with this name already exists"
		}
		else {
			await prisma.channel.update({
				where: {
					id: channel.id
				},
				data: {
					ChannelName: newName,
				}
			})
		}
	}

	async assignAdminRole(targetUser: string, executorId: number, channelId: number) {
		const channel = await this.messagesService.findChannelById(channelId);
		if (!channel){
			throw  "We experiencing issues. We will get back to you as soon as possible. in assignAdminRole, channel is null"
		}
		else if ( channel.status == "dm") {
			throw  "You cannot execute this command in dm channel."
		}

		else if (await this.messagesService.isOwner(channelId, executorId) == false) {
			throw  "you need to be the channel owner to execute this command."
		}
		else {
			const target = await prisma.channelUser.findFirst({
				where: {
					userName: targetUser,
					channelId: channel.id
				},
			})
			if (!target){
				throw  "You cannot assign admin role to someone who is not in this channel."
			}
			else if (target.userID == executorId) {
				throw  "You cannot assign yourself as admin."
			}
			else if (target.status == "admin") {
				await prisma.channelUser.update ({
					where: {id: target.id},
					data: {status: "user"},
				})
				throw `Server: ${targetUser} role has been downgraded.`
			}
			else {
				await prisma.channelUser.update ({
					where: {id: target.id},
					data: {status: "admin"},
				})
				throw `Server: ${targetUser} role has been upgraded.`
			}
		}
	}

	async block(targetUser: string, executorId: number, channelId: number){
		const channel = await this.messagesService.findChannelById(channelId);
		if (!channel){
			throw  "We experiencing issues. We will get back to you as soon as possible. in block, channel is null"
		}
		else {
			const executor = await prisma.channelUser.findFirst({
				where: {
					userID: executorId,
					channelId: channel.id
				},
			})
			if (!executor){
				throw  "We experiencing issues. We will get back to you as soon as possible. block, executor is null"
			}
			const target = await prisma.channelUser.findFirst({
				where: {
					userName: targetUser,
					channelId: channel.id
				},
			})
			if (target.id == executor.id){
				throw  "You cannot block yourself."
			}
			const	block = await prisma.block.findFirst({
				where: {
					blocked: target.userID,
					blocker: executor.userID,
				}
			})
			if (block) {
				await prisma.block.delete({
					where: {
						id: block.id
					}
				})
				throw `Server: ${targetUser} has been unblocked.`
			}
			const	blocked = await prisma.block.create({
				data: {
					blocker: executor.userID,
					blocked: target.userID,
					// blockedBy: {
					// 	connect: { id: target.userID}
					// },
					// blockedUser: {
					// 	connect: { id: executor.userID}
					// }
				},
			})
			if (blocked) {
				throw `Server: ${targetUser} has been blocked.`
			}
			else {
				throw `Server: An error has occurred, you cannot block this person at this time.`
			}
		}
	}

	async leave(executorId: number, channelId: number){
		const channel = await this.messagesService.findChannelById(channelId);
		if (!channel){
			throw  `We experiencing issues. We will get back to you as soon as possible. leave, channel is null`
		}
		else {
			const target = await prisma.channelUser.findFirst({
				where: {
					userID: executorId,
					channelId: channel.id
				},
			})
			if (target){
				if (target.status == "owner") {
					await this.messagesService.setNewChannelOwner(channelId);
				}
				await this.messagesService.removeChannelUser(channelId, executorId);
				const targetSocket = this.getChannelUserSocket(target)
				if (targetSocket && targetSocket.connected) {
					if (channel.status == "dm") 
						targetSocket.emit('updateDM', "remove", {channelId: channel.id});
					else
						targetSocket.emit('updateChannels', "remove", {id: channel.id, name: channel.ChannelName});
					targetSocket.emit('leaveChannel');
				}
				if (await this.messagesService.nobodyInChannel(channel.id)) {
					await this.messagesService.removeChannel(channel.id);
				}
			}
		}
	}

	async punish(type: string, targetUser: string, duration: string, executorId: number, channelId: number) {
		
		if (type != "mute" && type != "ban" && type != "kick") {
			throw  "You can only punish someone by muting, banning or kicking them."
		}
		const channel = await this.messagesService.findChannelById(channelId);
		if (!channel){
			throw  `We experiencing issues. We will get back to you as soon as possible. in punish, channel is null`
		}
		else if (channel.status == "dm") {
			throw  "You cannot execute this command in dm channel."
		}
		else if (await this.messagesService.isSuperUser(channelId, executorId) === false) {
			throw  `you can't ${type} someone, you are not the channel owner or admin!`
		}
		else {
			const target = await prisma.channelUser.findFirst({
				where: {
					userName: targetUser,
					channelId: channel.id
				},
			})
			if (!target){
				throw  `You cannot ${type} someone who is not in this channel.`
			}
			else if (target.userID == executorId) {
				throw  `You cannot ${type} yourself.`
			}
			else if (await this.messagesService.isOwner(channelId, executorId) == false
				&&	(target.status == "owner" || target.status == "admin")) {
				throw  `You cannot ${type} a SuperUser !`
			}
			const isPunished = await prisma.punishment.findMany({
				where: {
					punishedId: target.userID,
					channelId: channelId,
				}
			})
			const index = isPunished.findIndex((punishment) => punishment.type == type)
			if (index != -1) {
				await prisma.punishment.delete({
					where: {id: isPunished[index].id}
				})
				throw `${targetUser} ${type} punishment has been removed.`
			}
			else {
				if (type !== 'kick') {
					const expirationTimestamp = DateTime.now().plus({ minutes: parseInt(duration) }).toMillis();
					await prisma.punishment.create({
						data: {
							type: type,
							punishedId: target.userID,
							punishmentExpiration: new Date(expirationTimestamp).toISOString(),
							channel: {
								connect: { id: channelId}
							}
						},
					})
				}
				if (target.isConnect && type !== "mute") {
					const targetSocket = this.getChannelUserSocket(target)
					if (targetSocket && targetSocket.connected) {
						targetSocket.emit('disconectChannel');
					}
				}
				if (type !== 'kick')
					throw `Server: ${targetUser} has been ${type} for ${duration} minutes.`
				else
					throw `Server: ${targetUser} has been ${type}.`
			}
		}
	} 
	
	//methods for pong game invites
	async handleDisconnect(disconnectedSocket: Socket) {
		// console.log(`\nHandling disconnection from chat: Going to remove user with socket ${disconnectedSocket.id} from socketUserIDpairs....`)
		const socketUserIdPairIndex = this.socketUserIDpairs.findIndex(element => element.socket === disconnectedSocket)
		if (socketUserIdPairIndex === -1) {
			console.error(`Error: Could not found an socketUserIdPairIndex with the socket ${disconnectedSocket.id} in handle disconnection!`)
			return
		}
		await this.messagesService.updateUserAllChatConnectionStatus(this.socketUserIDpairs[socketUserIdPairIndex].userID, false)
		console.log(`\nCHAT DISCONNECTION: removed pair {userID: ${this.socketUserIDpairs[socketUserIdPairIndex].userID}, socket ${this.socketUserIDpairs[socketUserIdPairIndex].socket.id}}, pairs length before removing: ${this.socketUserIDpairs.length}.`)
		this.socketUserIDpairs.splice(socketUserIdPairIndex, 1)
		console.log(`socketUserIDpairs.length after removal: ${this.socketUserIDpairs.length}, socketUserIDpairs: [${this.socketUserIDpairs.map(pair => `{user:${pair.userID}, socker:${pair.socket.id}}, `)}]`)
	}
	//returns true if the invite was succesfully transmitted
	//returns false otherwise
	transmitPongGameInviteProposal(hostID: number, guestID: number, inviteDebugID: number, inviteRefusalCallback: () => void): boolean {
		// console.log(`Transmitting invite proposal hostID: ${hostID}, guestID: ${guestID}, inviteDebugID: ${inviteDebugID}...`)
		const socketUserIdPairIndex = this.socketUserIDpairs.findIndex(element => element.userID === guestID)
		// console.log(`socket/user pairs: ${JSON.stringify(this.socketUserIDpairs.map(pair => {pair.socket.id, pair.userID}))}`)
		if (socketUserIdPairIndex === -1) {
			console.error(`Error: Could not found an socketUserIdPairIndex with the userID ${guestID} to transmit pong game invite!`)
			return false
		}

		console.log(`\nTRANSMITTING INVITE: {host:${hostID}, guest:${guestID}}`)
		console.log(`AVAILABLE SOCKETS: [${this.socketUserIDpairs.map(pair => `{user:${pair.userID}, socker:${pair.socket.id}}, `)}]`)
		this.socketUserIDpairs[socketUserIdPairIndex].socket.emit('pong-game-invite', hostID, () => inviteRefusalCallback())
		return true
	}
}
