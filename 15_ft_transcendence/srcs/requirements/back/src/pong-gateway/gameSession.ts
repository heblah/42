import { Socket } from 'socket.io';
import { clamp, Vector2D } from './simpleMath';
import prisma from '../../prisma/prisma.client';
import { UseGuards } from '@nestjs/common'
import { WebSocketJwtAuthGuard } from '../jwt/jwt.guard'

//const
const interval: number = 1000 / 30
const playerWidthRatio = 0.0375; // proportion of canvas width 
const playerOffsetRatio = 0.0125; // proportion of canvas width
const playerHeightRatio = 0.166666; // proportion of canvas height
const ballRadiusRatio = 0.025; // proportion of canvas width
const deltaTime: number = 1 / 30
const timeForBallToCrossCanvas = 0.5
const BallXspeed = deltaTime * timeForBallToCrossCanvas

// Define the GameState and Player type
type Player = {
  y: number
  points: number
};

type GameState = {
  nbFramesDebug: number
  ball: Ball
  players: [Player, Player];
};


class Ball{
  posRelativeToCanvas: Vector2D = new Vector2D(0.5, 0.5)
  horizontalMovement: number = 1
  verticalMovement: number = 0
  checkOverlap(playerPosRelativeToCanvas: Vector2D): boolean {
      // Find the closest point to the circle within the rectangle
      let closestX = clamp(this.posRelativeToCanvas.x - playerPosRelativeToCanvas.x, -playerWidthRatio / 2, playerWidthRatio / 2) + playerPosRelativeToCanvas.x
      let closestY = clamp(this.posRelativeToCanvas.y - playerPosRelativeToCanvas.y, -playerHeightRatio / 2, playerHeightRatio / 2) + playerPosRelativeToCanvas.y
      // Calculate the distance between the circle's center and the closest point
      var distanceX = this.posRelativeToCanvas.x - closestX;
      var distanceY = this.posRelativeToCanvas.y - closestY;
      var distanceSquared = (distanceX * distanceX) + (distanceY * distanceY);
      // Check if the distance is less than the circle's radius squared
      return distanceSquared <= (ballRadiusRatio * ballRadiusRatio);
  }
  bounceOffPlayer(playerPosRelativeToCanvas: Vector2D) { 
      let dir = new Vector2D(this.posRelativeToCanvas.x - playerPosRelativeToCanvas.x, this.posRelativeToCanvas.y - playerPosRelativeToCanvas.y);
      dir.normalize();
      this.horizontalMovement *= -1;
      this.verticalMovement = dir.y * 0.15;
  }            
  givepointToPlayer(player: Player){
    this.posRelativeToCanvas = new Vector2D(0.5, 0.5)
    player.points++
  }
  move(gameState: GameState) {
    this.posRelativeToCanvas.x += this.horizontalMovement * BallXspeed
    this.posRelativeToCanvas.y += this.verticalMovement * deltaTime
    //bounce off players
    let leftPlayerPos: Vector2D = new Vector2D(playerOffsetRatio, gameState.players[0].y)
    if (this.checkOverlap(leftPlayerPos) && this.horizontalMovement === -1)
      this.bounceOffPlayer(leftPlayerPos)
    let rightPlayerPos: Vector2D = new Vector2D(1 - ballRadiusRatio, gameState.players[1].y)
    if (this.checkOverlap(rightPlayerPos) && this.horizontalMovement === 1)
      this.bounceOffPlayer(rightPlayerPos)
    //bounce off walls
    if (this.posRelativeToCanvas.y > 1 - ballRadiusRatio || this.posRelativeToCanvas.y < ballRadiusRatio)
      this.verticalMovement *= -1
    if (this.posRelativeToCanvas.x > 1 - ballRadiusRatio)
      this.givepointToPlayer(gameState.players[0])
    if (this.posRelativeToCanvas.x < ballRadiusRatio)
      this.givepointToPlayer(gameState.players[1]) 
  }
}

export class GameSession {

  // Initial game state
  gameState: GameState = {
    nbFramesDebug: 0,
    ball: new Ball(),
    players: [
      { y: 0.5, points: 0 }, // Player 1
      { y: 0.5, points: 0 }, // Player 2
    ],
  };

  // clientSocket connections list
  clientSockets: Socket[] = [];
  userIDs: number[] = []

  //Is used by the pongGateway to check if it should be removed
  gameIsOver: boolean = false
  debugId: number = -1

