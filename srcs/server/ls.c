/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:10 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:12 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		exec_ls_cmd(t_process *process, char *path)
{
	int			fd;
	char		*ls_com;

	ls_com = NULL;
	if ((fd = open(process->tmp_file,
	O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1
	|| !(ls_com = ft_strjoin("ls ", path))
	|| dup2(fd, 1) == -1
	|| execl("/bin/sh", "/bin/sh", "-c", ls_com, NULL) == -1)
	{
		ft_strdel(&ls_com);
		dup2(1, fd);
		close(fd);
		execl("/bin/rm", "/bin/rm", "-f", process->tmp_file, NULL);
		exit(1);
	}
	free(ls_com);
	dup2(1, fd);
	close(fd);
	exit(0);
}

static int		open_tmp_file(t_process *process)
{
	int			fd;

	if ((fd = open(process->tmp_file, O_RDONLY)) < 0)
	{
		message(process, COMMAND_FAIL);
		return (1);
	}
	ft_send_file_fd(process, fd);
	close(fd);
	return (0);
}

static int		get_ls_file(t_process *process, char *path, int cmd_len)
{
	int			pid;

	if ((recv(process->sock_fd_client, path, cmd_len, 0)) == -1)
	{
		message(process, COMMAND_FAIL);
		return (1);
	}
	if (verif_dir(process, path) && verif_file_exist(process, path))
	{
		message(process, REFUSE);
		return (1);
	}
	if ((pid = fork()) == -1)
	{
		message(process, REFUSE);
		return (1);
	}
	else if (!pid)
		exec_ls_cmd(process, path);
	else
		wait4(0, NULL, 0, NULL);
	return (open_tmp_file(process));
}

int				ft_ls(t_process *process, char **command)
{
	char		*name;
	int			ret;
	int			len;

	len = ft_atoi(command[1]);
	if (ft_tablen(command) != 2 || !(name = ft_strnew(len + 1)))
	{
		message(process, COMMAND_FAIL);
		return (1);
	}
	message(process, ACCEPT);
	ret = get_ls_file(process, name, len);
	free(name);
	return (ret);
}
