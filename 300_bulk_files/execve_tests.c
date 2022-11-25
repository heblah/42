/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:49:56 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/26 19:28:54 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** Emulate `cmd1 | cmd2 | more` pipeline using recursion.
http://stackoverflow.com/questions/20434124/recursive-piping-in-unix-environment
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#define EXIT_FAILURE 1

static int child = 0; /* whether it is a child process relative to main() */

static void report_error_and_exit(const char* msg) {
  perror(msg);
  (child ? _exit : exit)(EXIT_FAILURE);
}

/** move oldfd to newfd */
static void redirect(int oldfd, int newfd) {
  if (oldfd != newfd) {
    if (dup2(oldfd, newfd) != -1)
      close(oldfd); /* successfully redirected */
    else
      report_error_and_exit("dup2");
  }
}

/** execute `cmds[pos]` command and call itself for the rest of the commands.
    `cmds[]` is NULL-terminate array
    `exec_pipeline()` never returns.
*/
static void exec_pipeline(char* const* cmds[], size_t pos, int in_fd) {
  if (cmds[pos + 1] == NULL) { /* last command */
    redirect(in_fd, STDIN_FILENO); /* read from in_fd, write to STDOUT */
    execvp(cmds[pos][0], cmds[pos]);
    report_error_and_exit("execvp last");
  }
  else { /* $ <in_fd cmds[pos] >fd[1] | <fd[0] cmds[pos+1] ... */
    int fd[2]; /* output pipe */
	int	pid;
    if (pipe(fd) == -1)
      report_error_and_exit("pipe");
    pid = fork();
	if (pid == -1)
      report_error_and_exit("fork");
    //case 0: /* child: execute current command `cmds[pos]` */
	if (pid == 0)
	{
      //child = 1;
      close(fd[0]); /* unused */
      redirect(in_fd, STDIN_FILENO);  /* read from in_fd */
      redirect(fd[1], STDOUT_FILENO); /* write to fd[1] */
      execvp(cmds[pos][0], cmds[pos]);
      report_error_and_exit("execvp");
	 }
    //default: /* parent: execute the rest of the commands */
	if (pid != -1 && pid != 0)
	{
      close(fd[1]); /* unused */
      close(in_fd); /* unused */
      exec_pipeline(cmds, pos + 1, fd[0]); /* execute the rest */
	}
  }
}

int main(int argc __attribute__((unused)), char* argv[] __attribute__((unused))) {
  /* `cat file | grep the | more` */
  const char* cmd1[] = { "ls" , "-l", NULL };
  const char* cmd2[] = { "grep", "fork", NULL };
  const char* cmd3[] = { "wc", "-l", NULL };
  const char* const* cmds[] = { cmd1, cmd2, cmd3, NULL };

  //if (signal(SIGCHLD, SIG_IGN) == SIG_ERR) /* POSIX.1-2001 reap children */
   // report_error_and_exit("signal");

  exec_pipeline((char* const**)cmds, 0, STDIN_FILENO);
}
