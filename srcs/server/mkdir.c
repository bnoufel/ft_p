/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mkdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:15 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:16 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		create_folder(t_process *process, char *new_dir_name, int len)
{
	int64_t		n;

	if ((n = recv(process->sock_fd_client, new_dir_name, len, 0)) == -1)
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	new_dir_name[n] = '\0';
	if (verif_can_be_created(process, new_dir_name))
	{
		message(process, REFUSE_403);
		return ;
	}
	if (mkdir(new_dir_name, 0755) && errno != EEXIST)
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	message(process, ACCEPT);
}

void			ft_mkdir(t_process *process, char **command)
{
	char	*new_dir_name;
	int		len;

	len = ft_atoi(command[1]);
	if (ft_tablen(command) != 2 || !(new_dir_name = ft_strnew(len + 1)))
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	message(process, ACCEPT);
	create_folder(process, new_dir_name, len);
	free(new_dir_name);
}
