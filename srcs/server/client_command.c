/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:54 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:55 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	message(t_process *process, char *str)
{
	ft_dprintf(process->log_fd, "send: %s\n", str);
	send(process->sock_fd_client, str, ft_strlen(str), 0);
}

int		ft_dispatcher(t_process *process, char **command)
{
	if (!command[1] && !ft_strcmp(command[0], "pwd"))
		ft_pwd(process);
	else if (!command[1] && !ft_strcmp(command[0], "quit"))
	{
		ft_quit(process);
		return (1);
	}
	else if (!ft_strcmp(command[0], "cd") && command[1])
		ft_cd(process, command);
	else if (!ft_strcmp(command[0], "ls") && command[1])
		ft_ls(process, command);
	else if (!ft_strcmp(command[0], "get") && command[1])
		ft_get(process, command);
	else if (!ft_strcmp(command[0], "put") && command[1])
		ft_put(process, command);
	else if (!ft_strcmp(command[0], "mkdir") && command[1])
		ft_mkdir(process, command);
	else if (!ft_strcmp(command[0], "mget") && command[1])
		ft_mget(process, command);
	else
		message(process, UNKNOW_COMMAND);
	return (0);
}

void	client_command_loop(t_process *proces)
{
	char	**tab;
	ssize_t	n;

	tab = NULL;
	while (1)
	{
		ft_bzero(proces->command, 512);
		if (tab)
			ft_free_tab(tab);
		ft_dprintf(proces->log_fd, "waiting command...\n");
		if ((n = recv(proces->sock_fd_client, proces->command, 512, 0)) == -1)
		{
			ft_dprintf(proces->log_fd, "%s", RECV_FAIL);
			return ;
		}
		proces->command[n] = '\0';
		ft_dprintf(proces->log_fd, "%s\n", proces->command);
		if (!(tab = ft_strsplit(proces->command, ' ')))
		{
			ft_dprintf(proces->log_fd, "ERROR: strsplit failt\n");
			return ;
		}
		if (!tab[0] || ft_dispatcher(proces, tab))
			return ;
	}
}
