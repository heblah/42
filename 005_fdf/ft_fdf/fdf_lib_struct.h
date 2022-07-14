/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lib_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:40:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/07/13 18:05:03 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LIB_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
//# include <mlx.h>
# include <sys/types.h>
# include <string.h>
# include "../libft/libft/libft.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/printf/ft_printf.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define MLX_ERROR -1

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
}	t_data;

/* t_imgtmp : map into chained list before **int============================= */
typedef struct s_map
{
	int				*x;
	int				width;
	struct s_map	*next;
}					t_map;
#endif
