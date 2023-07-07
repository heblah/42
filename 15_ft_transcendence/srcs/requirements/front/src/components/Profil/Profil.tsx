import SolidFrame from "../SolidFrame/SolidFrame"
import SearchBar from "../SearchBar/SearchBar"
import SearchList from "../SearchList/SearchList"
import ProfileUserButton from "../StyledButtons/StyledButtons"
import Title from "../Title/Title";
import React, { ChangeEvent, useState, useEffect, useContext } from 'react'
import axios from 'axios'
import './Profil.scss'
import { debounce } from 'lodash'
import { Dispatch, SetStateAction } from 'react'
import MatchHistory from "../MatchHistory/MatchHistory";

interface UserInfo {
	id?: number,
	first_name?: string,
	last_name?: string,
	imageLink?: string,
	username?: string,
	doubleAuth?: string,
	currentStatus?: string
}

type ProfilProps = {
	ID: number,
	refreshWebToken: Dispatch<SetStateAction<string>>,
	webToken: string,
	username?: string,
	stats?: string,
	matchHistory?: string,
	children?: React.ReactNode,
	inChatBox: boolean
}

interface GameSession {
	Player1Name: string;
	Player2Name: string;
	winnerName: string;
	loserName: string;
  }  

const Profil: React.FC<ProfilProps> = ({ ID, webToken, refreshWebToken, stats = "Some user stats", matchHistory = "Some match history data", inChatBox = false, children }) => {
	const [newID, setNewID] = useState(-1)
	const [searchTerm, setSearchTerm] = useState('')
	const [uploadedFile, setUploadedFile] = useState<File>()
	// const [friendList, setFriendList] = useState<string[]>([])
	const [gameSessionOutcome, setGameSessionOutcome] = useState<{ Player1Name: string; Player2Name: string; loserName: string, winnerName: string }[]>([]);
	const [wins, setWins] = useState(0);
	const [loose, setLoose] = useState(0);
	const [friendList, setFriendList] = useState<{ friend: string; connected: string; imageLink: string }[]>([])
	const [triggerAvatarChange, setTriggerAvatarChange] = useState(0)
	const [userInfo, setUserInfo] = useState<UserInfo>({ id: -1, first_name: '', last_name: '', imageLink: '', username: '', currentStatus: "" })
		
	async function fetchFriendList() {
		try {
			const res = await axios({ url: 'http://localhost:8080/friend/list', method: 'POST', headers: { Authorization: `Bearer ${webToken}` }, data: { id: ID } })
			setFriendList(res.data)
		}
		catch (err) { console.log(err) }
	}
	useEffect(() => { fetchFriendList(); }, [])

	useEffect(() => {
		const fetchUserInformationDisplay = async () => {
			try {
				if (newID === -1)	{
					const res = await axios({
						url: 'http://localhost:8080/search/info-user',
						method: 'POST',
						headers: { Authorization: `Bearer ${webToken}` },
						data: { id: ID }
					})
					const updatedUserInfo: UserInfo = {
						id: ID,
						first_name: res.data.firstName,
						imageLink: res.data.imageLink,
						username: res.data.username,
						doubleAuth: res.data.doubleAuth,
						currentStatus: res.data.currentStatus
					}
					setUserInfo(updatedUserInfo)
				}
			}
			catch (err)	{ console.log(err) }
		}
		fetchUserInformationDisplay()
	}, [ID])

	useEffect(() => {
		if (userInfo.id !== -1 && localStorage.getItem("token")) {
			const fetchMatchHistory = async () => {
				try {
				  const res = await axios.post('http://localhost:8080/search/user-match-history', { id: userInfo.id }, { 
					  headers: { 'Authorization': `Bearer ${localStorage.getItem("token")}` 
					  }
				  });
				  let winCount = 0;
				  let looseCount = 0;
				  res.data.forEach((gameSession: GameSession) => {
					if (gameSession.winnerName === userInfo.username) {
					  winCount++;
					} else if (gameSession.loserName === userInfo.username) {
					  looseCount++;
					}
				  });
				  setWins(winCount);
				  setLoose(looseCount);
				  setGameSessionOutcome(res.data);
				} catch (err) {
				  console.error(err);
				}
			  };
			  fetchMatchHistory();
		}
	  }, [userInfo]);

	useEffect(() => {
		const fetchOtherUserInformationDisplay = async () => {
			try {
				if (newID !== -1)	{
					const res = await axios({
						url: 'http://localhost:8080/search/info-user',
						method: 'POST',
						headers: { Authorization: `Bearer ${webToken}` },
						data: { id: newID }
					})
					const updatedUserInfo: UserInfo = {
						id: newID,
						first_name: res.data.firstName,
						imageLink: res.data.imageLink,
						username: res.data.username,
						doubleAuth: res.data.doubleAuth,
						currentStatus: res.data.currentStatus
					}
					setUserInfo(updatedUserInfo)
				}
			}
			catch (err)	{ console.log(err) }
		}
		fetchOtherUserInformationDisplay()
	}, [newID, triggerAvatarChange])

	function				whichSendButton(e: React.MouseEvent<HTMLDivElement | HTMLButtonElement>): number	{
		const target = e.target as HTMLDivElement; const className = target.getAttribute('class')
		if (target.className === 'add-friend') { return 0 }
		else if (target.className === 'remove-friend') { return 1 }
		else if (target.className === 'block-friend') { return 2 }
		else { return 3 }
	}
	async		function	handleSocialInteract(e: React.MouseEvent<HTMLDivElement | HTMLButtonElement>)	{
		switch (whichSendButton(e))	{ case 0: await addUserFriend(); break;  case 1: await removeUserFriend(); break;  case 2: console.log('button-block-user'); break;  case 3: console.log('button-make-game') }
	}
	const 					waitHandleSocialInteract = debounce(handleSocialInteract, 500)
	async 		function	addUserFriend()	{ const res = await axios({ url: 'http://localhost:8080/friend/add', method: 'POST', headers: { Authorization: `Bearer ${webToken}` }, data: { ID, newID } }); console.log(res) }
	async 		function	removeUserFriend() { await axios({ url: 'http://localhost:8080/friend/remove', method: 'POST', headers: { Authorization: `Bearer ${webToken}` }, data: { ID, newID } }) }
	function 				triggerEffect()	{ setTriggerAvatarChange((prevKey) => prevKey + 1) }
	function				askDbForUsers(event: string) { setSearchTerm(event) }
	async		function 	handleUploadedFile(e: React.ChangeEvent<HTMLInputElement>) { if (e.target.files) {const file = e.target.files[0]; setUploadedFile(file)} }
	async		function 	changeAvatarProfil() {
		try {
			if (uploadedFile)	{
				const formData = new FormData()
    			formData.append('image', uploadedFile)
				const res = await axios({ url: 'http://localhost:8080/upload/avatar',
					headers: { Authorization: `Bearer ${webToken}`, 'Content-Type': 'multipart/form-data' },
					method: 'POST',
					data: formData
				})
				setNewID(ID); triggerEffect()
			}
		}
		catch (err) { console.log(err) }
	}
	async		function	change2FAUserStatus(e: React.MouseEvent<HTMLInputElement>)	{
		const status2FA = e.currentTarget.checked.valueOf()
		const res = await axios({
			url: 'http://localhost:8080/secure/update2FA',
			method: 'POST',
			headers: { Authorization: `Bearer ${webToken}` },
			data: { ID, status2FA }
		})
		const updatedUser = res.data
		setUserInfo(updatedUser); setNewID(ID); triggerEffect()
	}

	return (
		<SolidFrame frameClass='profil-frame'>
			<div className='search-frame'>
				<SearchBar searchTerm={searchTerm} onChange={(event) => askDbForUsers(event)} />
			</div>
			<SearchList webToken={webToken} setNewID={setNewID} searchTerm={searchTerm} />
			<div className='user-profil-frame element'>
				<div className='photo-frame'>
					<div className='avatar-container-profil'>
						<img src={userInfo.imageLink} />
					</div>
					{ (newID === ID || newID === -1) && !inChatBox ?
						<div className='container-avatar-change'>
							<label htmlFor='upload-file-input' className='custom-file-upload'>
								<input id='upload-file-input' className='upload-file-input' accept='image/*' type='file' onChange={handleUploadedFile}/>
								<span>{ uploadedFile ? uploadedFile.name : 'Choose file' }</span>
							</label>
							<button className='change-avatar-button' onClick={changeAvatarProfil}>Change avatar</button>
						</div>
						: null }
				</div>
				<div className='user-data-div-display'>
					<div className='user-profile-info'>
					<h1>User information</h1><br/>
						<p>Username: {userInfo.username}<br/><br/>Total Games: {gameSessionOutcome.length}<br/><br/>Connected: {userInfo.currentStatus} </p>
					</div>
					{ (newID === ID || newID === -1) && !inChatBox ? 
						<div className='container-friend-list-profile'>
							<h2>Friends</h2><br/>
							<div className='friend-list-scroll'>
							{friendList.map((friend, index) => (
								<div key={index} className='display-friend-list-cell'>
									<img className='image-cell-friend' src={friend.imageLink}></img>
									<span className={`status-circle ${friend.connected  !== 'offLine' ? 'online' : 'offline'}`}>&nbsp;{friend.friend}</span>
								</div>
							))}
							</div>
						</div>
					: 
					null }
					{ (newID === ID || newID === -1) && !inChatBox ?
						<div className='display-2fa-option'>
							<div className='switch-2fa'>
								<label className='form-switch'>
									2FA&nbsp;
									<input readOnly type='checkbox' onClick={(e)=>change2FAUserStatus(e)} checked={ userInfo.doubleAuth && userInfo.doubleAuth.length ? true : false }/>
									<i></i>
								</label>
							</div>
						</div>
					:
						<div className='container-social-button'>
							<div onClick={waitHandleSocialInteract} className='social-button-add'><p className='add-friend'>add<br/>friend</p></div>
							<div onClick={waitHandleSocialInteract} className='social-button-remove'><p className='remove-friend'>remove<br/>friend</p></div>
						</div>
					}
				</div>
			</div>
			<SolidFrame frameClass='info-frame element'>
				<Title frameClass='profil-title-frame' txtClass='text-profil-title' txt2='Stats' />
				{ !gameSessionOutcome.length ? (
					<SolidFrame frameClass='history-frame' txtClass='text-data-profil' txt1={stats} />
				) : (
					<div className="stats">
						<div className="wins">
							<div className="title">Wins</div>
							<div className="count">{wins}</div>
						</div>
						<div className="looses">
							<div className="title">Losses</div>
							<div className="count">{loose}</div>
						</div>
					</div>
				)}  
				{children}
			</SolidFrame>
			<SolidFrame frameClass='info-frame history element'>
				<Title frameClass='profil-title-frame' txtClass='text-profil-title' txt2='Match history' />
					{ newID !== -1 && newID !== ID ? 
					<div className='match-history-container'><MatchHistory userID={newID} token={webToken} /></div>
					: 
					<div className='match-history-container'><MatchHistory userID={ID} token={webToken} /></div> }
			</SolidFrame>
		</SolidFrame>
	)
}

export default Profil
