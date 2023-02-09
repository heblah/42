/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:43:06 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/22 11:15:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MINISHELL_H
# define T_MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "ft_libft.h"
# include <dirent.h>
# include <string.h>
# include <errno.h> /* for perror*/

/* ========================================================================== */
/*			enums                                                             */
/* ========================================================================== */
/* Lexer enum to determine type ============================================= */
typedef enum e_token
{
	C_WORD = -1,
	C_NULL = '\0',
	C_PIPE = '|',
	C_AMPERSAND = '&',
	C_INF = '<',
	C_SUP = '>',
	C_DOLLAR = '$',
	C_SQUOTE = '\'',
	C_DQUOTE = '\"',
	C_SPACE = ' ',
	C_WILDCARD = '*'
}	t_token;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef enum e_state
{
	S_PIPE = 0,
	S_SEP,
	S_SINQUOTE,
	S_DINQUOTE,
	S_SUP,
	S_INF,
	S_VAR,
	S_GENERAL,
}	t_state;

/* fd enum for input (read) and output (write) ============================== */
typedef enum e_fdio
{
	READ = 0,
	WRITE,
}	t_fdio;

/* enum for lexing array ==================================================== */
typedef enum e_lex
{
	INPUT = 0,
	TOKEN,
	STATE
}	t_lex;

/* enum for memory management =============================================== */
typedef enum e_label
{
	LEXER,
	PARSE,
	EXECV,
	INIT,
	LIBFT,
	OTHER,
	NOTHING
}	t_label;

typedef enum e_mem_t
{
	MALLOC,
	FREE,
	PURGE,
	LABEL
}	t_mem_t;

/* ========================================================================== */
/*			structures                                                        */
/* ========================================================================== */
/* Structure of the lexer =================================================== */
typedef struct s_lexer
{
	int		**tab;
	size_t	len;
}			t_lexer;

/* Execution structure for pipes ============================================ */
typedef struct s_lst
{
	char			**cmd;
	int				fd_in;
	int				fd_out;
	t_bool			exec;
	t_bool			internal;
	struct s_lst	*next;
}					t_lst;

/* Garbage collector structure ============================================== */
typedef struct s_garbage
{
	void				*address;
	t_label				label;
	struct s_garbage	*next;
}					t_garbage;

/* Data minishell structure ================================================= */
typedef struct s_data
{
	t_lexer		*lexer;
	size_t		*parser;
	t_lst		*cmd_lst;
	t_lst		*env;
	t_lst		*buf;
	t_garbage	*garbage;
	int			status;
	int			instance;
	t_bool		run;
	t_bool		isminishell;
	t_bool		heredoc;
}			t_data;
#endif
