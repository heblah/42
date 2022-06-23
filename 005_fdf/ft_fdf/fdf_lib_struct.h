/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_lib_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:40:00 by halvarez          #+#    #+#             */
/*   Updated: 2022/06/23 16:52:41 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_LIB_H
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <mlx.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR -1

/* structures =============================================================== */
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

#endif