  constructor(clientSocket1: Socket, clientSocket2: Socket, userID1: number, userID2: number, debugId: number) {
    this.debugId = debugId
    this.clientSockets = [clientSocket1, clientSocket2]
    this.userIDs = [userID1, userID2]
    this.clientSockets.forEach((cs, index) => cs.emit('start-game', index))
    this.clientSockets.forEach(cs => cs.emit('update-game', this.gameState));
    this.clientSockets.forEach(cs => cs.on('disconnect', () => this.handleDisconnect(cs)))
    this.clientSockets.forEach(cs => cs.on('player-move', (payload) => this.handlePlayerMove(cs, payload)))
    //update users status in db 
    prisma.user.update({ where: { id: userID1 }, data: { currentStatus: "inGame" }}).then(() => console.log(``))
    prisma.user.update({ where: { id: userID2 }, data: { currentStatus: "inGame" }}).then(() => console.log(``))
    //debug
    console.log(`GAME SESSION ${debugId}:`)
    console.log(`\t\t PLAYER1: socket: ${clientSocket1}, id: ${userID1}`)
    console.log(`\t\t PLAYER2: socket: ${clientSocket2}, id: ${userID2}`)
  }
 
  handleDisconnect(disconnectedClientSocket: Socket) {
    if (this.gameIsOver === false) {
      //find the index of the player that left 
      let winnerIndex = this.clientSockets.findIndex(cs => cs !== disconnectedClientSocket)
      let reason = `Game ${this.debugId} is over: player ${1 - winnerIndex} disconnected.`
      this.handleGameOver(winnerIndex, reason)
      prisma.user.update({ where: { id: this.userIDs[winnerIndex] }, data: { currentStatus: "online" }}).then(() => console.log(``))
      prisma.user.update({ where: { id: this.userIDs[1 - winnerIndex] }, data: { currentStatus: "online" }}).then(() => console.log(``))
    } 
  }
  update()  {
    this.gameState.ball.move(this.gameState)
    let WinnerIndex = this.gameState.players.findIndex(player => player.points >= 3)
    if (WinnerIndex !== -1) {
      this.handleGameOver(WinnerIndex, `Game ${this.debugId} is over: player ${WinnerIndex} has ${this.gameState.players[WinnerIndex].points} points.`)
      prisma.user.update({ where: { id: this.userIDs[0] }, data: { currentStatus: "online" }}).then(() => console.log(``))
      prisma.user.update({ where: { id: this.userIDs[1] }, data: { currentStatus: "online" }}).then(() => console.log(``))
    }
    else
      this.clientSockets.forEach(cs => cs.emit('update-game', this.gameState));
    this.gameState.nbFramesDebug++
  }

  handleGameOver(winnerIndex: number, reason: string = `Game ${this.debugId} is over, winer index: ${winnerIndex}.`) {
    console.log(`\n` + reason)
    this.clientSockets[winnerIndex].emit('game-over', {won: true, reason: reason})
    this.clientSockets[1 - winnerIndex].emit('game-over', {won: false, reason: reason})
    //Set gameIsOver to true before disconnecting the clients because handleDisconnect(which rellis on gameIsOver) will get called/
    this.gameIsOver = true
    this.clientSockets.forEach(cs => cs.disconnect(true))
    let recoredData = {
      data: {
        userID1: { connect: { id: this.userIDs[0] } },
        userID2: { connect: { id: this.userIDs[1] } },
        winner: { connect: { id: this.userIDs[winnerIndex] } },
        loser: { connect: { id: this.userIDs[1 - winnerIndex] } }
      }
    };
    let promise = prisma.gameSessionOutcome.create(recoredData)
    promise.catch(err => console.error(`Caught game session outcome prisma record creation error: ${err}`))
    // promise.then(() => console.log('Game session outcome prisma record created.'))
  }

  // Method to handle player move events
  @UseGuards(WebSocketJwtAuthGuard)
  handlePlayerMove(clientSocket: Socket, payload: { y: number }) {
    //find playerIndex with clientSocket (this way, a player can only affect its paddle)
    let playerIndex: number = this.clientSockets.findIndex(cs => cs === clientSocket)
    // Update the player's position based on the payload
    // console.log(`Setting position of player ${playerIndex} to ${payload.y}`)
    this.gameState.players[playerIndex].y = payload.y;
  }
}
