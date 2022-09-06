#ifndef FT_SERVER_H
# define FT_SERVER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>

/* ./00_server.c ============================================================ */
void	handle_msg(int sig, siginfo_t *info, void *context);

/* ./01_print.c ============================================================= */
void	srv_pid(void);
int		ft_strlen(char *s);
#endif
