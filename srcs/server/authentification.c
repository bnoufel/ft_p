/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   authentification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:49 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:52 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int				connection_accepted(t_process *process, int log_fd)
{
	if (open_process_log_file(process, log_fd) || init_process_root(process))
	{
		connection_refused(process, log_fd);
		return (end_process(1, process));
	}
	send(process->sock_fd_client,
			CONNECTION_ACCEPTED, ft_strlen(CONNECTION_ACCEPTED), 0);
	client_command_loop(process);
	return (end_process(0, process));
}

int				connection_refused(t_process *process, int log_fd)
{
	ft_dprintf(log_fd, "connection refused\n");
	send(process->sock_fd_client,
			CONNECTION_REFUSED, ft_strlen(CONNECTION_REFUSED), 0);
	return (0);
}

static char		**split_cmd_auth(t_process *process, int log_fd)
{
	char		**tab;

	if (!(tab = ft_strsplit(process->command, ':')))
	{
		ft_dprintf(log_fd, "strsplit fail\n");
		return (NULL);
	}
	if (ft_tablen(tab) != 2)
	{
		ft_dprintf(log_fd, "login not well formated\n");
		return (NULL);
	}
	ft_dprintf(log_fd, "%s", NEW_CONNECT, tab[0], tab[1]);
	return (tab);
}

static t_user	*get_user(t_user **lst, char *pass_file, int logfd, char **tab)
{
	t_user		*user;

	if (!(*lst = get_pass_file(pass_file)))
	{
		ft_free_tab(tab);
		return (NULL);
	}
	if (!(user = search_user(*lst, tab[0])))
	{
		ft_free_tab(tab);
		free_user_list(lst);
		ft_dprintf(logfd, "login not found\n");
		return (NULL);
	}
	return (user);
}

int				authentification(t_process *process, int logfd, char *filepass)
{
	char		**tab;
	t_user		*list;
	t_user		*user;

	if (!(tab = split_cmd_auth(process, logfd)))
		return (1);
	if (!(user = get_user(&list, filepass, logfd, tab)))
		return (1);
	if (ft_strcmp(user->password, tab[1]))
	{
		ft_free_tab(tab);
		free_user_list(&list);
		ft_dprintf(logfd, "wrong password\n");
		return (1);
	}
	process->login = ft_strdup(tab[0]);
	ft_free_tab(tab);
	free_user_list(&list);
	if (!process->login)
		return (1);
	ft_dprintf(logfd, "%s connection accepted\n", process->login);
	return (0);
}
