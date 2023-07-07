import { useEffect, useState } from 'react'
import React from 'react'
import { useNavigate } from 'react-router-dom'
import { Dispatch, SetStateAction } from 'react'
import axios from 'axios'
import './Login.scss'

interface LoginProps { log: Dispatch<SetStateAction<boolean>>, controlJwtToken: Dispatch<SetStateAction<string>>, ID: Dispatch<SetStateAction<number>> }
const Login: React.FC<LoginProps> = (control) => {
  let renderer = null
  interface UserApiData { id: number, first_name: string, last_name: string }

  const [userLogged, setUserLogged] = useState(false) 
  const [userApiData, setUserApiData] = useState<UserApiData | null>(null)
  const [userDbData, setUserDbData] = useState(null)
  const [attemptLogin, setAttemptLogin] = useState(false)
  const [doubleAuth, setDoubleAuth] = useState('') 
  const [dOptAuth, setDOptAuth] = useState('')
  const [userName, setUserName] = useState('')
  const [check2FA, setcheck2FA] = useState(false)
  const [token2FA, setToken2FA] = useState('')
  const [webToken, setWebToken] = useState('')
  const [stateBadUsername, setStateBadUsername] = useState(false)

  function executeAlert(msg: string) { alert(msg); setStateBadUsername(false); return true }

  async function askDataBaseForCreation(code: string) {
    const checkUserStateURL = 'http://localhost:8080/42Api/log'
    const res = await axios({ url: checkUserStateURL, method: 'POST', data: { code } })
    if (res.data.dbData)
      setDOptAuth(res.data.dbData.doubleAuth)
    setUserApiData(res.data.apiData)
    setUserDbData(res.data.dbData)
    setUserLogged(true)
    control.controlJwtToken(res.data.jwtSecureToken)
    localStorage.setItem('token', res.data.jwtSecureToken)
    setWebToken(res.data.jwtSecureToken)
    control.ID(res.data.apiData.id)
  }

  useEffect(() => {
      try {
        const queryParams = new URLSearchParams(window.location.search)
        const code = queryParams.get('code')
        if (code !== null)  { askDataBaseForCreation(code) }
      }
      catch (err) { console.log(err) }
  }, [attemptLogin])

  async function attemptConnect() {
    try {
      const logURL = 'https://api.intra.42.fr/oauth/authorize?client_id=u-s4t2ud-a672fd80ce2f029d5ff47b1c3f7f409fbe73cafcedb7f3b4cf7e8efc39f22a00&redirect_uri=http%3A%2F%2Flocalhost%3A3000%2FLogin&response_type=code'
      window.location.href = logURL; setAttemptLogin(true);
    }
    catch (err) { console.log(err) }
  }

  async function pushUserinDataBase(e: React.FormEvent<HTMLFormElement>)  {
    e.preventDefault()
    try {
      const addUserURL = 'http://localhost:8080/secure/add'
      const res = await axios({ url: addUserURL, method: 'POST', headers: { Authorization: `Bearer ${webToken}` }, data: { apiData: userApiData, username: userName, doubleAuth: doubleAuth } })
      setUserDbData(res.data)
    }
    catch (err) { setStateBadUsername(true); }
  }

	async function  handle2FA() {
    try {
      const handle2FAURL = 'http://localhost:8080/secure/secure'
      const res = await axios({ url: handle2FAURL, method: 'POST', headers: { Authorization: `Bearer ${webToken}` }, data : { info: userApiData }})
      setcheck2FA(true)
    }
    catch (err) { console.log(err) }
	}

  async function handle2FAVerif() {
    const check2FAURL = 'http://localhost:8080/secure/token'
    const check = await axios({ method: 'POST', url: check2FAURL, headers: { Authorization: `Bearer ${webToken}` }, data: { id: userApiData?.id, token: token2FA } })
    if (check.data === 'approved') { setcheck2FA(false); setDOptAuth('') }
    else { console.log('bad password') }
  }

  if (!userLogged)
    renderer = (
      <div className="solid-frame connect-frame">
          <button className="solid-frame connect-button text-content text-connect" onClick={attemptConnect}>Connect</button>
      </div>
    )
  else if (check2FA)  {
    renderer = (
      <div className="solid-frame two-fa-frame">
        <input className="solid-frame input-frame text-content text-input" onChange={(event)=>{setToken2FA(event.target.value)}} type='text' required></input>
        <button className="solid-frame button-frame text-content text-button" onClick={handle2FAVerif}>Verify code!</button>
      </div>
    )
  }
  else if (userLogged && userDbData && dOptAuth === 'on') {
    renderer = (
      <div className="solid-frame two-fa-frame">
        <button className="solid-frame button-frame text-content text-button" onClick={handle2FA}>To make 2FA, press here!</button>
      </div>
    )
  }
  else if (userLogged && userApiData && !userDbData)  {
    renderer = (
      <div className="solid-frame user-logged-frame text-content">
        User Logged, Apply design please, your welcome { userApiData.first_name }!
        <form className="solid-frame user-logged-frame text-content" onSubmit={(e) => pushUserinDataBase(e)} >
          <input className="solid-frame input-frame text-content text-label" onChange={(event)=>{setUserName(event.target.value)}} type='text' required />
						Choose username<br/>
          <input className="solid-frame checked-frame text-content text-input" onChange={(event)=>{setDoubleAuth(event.target.value)}} type='checkbox' />
          <button className="solid-frame button-frame text-content text-button" type='submit'>Submit</button>
        </form>
        { stateBadUsername && executeAlert('This username already exists. Please retry.') ? null : null }
      </div>
    )
  }
  // else { control.log(true); window.history.replaceState(null, '', '/') }
  else { control.log(true); window.history.replaceState(null, '', '/') }
  return renderer
}
export default Login
