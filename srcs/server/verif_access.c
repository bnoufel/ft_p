/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:37 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:38 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char		*format_path(t_process *process, char *path)
{
	char		*new_path;

	new_path = NULL;
	if (!process || !path)
		return (NULL);
	if (path[0] == '/')
		new_path = ft_strdup(path);
	else if (!ft_strncmp(path, "~/", 2))
		ft_asprintf(&new_path, "%s/%s", process->root, &(path[2]));
	else
		ft_asprintf(&new_path, "%s/%s", process->pwd, path);
	return (new_path);
}

static int		verif_dir_access(t_process *process, char *dir)
{
	char		*tmp_path;
	int			ret;

	if ((chdir(dir) == -1))
		return (1);
	if (!(tmp_path = ft_strjoinfree(getcwd(NULL, 0), "/", 1)))
	{
		chdir(process->pwd);
		return (1);
	}
	chdir(process->pwd);
	ft_dprintf(process->log_fd, "asking access to: %s\n", tmp_path);
	ret = 0;
	if (ft_strncmp(process->root, tmp_path, ft_strlen(process->root)))
		ret = 1;
	free(tmp_path);
	if (ret == 0)
		ft_dprintf(process->log_fd, "acces granted\n");
	else
		ft_dprintf(process->log_fd, "acces refused\n");
	return (ret);
}

int				verif_dir(t_process *process, char *dir)
{
	char		*path;
	int			ret;

	if (!(path = format_path(process, dir)))
		return (1);
	ret = verif_dir_access(process, path);
	free(path);
	return (ret);
}

int				verif_file_exist(t_process *process, char *file)
{
	char		*path;
	t_stat		stat;
	int			fd;
	int			ret;

	if (!(path = format_path(process, file)))
		return (1);
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		free(path);
		return (1);
	}
	if (fstat(fd, &stat) == -1 || S_ISDIR(stat.st_mode))
	{
		close(fd);
		free(path);
		return (1);
	}
	close(fd);
	*(ft_strrchr(path, '/') + 1) = '\0';
	ret = verif_dir_access(process, path);
	free(path);
	return (ret);
}

int				verif_can_be_created(t_process *process, char *file)
{
	char		*path;
	int			fd;
	int			ret;

	if (!(path = format_path(process, file)))
		return (1);
	if ((fd = open(path, O_RDONLY)) >= 0)
	{
		free(path);
		return (1);
	}
	*(ft_strrchr(path, '/') + 1) = '\0';
	ret = verif_dir_access(process, path);
	free(path);
	return (ret);
}
