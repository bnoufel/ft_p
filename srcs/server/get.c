/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:57 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:58 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		fail(t_process *process)
{
	message(process, COMMAND_FAIL);
	return (1);
}

int		ft_send_file_fd(t_process *process, int fd)
{
	t_stat		stat;
	char		*tmp;
	int			len;

	if ((fstat(fd, &stat)) == -1)
		return (fail(process));
	if (S_ISDIR(stat.st_mode))
	{
		message(process, REFUSE);
		return (1);
	}
	if ((ft_asprintf(&tmp, "%s %064llu", ACCEPT, stat.st_size)) == -1)
		return (fail(process));
	message(process, tmp);
	free(tmp);
	if (!(tmp = (char*)malloc(MAX_SEND)))
		return (fail(process));
	while ((len = read(fd, tmp, MAX_SEND)) > 0)
	{
		tmp[len] = '\0';
		message(process, tmp);
	}
	free(tmp);
	return (0);
}

int		ft_send_file(t_process *process, char *file_name)
{
	int	fd;

	if (verif_file_exist(process, file_name))
	{
		message(process, REFUSE);
		return (1);
	}
	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		message(process, REFUSE);
		return (1);
	}
	ft_send_file_fd(process, fd);
	close(fd);
	return (0);
}

int		ft_get(t_process *process, char **command)
{
	char	*file_name;
	int		n;
	int		len;

	len = ft_atoi(command[1]);
	if (ft_tablen(command) != 2 || !(file_name = (char*)malloc(len + 1)))
		return (fail(process));
	message(process, ACCEPT);
	if ((n = recv(process->sock_fd_client, file_name, len, 0)) == -1)
	{
		free(file_name);
		return (fail(process));
	}
	file_name[n] = '\0';
	ft_send_file(process, file_name);
	free(file_name);
	return (0);
}
