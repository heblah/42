#ifndef FT_CLIENT_H
# define FT_CLIENT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>

/* ./00_client.c ============================================================ */
void	msg2server(int srv_pid, char *msg);
void	msg_received(int sig, siginfo_t *info, void *context);

/* ./01_parser.c ============================================================ */
size_t	ft_strlen(char *s);
int		parser(int argc, char **argv);
#endif
