import React, { useState, useEffect } from 'react';
import { Dispatch, SetStateAction } from 'react'
import SolidFrame from '../SolidFrame/SolidFrame';
import axios from 'axios'
import { debounce } from 'lodash'

interface ProfileUserButtonProps	{
	webToken: string,
	newID: number,
	ID: number
}


const ProfileUserButton = ({webToken, newID, ID}: ProfileUserButtonProps) => {
	function	whichSendButton(e: React.MouseEvent<HTMLButtonElement>): number	{
		const target = e.target as HTMLButtonElement;
		if (target.className === 'solid-frame text-content button-interface-actions-user button-add-friend')
			return 0
		else if (target.className === 'solid-frame text-content button-interface-actions-user button-remove-friend')
			return 1
		else if (target.className === 'solid-frame text-content button-interface-actions-user button-block-user')
			return 2
		return 3
	}

	async function	handleSocialInteract(e: React.MouseEvent<HTMLButtonElement>)	{
		switch (whichSendButton(e))	{
			case 0:
				await axios({
					url: 'http://localhost:8080/friend/add',
					method: 'POST',
					headers: { Authorization: `Bearer ${webToken}` },
					data: { ID, newID }
				})
				break
			case 1:
				await axios({
					url: 'http://localhost:8080/friend/remove',
					method: 'POST',
					headers: { Authorization: `Bearer ${webToken}` },
					data: { ID, newID }
				})
				break
			case 2:
				console.log('button-block-user')
				break
			case 3:
				console.log('button-make-game')
		}
	}

	const waitHandleSocialInteract = debounce(handleSocialInteract, 500)

	function MouseOver(event: React.MouseEvent<HTMLButtonElement>) {
		const target = event.target as HTMLButtonElement;
		target.style.opacity = '1'
		target.style.borderWidth = '3px'
	}

	function MouseOut(event: React.MouseEvent<HTMLButtonElement>){
		const target = event.target as HTMLButtonElement;
		target.style.opacity = '0.8'
		target.style.borderWidth = '2px'
	}

	return (
		<div>
			{ newID === -1 || newID === ID ?
				null :
				<SolidFrame frameClass="button-interface-actions-user">
					<button onMouseOver={MouseOver} onMouseLeave={MouseOut} onClick={waitHandleSocialInteract} className="solid-frame text-content button-interface-actions-user button-add-friend" >Add friend</button>
					<button onMouseOver={MouseOver} onMouseLeave={MouseOut} onClick={waitHandleSocialInteract} className="solid-frame text-content button-interface-actions-user button-remove-friend" >Remove Friend</button>
					<button onMouseOver={MouseOver} onMouseLeave={MouseOut} onClick={waitHandleSocialInteract} className="solid-frame text-content button-interface-actions-user button-block-user" >Block User</button>
					<button onMouseOver={MouseOver} onMouseLeave={MouseOut} onClick={waitHandleSocialInteract} className="solid-frame text-content button-interface-actions-user button-make-game" >Make Game</button>
			</SolidFrame> }
		</div>
	)
}

export default ProfileUserButton
