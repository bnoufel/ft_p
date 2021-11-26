/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_auth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:18 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:19 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		free_process(t_process *process)
{
	if (process)
	{
		ft_strdel(&process->pwd);
		ft_strdel(&process->root);
		ft_strdel(&process->login);
		ft_strdel(&process->log_file);
		ft_strdel(&process->tmp_file);
		close(process->sock_fd_client);
		free(process);
	}
}

int			end_process(int to_return, t_process *process)
{
	free_process(process);
	return (to_return);
}

int			init_process_root(t_process *process)
{
	if ((ft_asprintf(&process->root, "%s%s/",
						process->pwd, process->login)) == -1)
		return (1);
	if (mkdir(process->root, 0755) && errno != EEXIST)
	{
		ft_dprintf(2, "ERROR: can not create %s\n", process->root);
		return (1);
	}
	if (chdir(process->root))
	{
		ft_dprintf(2, "ERROR: can not move to %s\n", process->root);
		return (1);
	}
	free(process->pwd);
	if (!(process->pwd = getcwd(NULL, 0)))
		return (1);
	ft_dprintf(process->log_fd, "root: %s\n", process->root);
	return (0);
}
