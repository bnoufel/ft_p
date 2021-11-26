/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:01 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:03 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static uint16_t	verif_port(char *str)
{
	int			i;
	uint16_t	nb;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_dprintf(2, PORT_DIGIT_ERROR);
			return (0);
		}
	}
	if (i >= 7 || (nb = ft_atoi(str)) > 65535)
	{
		ft_dprintf(2, PORT_ERROR);
		return (0);
	}
	return (nb);
}

static int		open_server_fd(t_context *ctx)
{
	ctx->sockaddr_server.sin_port = htons(ctx->port);
	ctx->sockaddr_server.sin_family = AF_INET;
	ctx->sockaddr_server.sin_addr.s_addr = INADDR_ANY;
	ctx->sock_fd_server = socket(AF_INET, SOCK_STREAM, 0);
	if (ctx->sock_fd_server == -1)
	{
		ft_dprintf(2, SOCKET_ERROR);
		return (1);
	}
	if ((bind(ctx->sock_fd_server,
	(struct sockaddr *)&(ctx->sockaddr_server),
	sizeof(t_sockaddr))) == -1)
	{
		ft_dprintf(2, BIND_ERROR);
		return (1);
	}
	if (listen(ctx->sock_fd_server, BACKLOG) == -1)
	{
		ft_dprintf(2, LISTEN_ERROR);
		return (1);
	}
	return (0);
}

static void		print_init_info(t_context *ctx)
{
	uint32_t		address;

	address = 0;
	ft_printf("address: %d.%d.%d.%d\nport: %hu\n",
		address & 0xff,
		(address >> 8) & 0xff,
		(address >> 16) & 0xff,
		(address >> 24) & 0xff,
		ctx->port);
}

int				create_root(t_context *ctx)
{
	char	*tmp;
	int		n;

	n = -42;
	if (mkdir(SERVER_FOLDER, 0755) && errno != EEXIST)
		n = ft_dprintf(2, "ERROR: can not create %s\n", SERVER_FOLDER);
	if (chdir(SERVER_FOLDER))
		n = ft_dprintf(2, "ERROR: can not move to %s\n", SERVER_FOLDER);
	if (!(ctx->root = getcwd(NULL, 0)))
		n = ft_dprintf(2, "ERROR: getcwd fail\n");
	if (!(tmp = ft_strjoin("/", PASSWORDS)))
		n = ft_dprintf(2, "ERROR: strjoin fail\n");
	if (!(ctx->pass_file = ft_strjoinfree(ctx->root, tmp, 2)))
		n = ft_dprintf(2, "ERROR: strjoinfree fail\n");
	if (!(tmp = ft_strjoin("/", SERVER_LOGS)))
		n = ft_dprintf(2, "ERROR: strjoin fail\n");
	if (!(ctx->log_folder = ft_strjoinfree(ctx->root, tmp, 2)))
		n = ft_dprintf(2, "ERROR: strjoinfree fail\n");
	if (mkdir(ctx->log_folder, 0755) && errno != EEXIST)
		n = ft_dprintf(2, "ERROR: can not create %s\n", ctx->log_folder);
	if (n != -42)
		return (1);
	return (0);
}

int				init_struct(char *str, t_context *ctx)
{
	if (!(ctx->port = verif_port(str)))
		return (1);
	ctx->user_list = NULL;
	ctx->root = NULL;
	ctx->pass_file = NULL;
	ctx->log_folder = NULL;
	ctx->error = NULL;
	ctx->end = 0;
	if (create_root(ctx))
		return (1);
	print_init_info(ctx);
	return (open_server_fd(ctx));
}
