import { Injectable, CanActivate, ExecutionContext } from '@nestjs/common'
import { WsException } from '@nestjs/websockets'
import { JwtService } from '@nestjs/jwt'
import { Observable } from 'rxjs'

@Injectable()
export class JwtAuthGuard implements CanActivate {

  
  constructor(private readonly jwtService: JwtService) {}

  canActivate(context: ExecutionContext): boolean | Promise<boolean> | Observable<boolean> {
    const request = context.switchToHttp().getRequest()
    return this.validateRequest(request)
  }

  async validateRequest(request: any): Promise<boolean> {
    const token = this.extractTokenFromRequest(request)   
    try {
      const payload = await this.jwtService.verifyAsync(token)
      request.user = payload
      return true
    }
    catch (err) {    
      console.log(err)
      return false
    }
  }

  extractTokenFromRequest(request: any): string {
    const authHeader = request.headers.authorization
    if (authHeader && authHeader.startsWith('Bearer '))
      return authHeader.substring(7)
    return null
  }
}

@Injectable()
export class WebSocketJwtAuthGuard implements CanActivate {
  constructor(private readonly jwtService: JwtService) {}

  canActivate(context: ExecutionContext): boolean | Promise<boolean> {
    const client = context.switchToWs().getClient()
    const token = client.handshake.query.token
    if (!token) {
      console.log(`WebSocketJwtAuthothification denied, token is null.`)
      throw new WsException('Unauthorized');
    }
      return this.validateToken(token)
  }
  
  extractTokenFromClient(client: any): string {
    return client.handshake.query.token || null
  }

  async validateToken(token: string): Promise<boolean> {
    try {
      const payload = await this.jwtService.verifyAsync(token)
      return true
    } 
    catch (err) {
      console.error(`Cauhght an error while vrifying authorization(or authentification?) token, returning null.`)
      console.error(`Error: `, err)
      return false
    }
  }
}
