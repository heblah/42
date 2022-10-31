/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:11:09 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/31 17:07:40 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MINISHELL_H
# define T_MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "ft_libft.h"
# include <dirent.h>
# include <string.h>
# include <errno.h> /* for perror*/

/* typedef definitions ====================================================== */
typedef int		t_flag;

/* Lexer structure ========================================================== */
typedef struct s_lexer
{
	t_flag			type;
	t_state			state;
	char			*first;
	struct s_lexer	*next;
}				t_lexer;

/* Lexer enum to determine type ============================================= */
typedef enum e_token
{
	C_NULL = 0,
	C_WORD,
	C_PIPE,
	C_AMPERSAND,
	C_REDIR_IN,
	C_REDIR_OUT,
	C_SQUOTE,
	C_DQUOTE,
	C_DOLLAR,
	C_DELIMITER ,
	/* bonus token */
	C_AND,
	C_OR,
	C_WILDCARD
}	t_token;

/* fd enum for input (read) and output (write) ============================== */
typedef enum e_fdio
{
	READ = 0,
	WRITE,
}	t_fdio;

/* Structure of the command line ============================================ */
typedef struct s_lst
{
	char			**cmds;
	struct s_lst	*back;
	struct s_lst	*next;
}					t_lst;

/* Data minishell structure ================================================= */
typedef struct s_data
{
	/* Input command  */
	char	*input;

	/* Errors management */

	/* Directories management */
	char	*prv_dir;
	char	*cur_dir;

	/* Commands management */
	t_token	*token;
	t_lst	*lst_cmds;
}			t_data;
#endif
