/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:30 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:31 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int		init_process_struct(t_process **process, t_context *ctx)
{
	(*process)->pwd = NULL;
	(*process)->root = NULL;
	(*process)->login = NULL;
	(*process)->tmp_file = NULL;
	(*process)->command_len = sizeof(t_sockaddr);
	if ((ft_asprintf(&((*process)->log_file), "%s/", ctx->log_folder)) == -1)
		return (1);
	if ((ft_asprintf(&((*process)->pwd), "%s/", ctx->root)) == -1)
		return (1);
	return (0);
}

static	void	*free_and_quit_process(int log, char *msg, t_process *process)
{
	if (process)
		free_process(process);
	if (msg)
		ft_dprintf(log, "%s", msg);
	return (NULL);
}

t_process		*new_process(t_context *ctx, int log_fd)
{
	t_process	*process;
	short		len;

	ft_dprintf(log_fd, "new_process\n");
	if (!(process = (t_process *)malloc(sizeof(t_process))))
		return (free_and_quit_process(log_fd, "ERROR: malloc error\n", NULL));
	if (init_process_struct(&process, ctx))
		return (free_and_quit_process(log_fd, NULL, process));
	if ((process->sock_fd_client = accept(ctx->sock_fd_server,
	(struct sockaddr *)&(process->sockaddr_client),
	&(process->command_len))) == -1)
	{
		free_process(process);
		ft_dprintf(log_fd, "ERROR: accept fail\n");
		return (NULL);
	}
	if ((len = (recv(process->sock_fd_client, process->command, 512, 0))) == -1)
	{
		free_process(process);
		ft_dprintf(log_fd, "ERROR: recv fail\n");
		return (NULL);
	}
	process->command[len] = '\0';
	return (process);
}

int				open_log_fd(t_context *ctx, int *fd)
{
	char		*tmp;

	if (!(tmp = ft_strjoin("/", GLOBAL_LOGS)))
	{
		ft_printf("ERROR: strjoin fail\n");
		return (1);
	}
	if (!(tmp = ft_strjoinfree(ctx->log_folder, tmp, 2)))
	{
		ft_printf("ERROR: strjoinfree fail\n");
		return (1);
	}
	if ((*fd = open(tmp, O_CREAT | O_WRONLY | O_TRUNC, 0755)) < 0)
	{
		ft_printf("ERROR: can not write in %s\n", tmp);
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

int				server(t_context *ctx)
{
	t_process	*process;
	int			process_id;
	int			log_fd;

	if (open_log_n_signal(ctx, &log_fd))
		return (1);
	while (1)
	{
		if (!(process = new_process(ctx, log_fd)))
			return (1);
		if (!authentification(process, log_fd, ctx->pass_file))
		{
			process_id = fork();
			if (process_id < 0)
				ft_dprintf(log_fd, "ERROR: fork fail\n");
			else if (process_id == 0)
			{
				free_ctx(ctx);
				return (connection_accepted(process, log_fd));
			}
		}
		else
			connection_refused(process, log_fd);
		free_process(process);
	}
}
