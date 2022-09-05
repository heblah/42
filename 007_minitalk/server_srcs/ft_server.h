#ifndef FT_SERVER_H
# define FT_SERVER_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/* ./00_server.c ============================================================ */
int		ft_strlen(char *s);

/* ./01_print.c ============================================================= */
void	ft_putpid(pid_t pid);
void	srv_pid(pid_t pid);
#endif
