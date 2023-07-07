import React from "react"
import { BrowserRouter as Router, Route, Routes } from 'react-router-dom';
import { Dispatch, SetStateAction } from 'react'
import SolidFrame from "../SolidFrame/SolidFrame"
import GetAccess from '../GetAccess/GetAccess'
import Login from '../Login/Login'
import './HomePage.scss'

type HomePageProps = {
	authChecked: boolean,
	log: Dispatch<SetStateAction<boolean>>,
	user: Dispatch<SetStateAction<number>>,
	controlJwtToken: Dispatch<SetStateAction<string>>,
	children?: React.ReactNode
}

const HomePage: React.FC<HomePageProps> = ({ authChecked, log, user, controlJwtToken }) => {

	return (
		<>
			{!authChecked && (
				<Router>
					<SolidFrame frameClass="login-frame" >
						<SolidFrame frameClass="simple-pong-frame" txtClass="text-logo" txt2="Simple Pong" />
						<SolidFrame frameClass="bottom-frame">
							<Routes>
								<Route path="*" element={<GetAccess />} />
								<Route path="/Login" element={<Login controlJwtToken={controlJwtToken} log={log} ID={user} />} />
							</Routes>
						</SolidFrame>
					</SolidFrame>
				</Router>
			)}
		</>
	);
};

export default HomePage;

