import React from "react";
import SolidFrame from "../SolidFrame/SolidFrame";
import './Pong.scss'
import PongGame from './PongGame'

type PongProps = {
	userDbID: number;
	pongGameGuestIDref: React.MutableRefObject<number | null>
	pongGameHostIDref: React.MutableRefObject<number | null>
	webToken: string,
};

export default function Pong({webToken, userDbID, pongGameGuestIDref, pongGameHostIDref}: PongProps) { 
	return (
	<SolidFrame frameClass="pong-frame"	>
		<SolidFrame frameClass="arena-frame" >
		<PongGame webToken={webToken} userDbID={userDbID} pongGameGuestIDref={pongGameGuestIDref} pongGameHostIDref={pongGameHostIDref}/>
		</SolidFrame>
	</SolidFrame>
	)
}
