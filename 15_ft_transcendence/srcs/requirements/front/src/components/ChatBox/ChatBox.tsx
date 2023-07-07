import React, { useState, useEffect, useRef, useContext } from 'react'
import SolidFrame from '../SolidFrame/SolidFrame'
import SearchList from "../SearchList/SearchList"
import SearchBar from "../SearchBar/SearchBar"
import Profil from '../Profil/Profil'
import { io } from 'socket.io-client'
import './ChatBox.scss'
import { reject, set } from 'lodash'
import { useNavigate } from "react-router-dom";
import { Dispatch, SetStateAction } from 'react'

const ChatBox: React.FC<{
	userDbID: number,
	pongGameGuestIDref: React.MutableRefObject<number | null>,
	pongGameHostIDref: React.MutableRefObject<number | null>,
	refreshWebToken: Dispatch<SetStateAction<string>>,
	webToken: string
}> = (props) => {




	const channelIdRef = useRef<number>(-1);

	const [socket, setSocket] = useState<any>(null);
	const [searchTerm, setSearchTerm] = useState('')

	const [createChannelMode, setCreateChannelMode] = useState<boolean>(false);
	const [joinChannelMode, setJoinChannelMode] = useState<boolean>(false);
	const [sidebarVisible, setSidebarVisible] = useState<boolean>(true);
	const [joined, setJoined] = useState<boolean>(false);

	const [formFailed, setFormFailed] = useState<boolean>(false);
	const [fomrError, setFormError] = useState<string>("");

	const [showProfile, setShowProfile] = useState<boolean>(false);
	const [selectedUserId, setSelectedUserId] = useState<number>(-1);

	const [messages, setMessages] = useState<any[]>([]);
	const [messageText, setMessageText] = useState('');

	const [typingDisplay, setTypingDisplay] = useState('');

	const [channels, setChannels] = useState<any[]>([]);
	const [channelsVisible, setChannelsVisible] = useState<boolean>(true)

	const [dm, setDm] = useState<any[]>([]);
	const [DMVisible, setDMVisible] = useState<boolean>(true)

	const [invitations, setInvitations] = useState<any[]>([]);
	const [invitationsVisible, setInvitationsVisible] = useState<boolean>(true)


	const [joinChatName, setJoinChatName] = useState<string>('');
	const [joinPassword, setJoinPassword] = useState<string>('');

	const [createChatName, setCreateChatName] = useState<string>('');
	const [createPassword, setCreatePassword] = useState<string>('');

	//fields for pongGame
	const navigate = useNavigate();
	const [showModal, setShowModal] = useState(false); 
	const pongGameInviteRefusalCallbackRef = useRef<(() => void) | null>(null)


	useEffect(() => {
		console.log(`Token in chatBox: ${props.webToken}`)
		const socketInstance = io('http://localhost:8080', {query: { token: props.webToken }});
		console.log(socketInstance)
		setSocket(socketInstance);

		// const handleDisconnect = async () => {
		// 	// Logique à exécuter lorsque l'utilisateur se déconnecte
		// 	console.log("L'utilisateur s'est déconnecté");
		// 	// Appeler votre fonction de déconnexion ici
		// 	await updateUserAllChatConnectionStatus(false);
		//   };
		console.log(props.userDbID)

		//   socketInstance.on('disconnect', handleDisconnect);
		return () => {
			socketInstance.disconnect();
		};
	}, []);

	useEffect(() => {
		if (!socket) return;

		const fetchData = async () => {
			try {
				await findDirectMessageChannels();
				await findAllInvitations();
				await findAllChannels();
			} catch (error) {
				console.log(error);
			}
		};
		fetchData();
		socket.on('updateChannels', (option: string, newChannel: any) => {
			if (option === 'add')
				setChannels((prevChannels: any[]) => [...prevChannels, newChannel]);
			else if (option === 'remove')
				setChannels((prevChannels: any[]) => prevChannels.filter((channel) => channel.id !== newChannel.id));
		});

		socket.on('updateInvitations', (option: string, newInvitation: any) => {
			if (option === 'add')
				setInvitations((prevInvitations: any[]) => [...prevInvitations, newInvitation]);
			else if (option === 'remove')
				setInvitations((prevInvitations: any[]) => prevInvitations.filter((invitation) => invitation.channelId !== newInvitation.channelId));
		});

		socket.on('updateDM', (option: string, newDM: any) => {
			if (option === 'add')
				setDm((prevDM: any[]) => [...prevDM, newDM]);
			else if (option === 'remove')
				setDm((prevDM: any[]) => prevDM.filter((DM) => DM.id !== newDM.id));
		});

		socket.on('message', (message: any) => {
			setMessages((prevMessages: any[]) => [...prevMessages, message]);
		});

		socket.on('typing', ({ name, isTyping }: { name: string, isTyping: boolean }) => {
			if (isTyping) {
				setTypingDisplay(`${name} is typing...`);
			} else {
				setTypingDisplay('');
			}
		});

		socket.on('formFailed', (error: string) => {
			showFormError(error);
		});

		socket.on('disconectChannel', () => {
			hideChannel();
		});

		socket.on('leaveChannel', () => {
			channelIdRef.current = -1;
			setJoined(false);
			setMessages([]);
		});

		//for pong game invites
		socket.on('pong-game-invite', (hostID: number, callback: () => void) => {
			console.log(`Received pong-game-invite event`)
			props.pongGameHostIDref.current = hostID
			pongGameInviteRefusalCallbackRef.current = callback
			// alert(`Received pong-game-invite event`, )
			setShowModal(true)
		})

		return () => {
			socket.off('disconectChannel');
			socket.off('updateChannels');
			socket.off('updateInvitations');
			socket.off('updateDM');
			socket.off('leaveChannel');
			socket.off('formFailed');
			socket.off('message');
			socket.off('typing');
			socket.disconnect();
		};
	}, [socket]);

	useEffect(() => {
		if (selectedUserId !== -1)
			setShowProfile(true);
		console.log(selectedUserId)
	}, [selectedUserId]);

	const findChannel = async (channelName: string, password: string) => {
		return new Promise<void>((resolve) => {
			if ((channelName.length < 1 || channelName.length > 20) || (password.length < 1 && password.length > 20)) {
				showFormError("Chat name or password must be between 1 and 20 characters");
				reject("Chat name or password must be between 1 and 20 characters");
			}
			else {
				socket.emit('findChannel', { channelName, password }, (response: number) => {
					channelIdRef.current = response;
					resolve();
				});
			}
		});
	};

	const showFormError = (error: string) => {
		setFormFailed(true);
		setFormError(error);

		setTimeout(() => {
			setFormFailed(false);
			setFormError("");
		}, 2000);
	};

	const join = async () => {
		return new Promise<void>((resolve, reject) => {
			if (channelIdRef.current !== -1) {
				socket.emit('join', { userId: props.userDbID, channelId: channelIdRef.current }, (response: boolean) => {
					if (response) {
						setMessages([]);
						setJoined(true);
						socket.emit('findAllChannelMessages', { userId: props.userDbID, channelId: channelIdRef.current }, (response: any) => {
							// setMessages(response);
							setMessages(Array.isArray(response) ? response : [response]);
							console.log(`Messages set to ${JSON.stringify(response)} in findAllChannelMessages callback in join`)
							resolve();
						});
					} else {
						reject("emit failed");
					}
				});
			} else {
				reject("channelIdRef.current is -1");
			}
		});
	};

	const findAllChannels = async () => {
		return new Promise<void>((resolve) => {
			socket.emit('findAllChannels', { userId: props.userDbID }, (response: any) => {
				setChannels(response);
				resolve();
			});
		})
	};

	const findDirectMessageChannels = async () => {
		return new Promise<void>((resolve) => {
			socket.emit('findDirectMessageChannels', { userId: props.userDbID }, (response: any) => {
				setDm(response);
				console.log("all directs messages", response)
				resolve();
			});
		})
	};

	const findAllInvitations = async () => {
		return new Promise<void>((resolve) => {
			socket.emit('findAllInvitations', { userId: props.userDbID }, (response: any) => {
				setInvitations(response);
				resolve();
			});
		});
	};

	const createChannel = async (chatName: string, password: string) => {
		return new Promise<void>((resolve, reject) => {
			if ((chatName.length < 1 || chatName.length > 20) || (chatName.length < 1 || password.length > 20)) {
				showFormError("Chat name or password must be between 1 and 20 characters");
				reject("Chat name or password must be between 1 and 20 characters");
			}
			else {
				socket.emit('createChannel', { userId: props.userDbID, chatName, password }, (response: boolean) => {
					if (response) {
						setMessages([]);
						resolve();
					} else {
						reject("Can't create channel");
					}
				});
			}
		})
			.then(() => {
				return findChannel(chatName, password);
			})
			.then(() => {
				if (channelIdRef.current !== -1) {
					return updateUserChatConnectionStatus(true)
				}
			})
			.then(() => {
				setJoined(true);
			})
			.catch((error) => {
				console.log(error);
			});
	};

	const sendMessage = async () => {
		return new Promise<void>((resolve, reject) => {
			if (channelIdRef.current !== -1) {
				if (messageText.length < 1 || messageText.length > 1000) {
					showFormError("Message must be between 1 and 1000 characters (" + messageText.length + " characters )")
					reject("Message must be between 1 and 1000 characters");
				}
				else {
					socket.emit('createMessageChannel', { text: messageText, channelId: channelIdRef.current, userId: props.userDbID }, (response: boolean) => {
						resolve();
					});
				}
			} else {
				reject("channelIdRef.current is -1");
			}
		})
			.then(() => {
				setMessageText('');
			})
	};

	const handleDMClick = async () => {
		const clickedUserId = selectedUserId;
		const dmObject = dm.find((item) => item.otherUserId === clickedUserId);

		if (dmObject) {
			channelIdRef.current = dmObject.channelId;
			if (channelIdRef.current !== -1) {
				join()
					.then(() => {
						hideProfile();
					})
					.catch((error) => {
						console.log(error);
					});
			}
		}
		else {
			return new Promise<void>((resolve, reject) => {
				socket.emit('createDM', { firstUser: props.userDbID, secondUser: clickedUserId }, (response: any) => {
					if (response) {
						channelIdRef.current = response.channelId;
						resolve();
					} else {
						channelIdRef.current = -1
						reject("Can't create DM");
					}
				});
			})
				.then(() => {
					if (channelIdRef.current !== -1) {
						return updateUserChatConnectionStatus(true);
					} else {
						throw new Error("Invalid channel ID");
					}
				})
				.then(() => {
					hideProfile();
					setJoined(true);
					setMessages([]);
				})
				.catch((error) => {
					console.log(error);
				});
		}
	};

	const updateUserChatConnectionStatus = async (neaStatus: boolean) => {
		return new Promise<void>((resolve) => {
			socket.emit('updateUserChatConnectionStatus', { userId: props.userDbID, channelId: channelIdRef.current, isConnect: neaStatus }, (response: any) => {
				resolve();
			});
		});
	};

	const handleChannelClick = async (clickedChannelId: number) => {
		channelIdRef.current = clickedChannelId;
		if (channelIdRef.current !== -1) {
			await join()
				.catch((error) => {
					console.log(error);
				});
		}
	};

	const handleInvitationlClick = async (invitationId: number, accepted: boolean, type: string) => {
		return new Promise<void>((resolve, reject) => {
			socket.emit('joinInvitation', { userId: props.userDbID, invitationId, accepted }, (response: boolean) => {
				if (response) {
					const updatedInvitations = invitations.filter(invitation => invitation.id !== invitationId);
					setInvitations(updatedInvitations);
					resolve();
				}
				reject();
			});
		})
	};

	const handleUserClick = async (userName: string) => {
		return new Promise<void>((resolve, reject) => {
			socket.emit('findUserInfo', { userName }, (response: any) => {
				if (response.length !== 0) {
					console.log(response.username);
					setSelectedUserId(response.id);
					setShowProfile(true);
					console.log(selectedUserId);
				}
				resolve();
			});
		});
	};

	const hideProfile = () => {
		setSelectedUserId(-1);
		setShowProfile(false);
	};

	const hideJoinForm = () => {
		setJoinChannelMode(false);
	};

	const hideCreateForm = () => {
		setCreateChannelMode(false);
	};

	const hideChannel = async () => {
		updateUserChatConnectionStatus(false)
			.then(() => {
				channelIdRef.current = -1;
				setJoined(false);
				setMessages([]);
			})
			.catch((error) => {
				console.log(error);
			});
	};
	let timeout;

	const emitTyping = () => {
		socket.emit('typing', { userId: props.userDbID, isTyping: true, channelId: channelIdRef.current });

		timeout = setTimeout(() => {
			socket.emit('typing', { userId: props.userDbID, isTyping: false, channelId: channelIdRef.current });
		}, 2000);
	};

	function askDbForUsers(event: string) {
		setSearchTerm(event)
	}

	if (!joined && !showProfile) {
		return (
			<SolidFrame frameClass="chat-box" >
				<SolidFrame frameClass="in-row">
					<SolidFrame frameClass="">
						<div className="solid-frame search-container">
							<div className="solid-frame search text-content" >Find your friends:</div>
							<SolidFrame
								frameClass="solid-frame search-frame"
							>
								<SearchBar searchTerm={searchTerm} onChange={(event) => askDbForUsers(event)} />
							</SolidFrame>
							<SearchList webToken={props.webToken} setNewID={setSelectedUserId} searchTerm={searchTerm} />
						</div>
						{!createChannelMode && !joinChannelMode && (
							<div className="button-container">
								<button
									className="solid-frame button-frame-choice text-content text-button-choice "
									onClick={() => setCreateChannelMode(true)}
								>
									Create Channel
								</button>
								<button
									className="solid-frame button-frame-choice text-content text-button-choice"
									onClick={() => setJoinChannelMode(true)}
								>
									Join Channel
								</button>
							</div>
						)}
						{joinChannelMode && (
							<form
								className="solid-frame create-chan-frame"
								onSubmit={async (e) => {
									e.preventDefault();
									try {
										await findChannel(joinChatName, joinPassword);
										await join();
									} catch (error) {
										console.log('Error:', error);
									}
								}}
							>
								<label
									className="solid-frame label-frame text-content text-label"
								>
									Chat name:
								</label>
								<input
									className="solid-frame input-frame text-content text-input"
									value={joinChatName}
									onChange={(e) => setJoinChatName(e.target.value)} />
								<label
									className="solid-frame label-frame text-content text-label"
								>
									Chat password:
								</label>
								<input
									className="solid-frame input-frame text-content text-input"
									value={joinPassword}
									onChange={(e) => setJoinPassword(e.target.value)}
									type="password" />
								<button
									className="solid-frame button-frame text-content text-button"
									type="submit"
								>
									Join room
								</button>
								<button className="solid-frame button-frame text-content text-button"
									onClick={hideJoinForm}>return</button>

							</form>
						)}
						{createChannelMode && (
							<form
								className="solid-frame user-frame"
								onSubmit={async (e) => {
									e.preventDefault();
									await createChannel(createChatName, createPassword);
								}}
							>
								<label
									className="solid-frame label-frame text-content text-label"
								>
									Chat name :
								</label>
								<input
									className="solid-frame input-frame text-content text-input"
									value={createChatName}
									onChange={(e) => setCreateChatName(e.target.value)} />
								<label
									className="solid-frame label-frame text-content text-label"
								>
									Chat password:
								</label>
								<input
									className="solid-frame input-frame text-content text-input"
									value={createPassword}
									onChange={(e) => setCreatePassword(e.target.value)}
									type="password" />
								<button
									className="solid-frame button-frame text-content text-button"
									type="submit"
								>
									Create room
								</button>
								<button className="solid-frame button-frame text-content text-button"
									onClick={hideCreateForm}>return</button>

							</form>
						)}
						{formFailed && (
							<div className="solid-frame  text-content text-label error-message ">
								{fomrError}
							</div>
						)}
					</SolidFrame>
					<SolidFrame frameClass="sidebar">
						<div className="solid-frame text-content text-label">
							<h2 className="channel-item header" onClick={() => setChannelsVisible(!channelsVisible)}>Channels:</h2>
							<ul className={`channel-list ${!channelsVisible ? "close" : ""}`}>
								<>
									{(channelsVisible && channels.length !== 0) ? (
										channels.map((channel: any) => (
											<li className="channel-item" key={channel.id}>
												<div className="channel-name" onClick={() => handleChannelClick(channel.id)}>
													{channel.ChannelName}
												</div>
											</li>
										))
									) : (
										channels.length === 0 ? (
											<div className="channel-name"> empty </div>
										) : (
											<div className="channel-name"> --- </div>
										)
									)}
								</>
							</ul>
							<h2 className="channel-item header" onClick={() => setDMVisible(!DMVisible)}>DM:</h2>
							<ul className={`channel-list ${!DMVisible ? "close" : ""}`}>
								{(DMVisible && dm.length !== 0) ? (
									dm.map((dm: any) => (
										<li className="channel-item" key={dm.channelId}>
											<div className="channel-name" onClick={() => handleChannelClick(dm.channelId)}>
												{dm.otherUserUsername}
											</div>
										</li>
									))
								) : (
									dm.length === 0 ? (
										<div className="channel-name"> empty </div>
									) : (
										<div className="channel-name"> --- </div>
									)
								)}
							</ul>
							<h2 className="solid-frame channel-item header" onClick={() => setInvitationsVisible(!invitationsVisible)}>Invitations:</h2>
							<ul className={`channel-list ${!invitationsVisible ? "close" : ""}`}>
								<>
									{(invitationsVisible && invitations.length !== 0) ? (
										invitations.map((invitation: any) => (
											<li className="channel-item" key={invitation.id}>
												<div className="solid-frame channel-name invite">
													join {invitation.whoInviteUserName}'s {invitation.type} invitation now
												</div>
												<div className="invitation-buttons">
													<button className="button-yes" onClick={async () => {
														try {
															await handleInvitationlClick(invitation.id, true, invitation.type);
														} catch (error) {
															console.log(error);
														}
													}}> Yes </button>
													<button className="button-no" onClick={async () => {
														try {
															await handleInvitationlClick(invitation.id, false, invitation.type);
														} catch (error) {
															console.log(error);
														}
													}}>No</button>
												</div>
											</li>
										))
									) : (
										invitations.length === 0 ? (
											<div className="channel-name"> empty </div>
										) : (
											<div className="channel-name"> --- </div>
										)
									)}
								</>
							</ul>
						</div>
					</SolidFrame>
				</SolidFrame>
				<div>
					{/* JSX for pong game invites*/}
					{showModal && (
						<div className="modal">
							<div className="modal-content">
								<h2>You received an invite to the play a pong game!</h2>
								<button onClick={() => {
									socket.disconnect()
									navigate('/Pong')
									setShowModal(false)
								}}>
									Accept
								</button>
								<button onClick={() => {
									props.pongGameGuestIDref.current = null
									setShowModal(false)
									if (pongGameInviteRefusalCallbackRef.current !== null) {
										pongGameInviteRefusalCallbackRef.current()
									} else {
										console.error("Warning: pongGameInviteRefusalCallbackRef.current is null!")
									}
									pongGameInviteRefusalCallbackRef.current = null
								}}>Refuse</button>
							</div>
						</div>
					)}
				</div>
			</SolidFrame>
		);
	}
	else if (showProfile)
		return (
			<>
				<Profil ID={selectedUserId} webToken={props.webToken} refreshWebToken={props.refreshWebToken} inChatBox={true}/>
				{props.userDbID !== selectedUserId &&
					<>
						<button className="solid-frame button-frame-choice text-content text-button-choice"
							onClick={async () => {
								await handleDMClick();
							}}>
							DM
						</button>
						<button
							className="solid-frame button-frame-choice text-content text-button-choice"
							onClick={() => {
								props.pongGameGuestIDref.current = selectedUserId
								console.log('props.pongGameGuestIDref.current set to ', selectedUserId)
								socket.disconnect()
								navigate("/Pong");
							}}
						>
							Invite to pong game
						</button>
					</>
				}
				<button className="solid-frame button-frame-choice text-content text-button-choice"
					onClick={hideProfile}>return to chat</button>

					<div>
						{/* JSX for pong game invites*/}
						{showModal && (
							<div className="modal">
								<div className="modal-content">
									<h2>You received an invite to the play a pong game!</h2>
									<button onClick={() => {
										socket.disconnect()
										navigate('/Pong')
										setShowModal(false)
									}}>
										Accept
									</button>
									<button onClick={() => {
										props.pongGameGuestIDref.current = null
										setShowModal(false)
										if (pongGameInviteRefusalCallbackRef.current !== null) {
											pongGameInviteRefusalCallbackRef.current()
										} else {
											console.error("Warning: pongGameInviteRefusalCallbackRef.current is null!")
										}
										pongGameInviteRefusalCallbackRef.current = null
									}}>Refuse</button>
								</div>
							</div>
						)}
					</div>
			</>
		)
	return (
		<SolidFrame frameClass="chat-box" >
			<div
				className="solid-frame messages-container text-content text-container"
			>
				{
					(() => {
						// console.log(`Messages: `, JSON.stringify(messages, null, 2));
						return messages.map((message: any, index: number) => (
							<div key={index}>
								<span
									className="message-name"
									onClick={async () => {
										await handleUserClick(message.name);
									}}>
									{message.name}
								</span>
								: {message.text}
							</div>
						));
					})()
				}

			</div>

			{typingDisplay && <div className="text-content text-label">{typingDisplay}</div>}

			{/*<hr /> commented just in case it is usefull*/}
			<div
				className="solid-frame write-frame"
			>
				<form
					className="solid-frame write-frame"
					onSubmit={(e) => {
						e.preventDefault();
						sendMessage()
							.catch((error) => {
								console.log(error);
							});
					}}>
					<label
						className="solid-frame label-frame text-content text-label"
					>
						Message:
					</label>
					<textarea
						className="solid-frame input-frame text-content text-chatmsg-input text-msg-input"
						value={messageText}
						onChange={(e) => setMessageText(e.target.value)}
						onInput={emitTyping}
					/>
					{formFailed && (
						<div className="solid-frame  text-content text-label error-message ">
							{fomrError}
						</div>
					)}
					<button
						className="solid-frame button-frame text-content text-button"
						type="submit"
					>
						Send
					</button>
					<button className="solid-frame button-frame text-content text-button"
						type="button"
						onClick={hideChannel}>return
					</button>
				</form>
			</div>

			<div>
				{/* JSX for pong game invites*/}
				{showModal && (
					<div className="modal">
						<div className="modal-content">
							<h2>You received an invite to the play a pong game!</h2>
							<button onClick={() => {
								socket.disconnect()
								navigate('/Pong')
								setShowModal(false)
							}}>
								Accept
							</button>
							<button onClick={() => {
								props.pongGameGuestIDref.current = null
								setShowModal(false)
								if (pongGameInviteRefusalCallbackRef.current !== null) {
									pongGameInviteRefusalCallbackRef.current()
								} else {
									console.error("Warning: pongGameInviteRefusalCallbackRef.current is null!")
								}
								pongGameInviteRefusalCallbackRef.current = null
							}}>Refuse</button>
						</div>
					</div>
				)}
			</div>
		</SolidFrame>
	)
}

export default ChatBox;
