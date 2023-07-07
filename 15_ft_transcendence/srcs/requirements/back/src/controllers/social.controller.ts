import { Controller, Post, Get, Res, Req, UseGuards } from '@nestjs/common'
import { Response, Request } from 'express'
import prisma from '../../prisma/prisma.client'
import { JwtAuthGuard } from '../jwt/jwt.guard'
import AuthService from 'src/services/auth.service'

@Controller('friend')
@UseGuards(JwtAuthGuard)
export class SocialInteractController	{
constructor(private auth: AuthService) {}
	@Post('add')	async addFriendOfUser(@Res() res: Response, @Req() req: Request)	{
		try	{
			const	user = await prisma.user.findUnique({where: { id: req.body.ID }})
			const	newFriend = await prisma.user.findUnique({where: { id: req.body.newID }})
			const	alreadyFriend = user.friends.find(friend => friend === newFriend.username)
			if (alreadyFriend) { res.status(304); return }
			await prisma.user.update({ where: { id: user.id }, data: { friends: { push: newFriend.username } }})
			await prisma.user.update({ where: { id: newFriend.id }, data: { friends: { push: user.username } }})
			res.status(201)
		}
		catch (err)	{ console.log(err); res.status(404) }
	}
	@Post('remove')	async removeFriendOfUser(@Res() res: Response, @Req() req: Request)	{
		try	{
			const	user = await prisma.user.findUnique({where: { id: req.body.ID }})
			const	removeFriend = await prisma.user.findUnique({where: { id: req.body.newID }})
			const	friendExists = user.friends.find(friend => friend === removeFriend.username)
			if (!friendExists)	{ res.status(204); return }
			const updatedUserFriends = user.friends.filter(friend => friend !== removeFriend.username)
			await prisma.user.update({ where: { id: user.id }, data: { friends: updatedUserFriends } })
			const updatedRemovedUserFriends = removeFriend.friends.filter(friend => friend !== user.username)
			await prisma.user.update({ where: { id: removeFriend.id }, data: { friends: updatedRemovedUserFriends } })
			res.status(202)
		}
		catch (err)	{ console.log(err); res.status(404) }
	}
	@Post('list')
	async returnListofUserFriends(@Res() res: Response, @Req() req: Request) {
	  try {
		const user = await this.auth.askDataBaseForCreation(req.body.id);
		const arr = await Promise.all(
		  user.friends.map(async (friend) => {
			const objFriend = await prisma.user.findFirst({ where: { username: friend } });
			const obj = { friend, connected: objFriend.currentStatus, imageLink: objFriend.imageLink };
			return obj;
		  })
		);
		res.status(200).json(arr);
	  } 
	  catch (err) { console.log(err); res.status(404) }
	}	
}
