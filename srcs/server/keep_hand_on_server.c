/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_hand_on_server.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:04 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:07 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		catch_ctrl_c(int n)
{
	n = 0;
}

static void		server_command_help(void)
{
	ft_printf("-quit:        stop the server\n");
	ft_printf("-newuser:     add user for connection\n");
	ft_printf("-deleteuser:  delete an user\n");
	ft_printf("-showuser:    print user list\n");
	ft_printf("-help:        show the help\n");
}

static int		command_from_server(t_context *ctx)
{
	char	buf[512];
	int		len;

	while ((len = read(STDIN_FILENO, &buf, 512)) > 0)
	{
		buf[len - 1] = '\0';
		if (!ft_strcmp("newuser", buf))
			newuser(ctx);
		else if (!ft_strcmp("deleteuser", buf))
			deleteuser(ctx);
		else if (!ft_strcmp("showuser", buf))
			showuser(ctx->user_list);
		else if (!ft_strcmp("help", buf))
			server_command_help();
		else if (!ft_strcmp("quit", buf))
			break ;
		else
			ft_dprintf(2, "unknow command type \"help\" for help...\n");
		write(1, "$ ", 2);
	}
	if (kill(ctx->server_pid, SIGTERM) == -1)
		kill(ctx->server_pid, 9);
	ctx->end = 1;
	return (0);
}

int				keep_hand_on_server(t_context *ctx)
{
	int			father;

	if ((father = fork()) < 0)
	{
		ft_dprintf(2, "ERROR: fork fail\n");
		return (1);
	}
	if (father == 0)
		return (0);
	if (!(ctx->user_list = get_pass_file(ctx->pass_file)))
		return (1);
	signal(2, catch_ctrl_c);
	ctx->server_pid = father;
	write(1, "$ ", 2);
	command_from_server(ctx);
	free_user_list(&ctx->user_list);
	ft_printf("server end\n");
	return (0);
}
