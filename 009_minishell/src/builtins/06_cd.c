/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:28:12 by halvarez          #+#    #+#             */
/*   Updated: 2022/12/14 16:42:05 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_minishell.h"
#include "ft_minishell.h"

static char	*get_homepath(char *new_path)
{
	char	*path;

	if (access("/mnt/nfs/homes/awallet", R_OK) == 0)
	{
		path = ft_strjoin("/mnt/nfs/homes/awallet", new_path + 1);
		if (path == NULL)
			return (NULL);
		return (memg(MALLOC, 0, path, EXECV), path);
	}
	else if (access("/mnt/nfs/homes/halvarez", R_OK) == 0)
	{
		path = ft_strjoin("/mnt/nfs/homes/halvarez", new_path + 1);
		if (path == NULL)
			return (NULL);
		return (memg(MALLOC, 0, path, EXECV), path);
	}
	else
		return (NULL);
}

void	export_oldpwd(void)
{
	t_data	*data;
	char	cwd[PATH_MAX];
	char	*oldpwd;

	data = get_data();
	getcwd(cwd, PATH_MAX);
	oldpwd = ft_strjoin("OLDPWD=", cwd);
	memg(MALLOC, 0, oldpwd, OTHER);
	export(data, oldpwd);
}

void	export_pwd(void)
{
	t_data	*data;
	char	cwd[PATH_MAX];
	char	*pwd;

	data = get_data();
	getcwd(cwd, PATH_MAX);
	pwd = ft_strjoin("PWD=", cwd);
	memg(MALLOC, 0, pwd, OTHER);
	export(data, pwd);
}

static void	update_wd(char *old_pwd, char *cwd)
{
	t_data	*data;

	data = get_data();
	old_pwd = ft_strjoin("OLDPWD=", old_pwd);
	memg(MALLOC, 0, old_pwd, OTHER);
	cwd = ft_strjoin("PWD=", cwd);
	memg(MALLOC, 0, cwd, OTHER);
	export(data, cwd);
	export(data, old_pwd);
}

void	cd(char *new_path)
{
	char		*path;
	char		cwd[PATH_MAX];
	char		old_pwd[PATH_MAX];

	getcwd(old_pwd, PATH_MAX);
	if (new_path && ft_strncmp(new_path, "~", 1) != 0
		&& ft_strncmp(new_path, "-", 2) != 0)
	{
		if (chdir(new_path) == -1)
			return (cd_error("No such file or directory\n", new_path));
	}
	else if ((new_path && ft_strncmp(new_path, "~", 1) == 0)
		|| new_path == NULL)
	{
		if (new_path != NULL)
			path = get_homepath(new_path);
		else
			path = get_homepath("\0\0");
		if (path != NULL && chdir(path) == -1)
			return (cd_error("No such file or directory\n", new_path));
	}
	else if (new_path
		&& ft_strncmp(new_path, "-", ft_strlen(new_path) + 1) == 0)
		return (cd_error("Option not implemented.\n", new_path));
	update_wd(old_pwd, getcwd(cwd, PATH_MAX));
}
