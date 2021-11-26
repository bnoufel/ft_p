/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:07 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:10 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char		*get_log_file(int log_fd)
{
	time_t		time_var;
	char		*log_file;

	time_var = time(NULL);
	if (!(log_file = ctime(&time_var)))
	{
		ft_dprintf(log_fd, "ERROR: ctime fail\n");
		return (NULL);
	}
	if (!(log_file = ft_strsub(log_file, 4, 20)))
	{
		ft_dprintf(log_fd, "ERROR: ft_strsub fail\n");
		return (NULL);
	}
	return (log_file);
}

int				open_process_log_file(t_process *process, int log_fd)
{
	char		*log_file;
	char		*tmp;

	if (!(log_file = get_log_file(log_fd)))
		return (1);
	if ((ft_asprintf(&(process->tmp_file), "%s.%s_tmp",
					process->log_file, process->login) == -1)
	|| (ft_asprintf(&tmp, "%s%s%s", process->log_file,
					process->login, log_file)) == -1)
	{
		free(log_file);
		ft_dprintf(log_fd, "ERROR: ft_asprintf fail\n");
		return (3);
	}
	free(log_file);
	free(process->log_file);
	process->log_file = tmp;
	if (!(process->log_fd = open(process->log_file,
									O_CREAT | O_WRONLY | O_TRUNC, 0755)))
	{
		ft_dprintf(log_fd, "ERROR: open %s fail\n", log_file);
		return (6);
	}
	return (0);
}

static void		end_server(int n)
{
	n = 0;
	exit(1);
}

int				open_log_n_signal(t_context *ctx, int *log_fd)
{
	if (open_log_fd(ctx, log_fd))
		return (1);
	signal(SIGCHLD, SIG_IGN);
	signal(SIGTERM, end_server);
	return (0);
}
