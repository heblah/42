/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:11:09 by halvarez          #+#    #+#             */
/*   Updated: 2022/10/28 17:02:55 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_MINIHSELL_H
# define T_MINIHSELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include "ft_libft.h"
# include <dirent.h>
# include <string.h>
# include <errno.h> /* for perror*/

/* t_flag definition ======================================================== */
typedef int	t_flag;

/* Lexer structure ========================================================== */
typedef struct s_lexer
{
	t_flag			type;
	//t_quote			nb_quote; /* utile ??*/
	char			*first;
	struct s_lexer	*next;
}				t_lexer;

/* Lexer enum to determine type ============================================= */
typedef enum	e_token
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
	C_DELIMITER,
	/* bonus token */
	C_AND,
	C_OR,
	C_WILDCARD
}				t_token;

/* Structure of the commands list =========================================== */
typedef struct s_lst
{
	char			**cmd;
	struct s_lst	*next;
}				t_lst;

/* Data minishell structure ================================================= */
typedef struct	s_data
{
	/* Input command  */
	char	*input;

	/* Errors management */

	/* Directories management */
	char	*prv_dir;
	char	*cur_dir;

	/* Commands management */
	t_lst	*lst_cmds;
}				t_data;
#endif
