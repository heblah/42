import React, { useState, useContext, useEffect } from 'react';
import './App.scss';
import MainPage from './components/MainPage/MainPage'
import HomePage from './components/HomePage/HomePage';
import './components/ChatBox/ChatBox.scss'
//import { set } from 'lodash'
import axios from 'axios'


function App() { 
	const [authChecked, setAuthChecked] = useState(false)
	const [userID, setUserID] = useState(-1) 
	const [sessionToken, setSessionToken] = useState('')

	function extractInfoFromToken(token: string)	{
			const tokenParts = token.split('.');
			const payload = JSON.parse(atob(tokenParts[1]));
			return payload
	}

	useEffect((() => {
		const token = localStorage.getItem('token')
		if (token && userID === -1) {
			const info = extractInfoFromToken(token);
			const userID = info.id			
			setUserID(userID)
			setSessionToken(token)
		}
	}), [sessionToken])

	useEffect(() => {
		async function askDatabaseForUserExist(){
			const token = localStorage.getItem('token')
			if (token)	{
				const info = extractInfoFromToken(token)
				let res = await axios({
					url: 'http://localhost:8080/secure/user',
					method: 'POST',
					headers: { Authorization: `Bearer ${token}` }, 
					data: { info }
				})
				if (res.status === 200) {
					setAuthChecked(true);
				}
			}
		}
		askDatabaseForUserExist();
	}, [authChecked])

	return (
		<div className="App">
			{ authChecked ? (
					<MainPage
						statusLog={setAuthChecked}
						ID={userID}
						refreshWebToken={setSessionToken}
						webToken={sessionToken}
					/>
				) : (
					<HomePage
						authChecked={authChecked}
						log={setAuthChecked}
						user={setUserID}
						controlJwtToken={setSessionToken}
					/>
				)
			}
		</div>
	  );
	  
	  
}

export default App
