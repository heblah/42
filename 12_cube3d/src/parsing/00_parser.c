/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:43:14 by halvarez          #+#    #+#             */
/*   Updated: 2023/03/14 22:21:53 by halvarez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_cube3d.h"
#include "ft_cube3d.h"

static t_bool	check_extension(char *ext, char *file)
{
	int	len_ext;
	int	len_file;

	len_ext = ft_strlen(ext);
	len_file = ft_strlen(file);
	while (len_file && file[len_file - 1] == ' ')
		file[--len_file] = '\0';
	if (!len_ext || !len_file
		|| ft_strncmp(ext, file + len_file - len_ext, len_ext) != 0)
		return (false);
	return (true);
}

static int	openfile(char *path2file, char *ext)
{
	int	fd;

	if (ext != NULL && check_extension(ext, path2file) == false)
		return (-1);
	fd = open(path2file, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
	{
		fd = open(path2file, O_RDONLY);
		if (fd == -1)
			return (-1);
	}
	else
	{
		if (close(fd) == -1)
			return (ft_putstr_fd("Error: closing the file", 2),
				ft_putstr_fd(path2file, 2),
				ft_putstr_fd(".\n", 2), -1);
		else
			return (-1);
	}
	return (fd);
}

void	*get_texture(char *path, t_img *img)
{
	int		fd;

	while (path && *path && *path == ' ')
		path++;
	fd = openfile(path, ".xpm");
	if (check_extension(".xpm", path) == true && fd != -1)
	{
		if (close(fd) == -1)
		{
			ft_putstr_fd("Error: closing the file", 2);
			ft_putstr_fd(path, 2);
			ft_putstr_fd(".\n", 2);
		}
		img->path = ft_strdup(path);
		return (memg(MALLOC, 0, img->path, PARSE), img->path);
	}
	else if (check_extension(".xpm", path) == false)
		ft_putstr_fd("Error : texture has to be in xpm format.\n", 2);
	return (NULL);
}

t_color	getcolor(char *color_txt)
{
	t_color	color;
	int		red;
	int		green;
	int		blue;

	color.rgb = UINT_MAX;
	while (*color_txt && *color_txt == ' ')
		color_txt++;
	if (checkrgb(color_txt) == false)
		return (ft_putstr_fd("", 2), color);
	red = ft_atoi(color_txt);
	while (*color_txt && *color_txt != ',')
		color_txt++;
	green = ft_atoi(++color_txt);
	while (*color_txt && *color_txt != ',')
		color_txt++;
	blue = ft_atoi(++color_txt);
	if (red < 0 || green < 0 || blue < 0
		|| red > 255 || green > 255 || blue > 255)
		return (ft_putstr_fd("Error : wrong format color.\n", 2), color);
	color.rgb = 0;
	return (color.red = red, color.green = green, color.blue = blue, color);
}

int	parser(t_data *data, char *path2map)
{
	int		fd;
	char	*gnl;

	fd = openfile(path2map, ".cub");
	if (fd == -1)
		return (ft_putstr_fd("Error : invalid map.\n", 2), -1);
	gnl = rm_nl(get_next_line(fd));
	while (gnl != NULL)
	{
		memg(MALLOC, 0, gnl, PARSE);
		if (*gnl >= 'A' && *gnl <= 'Z')
			getmapdata(data, gnl);
		else if (*gnl == '1' || *gnl == ' ' || *gnl == '\t')
			list_addback(&data->map_tmp, gnl);
		gnl = rm_nl(get_next_line(fd));
	}
	if (convertmap(data, data->map_tmp) == false)
		return (ft_putstr_fd("Error : wrong map format.\n", 2), -1);
	if (checkparsing(data) == false)
		return (-1);
	data->fd = fd;
	return (fd);
}
