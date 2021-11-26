/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:24 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:26 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void		help(void)
{
	error_handling(214);
	ft_printf("mkdir <folder>: Create a folder on the server\n");
	ft_printf("ls [OPTIONS] <files>: List file from server\n");
	ft_printf("lls [OPTIONS] <files>: List file from client\n");
	ft_printf("pwd: Get current directory from server\n");
	ft_printf("lpwd: Get current directory from client\n");
	ft_printf("cd: Change current directory from server\n");
	ft_printf("lcd: Change current directory from client\n");
	ft_printf("get <file>: Get a file from server\n");
	ft_printf("get <file> -: print a file from server\n");
	ft_printf("put <file>: Put a file from server\n");
	ft_printf("mget <files>: Get a file(s) from server with globbing or "
		"multiple args\n");
	ft_printf("mput <files>: Put a file(s) from server with globbing or "
		"multiple args\n");
	ft_printf("quit: Quit client\n");
	ft_printf("help: Print this help\n");
	error_handling(211);
}

static int		handle_cmd_auth2(char **tab, t_context *ctx, char *cmd)
{
	if (!ft_strcmp(tab[0], "pwd"))
		return (server_builtin(tab, ctx));
	else if (!ft_strcmp(tab[0], "get"))
		return (send_get(tab, ctx));
	else if (!ft_strcmp(tab[0], "put"))
		return (send_put(tab, ctx, tab[0]));
	else if (!ft_strcmp(tab[0], "mget"))
		return (send_mget(ctx, cmd));
	else if (!ft_strcmp(tab[0], "mput"))
		return (send_mput(ctx, cmd));
	else if (!ft_strcmp(tab[0], "help"))
		help();
	else
		return (error_handling(202));
	return (EXIT_SUCCESS);
}

static int		handle_cmd_auth(char **tab, t_context *ctx, char *cmd)
{
	if (!ft_strcmp(tab[0], "lcd"))
		return (builtin_cd(tab, ctx));
	else if (!ft_strcmp(tab[0], "lls"))
		return (send_builtin(tab));
	else if (!ft_strcmp(tab[0], "lpwd"))
		return (send_builtin(tab));
	else if (!ft_strcmp(tab[0], "cd"))
		return (server_builtin(tab, ctx));
	else if (!ft_strcmp(tab[0], "ls"))
		return (server_builtin(tab, ctx));
	else if (!ft_strcmp(tab[0], "mkdir"))
		return (server_builtin(tab, ctx));
	return (handle_cmd_auth2(tab, ctx, cmd));
}

int				handle_cmd(char *cmd, t_context *ctx)
{
	char		**tab;

	if (!(tab = ft_strsplit(cmd, ' ')))
		return (EXIT_FAILURE);
	if (ctx->auth)
	{
		if (!ft_strcmp(tab[0], "login"))
			ft_dprintf(STDERR_FILENO, "Already connected\n");
		else
		{
			if (!ft_strcmp(tab[0], "quit"))
			{
				ft_free_tab(tab);
				return (quit(0, ctx));
			}
			else if (handle_cmd_auth(tab, ctx, cmd) == 202)
				;
		}
	}
	ft_free_tab(tab);
	return (EXIT_SUCCESS);
}
