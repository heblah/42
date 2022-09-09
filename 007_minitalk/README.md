#		Minitalk

Send text message from client to server using SIGUSR1 and SIGUSR2.  
    - The client send an UTF-8 text message.  
    - After the null char, the server send back a signal to confirm the reception.
