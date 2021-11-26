/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:12 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:13 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			free_ctx(t_context *ctx)
{
	if (ctx && ctx->end)
	{
		free_user_list(&(ctx->user_list));
		ft_strdel(&(ctx->root));
		ft_strdel(&(ctx->pass_file));
		ft_strdel(&(ctx->log_folder));
		ft_strdel(&(ctx->error));
		close(ctx->sock_fd_server);
		ctx->end = 0;
		free(ctx);
		ctx = NULL;
	}
}

int				main(int ac, char **av)
{
	t_context	*ctx;

	if (ac != 2)
	{
		ft_dprintf(2, "Usage: %s <port>\n", av[0]);
		return (1);
	}
	if (!(ctx = (t_context *)malloc(sizeof(t_context))))
		return (1);
	if (init_struct(av[1], ctx)
			|| keep_hand_on_server(ctx))
		return (1);
	if (ctx && !ctx->end)
		server(ctx);
	if (ctx && ctx->error)
	{
		write(2, ctx->error, ft_strlen(ctx->error));
		free_ctx(ctx);
		return (4);
	}
	free_ctx(ctx);
	return (0);
}
