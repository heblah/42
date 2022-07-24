/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:40:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/22 10:48:06 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FDF_H
# define T_FDF_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <string.h>
# include "../libft/libft/libft.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/printf/ft_printf.h"

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080
# define MLX_ERROR 		-1
# define BACKGROUND 	0x2F4F4F
# define ORANGE 		0xFF8C00

/* t_img ==================================================================== */
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/* t_data =================================================================== */
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		color;
}	t_data;

/* t_map : map into chained list before matrix ============================== */
typedef struct s_map
{
	int				*x;
	int				width;
	struct s_map	*next;
}					t_map;

/* t_matrix :  into chained list before matrix ============================== */
typedef struct s_matrix
{
	int	**pxl;
	int	row;
	int	col;
}		t_matrix;
#endif
