import { Controller, Post, Get, Res, Req, UseGuards } from '@nestjs/common'
import { Response, Request } from 'express'
import sendGrid from '../services/sendgrid.service'
import totp from '../services/totp.service'
import { JwtService } from '@nestjs/jwt'
import prisma from '../../prisma/prisma.client'
import { JwtAuthGuard } from '../jwt/jwt.guard'
import axios from 'axios'
import AuthService from 'src/services/auth.service'

@Controller('search')
@UseGuards(JwtAuthGuard)
export class SearchController	{
	constructor(private auth: AuthService)	{}
	@Post('users')	async returnMatchingKnownUsers(@Res() res: Response, @Req() req: Request) {
		try	{
			const users = await prisma.user.findMany({ where: { username: { startsWith: req.body.searched } } })
			res.status(200).json(users)
		}
		catch (err)	{ console.log(err); res.status(404) }
	}
	@Post('info-user')	async returnUserInformation(@Res() res: Response, @Req() req: Request) {
		try	{
			const info = await this.auth.askDataBaseForCreation(req.body.id)
			console.log(info);
			res.status(200).json(info)
		}
		catch (err)	{ console.log(err); res.status(404) }
	}
	@Post('user-match-history')
	async getUserMatchHistory(@Res() res: Response, @Req() req: Request) {
		try {
		const userId = req.body.id;
		const games = await prisma.gameSessionOutcome.findMany({
		  where: {
			OR: [
			  {
				user1Id: userId,
			  },
			  {
				user2Id: userId,
			  },
			],
		  },
		  include: {
			userID1: true,
			userID2: true,
			winner: true,
			loser: true,
		  },
		});
  
		const gameSessionsHistory = games.map((game) => ({ Player1Name: game.userID1.username, Player2Name: game.userID2.username,
		  winnerName: game.winner.username, loserName: game.loser.username }))
		res.status(200).json(gameSessionsHistory)
	  } 
	  catch (err) { console.log(err); res.status(404) }
	}
}