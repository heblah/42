import { Injectable } from '@nestjs/common'
import axios from 'axios'
import * as qs from 'qs'
import prisma from '../../prisma/prisma.client'
import { User } from '@prisma/client'

@Injectable()
export default class AuthService {
    async	exchangeCodeForToken(access_code: string)	{
      try	{
        const qs = require('qs')
        let url = process.env.CODE_FOR_TOKEN
        const requestBody = {
          grant_type: 'authorization_code',
          client_id: process.env.CLIENT_ID,
          client_secret: process.env.CLIENT_SECRET,
          code: access_code,
          redirect_uri: process.env.URL_API_CONTROLLER
        }
        let res = await axios.post(url, qs.stringify(requestBody))
        const accessToken = res.data.access_token
        return accessToken
      }
      catch (err)	{ console.log(err) }
    }
    async	askUserID(accessToken: string)	{
      const url = process.env.TOKEN_INFO_URL
      const res = await axios.get(url, { headers: { 'Authorization' : `Bearer ${accessToken}`} })
      const resourceOwnerId = res.data.resource_owner_id
      return resourceOwnerId
    }
    async	fetchUserData42(accessToken: string, resourceOwnerId: string)	{
      const url = process.env.USER_INFO_42URL + "/" + resourceOwnerId
      const res = await axios.get(url, { headers: { 'Authorization' : `Bearer ${accessToken}` } })
      return res.data
    }
    async	askDataBaseForCreation(userId: number) : Promise<User | null>	{
      const	user: User = await prisma.user.findUnique({ where: { id: userId } })
      return user
    }
    async updateConnectedStatus(userID: number) { 
        try {
          if (userID !== undefined) {
            await prisma.user.update({ where: { id: userID }, data: { currentStatus: "online" } })
            console.log(`USER ${userID} => ONLINE`)
          }
        } catch (err) { console.log(err) } 
    }
}
