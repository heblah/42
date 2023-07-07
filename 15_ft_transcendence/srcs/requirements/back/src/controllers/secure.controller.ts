import { Controller, Post, Get, Res, Req, UseGuards } from '@nestjs/common'
import { Response, Request } from 'express'
import sendGrid from '../services/sendgrid.service'
import totp from '../services/totp.service'
import { JwtService } from '@nestjs/jwt'
import prisma from '../../prisma/prisma.client'
import AuthService from '../services/auth.service'
import { JwtAuthGuard } from '../jwt/jwt.guard'

@Controller('secure')
@UseGuards(JwtAuthGuard)
export class ConnectController {
	constructor(private readonly jwtService: JwtService, private auth: AuthService) {}
	@Post('user')	async userExists(@Res() res: Response, @Req() req: Request) {
		try {
			const user = await prisma.user.findFirst( { where: { id: req.body.info.id }} )
			if (user) {
				res.status(200).json(user) 
				const updateUserSatus = await prisma.user.update({ where: {id: req.body.info.id}, data: { currentStatus: 'online'}})
				console.log(`USER ${req.body.info.id} => ONLINE`)
			} else { res.status(404).json(req.body) }
		}
		catch (err)	{ console.log(err); res.status(404) }
	}
	@Post('add')	async addUserInDataBase(@Res() res: Response, @Req() req: Request) {
		try	{
			const username = await prisma.user.findFirst({ where: { username: req.body.username } })
			if (username) { res.status(409).json(null); return; }
			const user = await prisma.user.create({
				data: { id: req.body.apiData.id, username: req.body.username, email: req.body.apiData.email,
					login: req.body.apiData.login, lastName: req.body.apiData.last_name, firstName: req.body.apiData.first_name,
					imageLink: req.body.apiData.image.link, doubleAuth: req.body.doubleAuth, currentStatus: "online"
				}
			}); res.status(201).json(user)
			console.log(`USER ${req.body.id} => ONLINE`)
		}
		catch (err)	{ console.log(err); res.status(404) }
	}
	@Post('logout')
	async delogUserConnectedFalse(@Res() res: Response, @Req() req: Request) {
		try	{
			console.log(`USER ${req.body.id} => OFFLINE`)
			const updatedUser = await prisma.user.update({ where: { id: req.body.id }, data: { currentStatus: "offLine" }})
			res.status(204).json(updatedUser)
		}
		catch (err)	{ console.log(err); res.status(401) }
	}
	@Post('update2FA')	async update2FAStatus(@Res() res: Response, @Req() req: Request) {
		try {
			let updater
			if (req.body.status2FA)	{ updater = 'on' }
			else { updater = '' }
			const updatedUser = await prisma.user.update({ where: { id: req.body.ID }, data: { doubleAuth: updater }})
			res.status(204).json(updatedUser)
		}
		catch (err) { console.log(err); res.status(404) }
	}
	@Post('secure')	async	makeDoubleAuth(@Res() res: Response, @Req() req: Request)	{
		try	{
			await prisma.token2FA.deleteMany({ where: { id: req.body.info.id } })
			const secureTkn = totp.generate()
			sendGrid.send({
				to: req.body.info.email,
				from: process.env.SENDER_SEND_GRID_MAIL,
				subject: '2FA verification from transcendance.team',
				text: `Hello ${req.body.info.first_name}, your authentification token is ${secureTkn} with love.`
			})
			await prisma.token2FA.create({ data: { id: req.body.info.id, value: secureTkn } })
			res.status(200).json()
		}
		catch (err) { console.log(err); res.status(404) }
	}
	@Post('token')	async verifyDoubleAuthToken(@Res() res: Response, @Req() req: Request)	{
		try	{
			const	verif = await prisma.token2FA.findUnique({ where: { id: req.body.id } })
			if (verif && verif.value === req.body.token)	{
				await prisma.token2FA.delete({ where: { id: req.body.id } })
				this.auth.updateConnectedStatus(req.body.id)
				res.status(201).json('approved')
			}
			else { res.status(401) }
		}
		catch (err) { console.log(err); res.status(404) }
	}
}
