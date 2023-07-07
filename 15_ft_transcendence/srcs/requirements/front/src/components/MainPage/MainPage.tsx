import React, { useEffect, useRef } from 'react';
import { BrowserRouter as Router, Route, Routes, useLocation } from 'react-router-dom';
import SolidFrame from '../SolidFrame/SolidFrame';
import SideBar from "../SideBar/SideBar";
import Title from '../Title/Title';
import './MainPage.scss';
import ChatBox from '../ChatBox/ChatBox';
import Pong from '../Pong/Pong';
import { Dispatch, SetStateAction } from 'react'
import axios from 'axios'
import Profil from '../Profil/Profil';

type MainPageProps = {
  ID: number,
  statusLog: Dispatch<SetStateAction<boolean>>,
  refreshWebToken: Dispatch<SetStateAction<string>>,
  webToken: string
}

type ContentPageProps = {
  ID: number,
  refreshWebToken: Dispatch<SetStateAction<string>>,
  webToken: string
}

const Content: React.FC<ContentPageProps> = (control) => {
  const location = useLocation();

  //Properties for ponGameInvite
  const pongGameGuestIDref = useRef<number | null>(null)
  const pongGameHostIDref = useRef<number | null>(null)



  const getTitle = () => {
	switch(location.pathname) {
		case '/Profil':
			return 'Profile';
		case '/Pong':
			return 'Pong';
		case '/Chat':
			return 'Chat';
		default:
			return 'Chat';
    }
  }

  return (
    <SolidFrame frameClass="main-frame">
      <Title frameClass="main-title-frame" txtClass="text-main-title" txt2={getTitle()} />
      <SolidFrame frameClass="content-frame">
        <Routes>
          <Route path="*" element={<Profil ID={control.ID} webToken={control.webToken} refreshWebToken={control.refreshWebToken} inChatBox={false}/>} />
          <Route path="/Profil" element={<Profil ID={control.ID} webToken={control.webToken} refreshWebToken={control.refreshWebToken} inChatBox={false}/>} />
          <Route path="/Pong" element={<Pong webToken={control.webToken} userDbID={control.ID} pongGameGuestIDref={pongGameGuestIDref}  pongGameHostIDref={pongGameHostIDref}/>} />
          <Route path="/Chat" element={<ChatBox userDbID={control.ID} pongGameGuestIDref={pongGameGuestIDref}  pongGameHostIDref={pongGameHostIDref} refreshWebToken={control.refreshWebToken} webToken={control.webToken}/>} />
        </Routes>
      </SolidFrame>
    </SolidFrame>
  );
};

const MainPage: React.FC<MainPageProps> = (control) => {
    useEffect(() => {

      window.addEventListener('beforeunload', setCurrentStatusToOffline, {once : true})

      return () => {
      // setCurrentStatusToOffline()
      // window.removeEventListener('beforeunload', setCurrentStatusToOffline)
        }
    }, []);

    function setCurrentStatusToOffline() {
    const logoutPromise = axios({ url: 'http://localhost:8080/secure/logout', method: 'POST', headers: { Authorization: `Bearer ${ control.webToken }` }, data: { id: control.ID } })
    logoutPromise.then(response => console.log(`Response from logout request: ${JSON.stringify(response, null, 2)}`))
    logoutPromise.catch(error => console.error(`Caught error from logoutPromise: ${JSON.stringify(logoutPromise, null, 2)}`))
    }

  return (
    <Router>
      <SolidFrame frameClass="window-frame"> 
        <SideBar webToken={control.webToken} statusLog={control.statusLog} userID={control.ID} />
        <Content ID={control.ID} webToken={control.webToken} refreshWebToken={control.refreshWebToken}/>
      </SolidFrame>
    </Router>
  )
}

export default MainPage;