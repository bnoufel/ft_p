/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:20 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:21 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int		ft_put_fourth(t_process *process,
					char *buf, uint64_t *file_len, int new_file)
{
	int			len;

	if (*file_len > MAX_SEND)
	{
		if ((len = recv(process->sock_fd_client, buf, MAX_SEND, 0) == -1))
		{
			message(process, COMMAND_FAIL);
			return (1);
		}
	}
	else
	{
		if ((len = recv(process->sock_fd_client, buf, *file_len, 0)) == -1)
		{
			message(process, COMMAND_FAIL);
			return (1);
		}
	}
	ft_dprintf(process->log_fd, "writing %d bytes in the file\n", len);
	write(new_file, buf, len);
	*file_len -= (unsigned long long)len;
	return (0);
}

static void		ft_put_third(t_process *process, uint64_t len, int new_file)
{
	char		*buf;

	if (!(buf = (char *)malloc(MAX_SEND)))
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	message(process, ACCEPT);
	while (len != 0)
	{
		if (ft_put_fourth(process, buf, &len, new_file))
		{
			free(buf);
			return ;
		}
		message(process, ACCEPT);
	}
	free(buf);
}

void			ft_put_second(t_process *process, char **command, char *file)
{
	int			new_file;

	if ((recv(process->sock_fd_client, file, ft_atoi(command[1]), 0)) == -1)
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	ft_dprintf(process->log_fd, "file name: %s\nlen: %llu\n",
			file, ft_atoull(command[2]));
	if (verif_file_exist(process, file) && verif_can_be_created(process, file))
	{
		message(process, REFUSE);
		return ;
	}
	if ((new_file = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0)
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	ft_put_third(process, ft_atoull(command[2]), new_file);
	close(new_file);
}

void			ft_put(t_process *process, char **command)
{
	char		*file_name;
	int			len;

	file_name = NULL;
	len = ft_atoi(command[1]);
	if (ft_tablen(command) != 3 || !(file_name = ft_strnew(len + 1)))
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	message(process, ACCEPT);
	ft_put_second(process, command, file_name);
	free(file_name);
}
