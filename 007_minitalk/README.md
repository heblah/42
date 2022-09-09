#		Minitalk

Send text message from client to server using SIGUSR1 and SIGUSR2.  
	1. The client send an UTF-8 text message.  
    2. After the null char, the server send back a signal to confirm the reception.
