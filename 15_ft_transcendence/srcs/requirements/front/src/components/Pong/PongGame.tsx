import { useEffect, useState, useRef } from 'react';
import { ReactP5Wrapper } from "@p5-wrapper/react";
import io from 'socket.io-client'; // Import the socket.io client
import { Socket } from 'socket.io-client'; // Import the socket.io client

type Vector = any;

type PongGameProps = { 
    webToken: string,
    userDbID: number;
	pongGameGuestIDref: React.MutableRefObject<number | null>
	pongGameHostIDref: React.MutableRefObject<number | null>
}; 

export default function PongGame({webToken, userDbID, pongGameGuestIDref, pongGameHostIDref}: PongGameProps) { 
    //possible states: undefined(didn't try anything), in queue, in game, Connection failed, Connection timeout, VICTORY, DEFEAT
    const [sessionState, setsessionState] = useState<string | undefined>(undefined)
    const socketRef = useRef<Socket | null>(null)
    const [playerIndex, setPlayerIndex] = useState<number | null>(null); // Store the player index, 0 = left, 1 = right
    const parentRef = useRef<HTMLDivElement | null>(null);

    //partilcles variables
    const nbParticlesPerSide = 25
    const particles: Vector[] = []
    let timeSinceStarrtInMillis = 0
    const noiseFrequency = 0.5
    let showParticles: boolean = true
    
    // Connect to the socket server on component mount
    useEffect(() => {
        console.log("PongGame mount")
        if (!socketRef.current) {
            console.log(`Web token: `, webToken)
            socketRef.current = io('http://localhost:9090', {
                query: { token: webToken }
              })
            socketRef.current.on('connect', () => {
                setsessionState('connected')
                console.log('PongGame socket connected to backend gateway.')
                if (pongGameGuestIDref.current !== null) {
                    console.log(`Sending invite-request with hostID=${userDbID}, guestID=${pongGameGuestIDref.current}`)
                    socketRef.current?.emit('invite-request', {hostID: userDbID, guestID: pongGameGuestIDref.current})
                }
                else if (pongGameHostIDref.current !== null) {
                    console.log(`Emiting join-request with hostID=${pongGameHostIDref.current}, guestID=${userDbID}.`) 
                    socketRef.current?.emit('join-request', {hostID: pongGameHostIDref.current, guestID: userDbID}) 
                }
                else {
                    console.log(`Emitin enter-queue request.`)
                    socketRef.current?.emit('enter-queue', userDbID)
                }
            });
            socketRef.current.on('in-queue', () => setsessionState('in-queue'));
            socketRef.current.on('start-game', (playerIndex) => {
                setsessionState('in-game')
                setPlayerIndex(playerIndex)
            });
            socketRef.current.on('connect_error', () => setsessionState('connection-failed'));
            socketRef.current.on('connect_timeout', () => setsessionState('connection-timeout'));
            socketRef.current.on('waiting-for-guest-answer', () => setsessionState('waiting-for-guest-answer'));
            console.log("Created new socketRef.current")
        }
        return () => {
            // console.log("closing connection")
            console.log("PongGame unmount, disconnecting socket and setting 'pongGameGuestIDref.current' to null.")
            socketRef.current?.disconnect()
            pongGameGuestIDref.current = null
            pongGameHostIDref.current = null
        }
    }, []);

    const sketch = (p5: any) => {
        const playerWidthRatio = 0.0375; // proportion of canvas width
        const playerOffsetRatio = 0.0125; // proportion of canvas width
        const playerHeightRatio = 0.166666; // proportion of canvas height
        const ballRadiusRatio = 0.025; // proportion of canvas width
        const timeForPlayerToCrossCanvas = 0.6
        function getSideLength() {
            if (parentRef.current !== null)
                return Math.min(parentRef.current.offsetHeight, parentRef.current.offsetWidth)
            console.warn("Warning: parentRef.current is null!")
            return 500
        }
        function getPlayerWidth() {
            return playerWidthRatio * getSideLength();
        }
        function getPlayerOffset() {
            return playerOffsetRatio * getSideLength();
        }
        function getPlayerHeight() {
            return playerHeightRatio * getSideLength();
        }
        function getBallRadius() {
            return ballRadiusRatio * getSideLength();
        }


        let playerLeft: Player;
        let playerRight: Player;
        let ball: Ball;

        class Player{
            posRelativeToCanvas: Vector;
            points: number = 0
            constructor(x: number)
            {
                this.posRelativeToCanvas = p5.createVector(x, 0.5)
                this.points = 0
            }
            draw(isLocal: boolean)
            {
                p5.rectMode(p5.CENTER)
                p5.fill(isLocal ? 'white' : 'black')
                p5.stroke('white')
                p5.rect(this.posRelativeToCanvas.x * getSideLength(), this.posRelativeToCanvas.y * getSideLength(), getPlayerWidth(), getPlayerHeight())
                p5.rectMode(p5.CORNER)
            }
            move(upKey: number, downKey: number)
            {
                //get the direction
                let direction = 0
                if (p5.keyIsDown(upKey))
                    direction = -1
                if (p5.keyIsDown(downKey))
                    direction = 1
                //move
                this.posRelativeToCanvas.y += direction * timeForPlayerToCrossCanvas * (p5.deltaTime / 1000)
                //clamp the position
                this.posRelativeToCanvas.y = Math.max(this.posRelativeToCanvas.y, playerHeightRatio / 2)
                this.posRelativeToCanvas.y = Math.min(this.posRelativeToCanvas.y, 1 - playerHeightRatio / 2)
                socketRef.current?.emit('player-move', { y: this.posRelativeToCanvas.y })
            }
        }

        class Ball{
            posRelativeToCanvas: Vector;
            constructor() {
                this.posRelativeToCanvas = p5.createVector(0.5, 0.5)
            }
            draw() {
                p5.circle(this.posRelativeToCanvas.x * getSideLength(), this.posRelativeToCanvas.y * getSideLength(), getBallRadius() * 2)
            }
        }
        

        p5.setup = () => {
            if (socketRef.current) { 
                p5.createCanvas(getSideLength(), getSideLength());
                setupParticles()

                playerLeft = new Player(playerOffsetRatio);
                playerRight = new Player(1 - playerOffsetRatio);
                ball = new Ball();

                socketRef.current.on('update-game', (gameState) => {
                    // console.log(gameState) 
                    if (playerIndex !== 0)//if we are not the left player we want to update the position of the remote left player
                        playerLeft.posRelativeToCanvas.y = gameState.players[0].y
                    if (playerIndex !== 1)//same for the right player
                        playerRight.posRelativeToCanvas.y = gameState.players[1].y
                    ball.posRelativeToCanvas.x = gameState.ball.posRelativeToCanvas.x
                    ball.posRelativeToCanvas.y = gameState.ball.posRelativeToCanvas.y
                    playerLeft.points = gameState.players[0].points
                    playerRight.points = gameState.players[1].points
                });
                socketRef.current.on('game-over', (outcome: any) => {
                    console.log("received 'game-over' event, won: ", outcome.won, ", reason: ", outcome.reason)
                    if (outcome.won)
                        setsessionState("VICTORY")
                    else
                        setsessionState("DEFEAT")
                })
            }
        };

        p5.windowResized = () => {
            p5.resizeCanvas(getSideLength(), getSideLength());
        };



        function setupParticles() {
            for (let x = 0; x < nbParticlesPerSide; x++){
                for (let y = 0; y < nbParticlesPerSide; y++){
                let X = x / nbParticlesPerSide
                let Y = y / nbParticlesPerSide
                particles.push(p5.createVector(X, Y))
                }
            }
        }
        
        function drawParticles() {
            timeSinceStarrtInMillis += p5.deltaTime
            for (let i = 0; i < particles.length; i++){
                let offset = sampleoffset(particles[i])
                offset.mult(p5.noise(i) * 0.00075 )
                particles[i].add(offset)
                //maintain the particle in the frame
                particles[i].x = particles[i].x % 1
                if (particles[i].x < 0 || particles[i].x > 1)
                    particles[i].x = 1 - particles[i].x
                particles[i].y = particles[i].y % 1
                if (particles[i].y < 0 || particles[i].y > 1)
                    particles[i].y = 1 - particles[i].y
                //Draw the particle
                if (showParticles)
                    p5.circle(particles[i].x * getSideLength(), particles[i].y * getSideLength(), 0.005 * getSideLength())
            }
        }
        
        function sampleoffset(p: Vector){
            let val = p5.noise(p.x * noiseFrequency, p.y * noiseFrequency, timeSinceStarrtInMillis * 0.0005 + p5.noise(timeSinceStarrtInMillis * 0.0001) * 0.6) * 360 * 2
            return p5.constructor.Vector.fromAngle(p5.radians(val), 1).mult(p5.deltaTime )
        }

        function drawGame() {
            playerLeft.draw(playerIndex === 0);
            playerRight.draw(playerIndex === 1);
            ball.draw();
 
            if (playerIndex === 0)
                playerLeft.move(p5.UP_ARROW, p5.DOWN_ARROW);
            else 
                playerRight.move(p5.UP_ARROW, p5.DOWN_ARROW);

            p5.textSize(getSideLength() / 10);
            p5.fill('white')
            p5.text(playerLeft.points.toString(), getSideLength() / 5, getSideLength() / 6)
            p5.text(playerRight.points.toString(), getSideLength() - getSideLength() / 5, getSideLength() / 6)
            
        }
        function drawText() {
            p5.textAlign(p5.CENTER)
            p5.textSize(20);
            if (typeof sessionState !== undefined && sessionState)
                p5.textSize(0.9 * getSideLength() / sessionState.length);
            if (sessionState === "VICTORY") 
                p5.fill('yellow')
            else 
                p5.fill('gray')
            p5.text(sessionState, getSideLength() / 10, getSideLength() / 10, getSideLength() * 0.9 , getSideLength() * 0.9)
        }
        p5.draw = () => {
            p5.clear()
            p5.background(0);
            drawParticles()
            if (sessionState === 'in-game')
                drawGame()
            else
                drawText()
        };
        p5.keyPressed = () => {
            console.log(`Called, p5.keyCode: ${p5.keyCode}, p5.BACKSPACE: ${p5.BACKSPACE}.`)
            if (p5.keyCode === 32)
                showParticles = !showParticles
        }
          
    };
 
    return (
        <div ref={parentRef} className="solid-frame parentDiv">
            <ReactP5Wrapper sketch={sketch} />
        </div>
    );
}
