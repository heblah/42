import React, { useState, useEffect } from 'react';
import axios from 'axios'
import { Dispatch, SetStateAction } from 'react'
import './SearchList.scss'

interface User {
	id: number;
	username: string;
}

interface SearchListProps	{
	webToken: string,
	searchTerm: string,
	setNewID: Dispatch<SetStateAction<number>>
}

const SearchList = ({webToken, setNewID, searchTerm}: SearchListProps) => {
	const [users, setUsers] = useState<User[]>([])
	
	async function askDataBaseForSearchBarContent()	{
		try {
			const	searchResultURL = 'http://localhost:8080/search/users'
			const	res = await axios({
				url: searchResultURL,
				method: 'POST',
				headers: { Authorization: `Bearer ${webToken}` },
				data:	{ searched: searchTerm }
			})
			setUsers(res.data)
		}
		catch (error) {
			console.error('Error fetching user data:', error)
		}
	}

	function MouseOver(event: React.MouseEvent<HTMLDivElement>) {
		const target = event.target as HTMLDivElement;
		target.style.opacity = '0.8'
	}

	function MouseOut(event: React.MouseEvent<HTMLDivElement>){
		const target = event.target as HTMLDivElement;
		target.style.opacity = '1'
	}

	useEffect(() => {
		if (searchTerm)
			askDataBaseForSearchBarContent()
	}
	, [searchTerm])

	async function	navigateToSelectedProfile(e: React.MouseEvent<HTMLDivElement>)	{
		const	tag = e.target as HTMLDivElement
		const	text = tag.textContent
		if (text)	{
			const user = users.filter(user => user.username.toLowerCase().includes(text.toLowerCase()))
			setNewID(user[0].id)
		}
	}

	return (
		<div className='search-list' >
			{searchTerm ? 
			<ul>
				{users.length ? users.map((user) => (
					<div className='search-list-display-user' onMouseOver={MouseOver} onMouseLeave={MouseOut} onClick={(e) => navigateToSelectedProfile(e)} key={user.id}>
						{user.username}
					</div>
				)) : 
					<div>
						No user matched your search
					</div>
				}
			</ul>
			: null }
		</div>
	)
}

export default SearchList