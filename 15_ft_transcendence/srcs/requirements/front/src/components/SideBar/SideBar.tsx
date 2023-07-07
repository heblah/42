import React from "react";
import SolidFrame from '../SolidFrame/SolidFrame'
import './SideBar.scss'
import { Dispatch, SetStateAction } from 'react'
import axios from 'axios'

type SideBarProps = { webToken: string, statusLog: Dispatch<SetStateAction<boolean>>, userID: number }
const SideBar: React.FC<SideBarProps> = (control) => {

	async function	sessionDestroyTrigger()	{
		control.statusLog(false)
		let res = await axios({ url: 'http://localhost:8080/secure/logout', method: 'POST', headers: { Authorization: `Bearer ${control.webToken}` }, data: { id: control.userID } })
		if (res.status === 204) {
			console.log("20444444");	
			localStorage.removeItem('token'); 
			window.location.href = '/'; 
		}
	}

	return (
		<SolidFrame frameClass="side-frame" >
			<SolidFrame frameClass="logo-frame" txtClass="text-logo" txt1="Simple" txt2="Pong" />
			<SolidFrame frameClass="menu-frame" txtClass="text-side" txt2="Profil" link="/Profil" />
			<SolidFrame frameClass="menu-frame" txtClass="text-side" txt2="Pong Game" link="/Pong" />
			<SolidFrame frameClass="menu-frame" txtClass="text-side" txt2="Chat" link="/Chat" />
			<SolidFrame frameClass="menu-frame" txtClass="text-side" txt2="Logout" onClick={sessionDestroyTrigger}/>
		</SolidFrame>
	)
}

export default SideBar
