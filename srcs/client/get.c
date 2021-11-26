/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:22 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:23 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		free_cmd_and_ret(char *cmd, int ret)
{
	ft_strdel(&cmd);
	return (error_handling(ret));
}

static int		get_accept_file(char **cmd, t_context *ctx, char *check)
{
	uint64_t	len;
	char		*file;
	int			fd;

	fd = (ft_tablen(cmd) == 3 && !ft_strcmp(cmd[2], "-")) ? 1 : -1;
	if (!ft_strncmp(check, REFUSE, ft_strlen(REFUSE)))
		return (error_handling(451));
	len = ft_atoull(check + ft_strlen(ACCEPT) + 1);
	if (!(file = ft_strnew(len + 1)))
		return (error_handling(552));
	if (ft_tablen(cmd) == 2 && (fd = open(get_name_openfile(cmd[1]), O_CREAT |
	O_WRONLY | O_TRUNC, 0644)) == -1)
	{
		ft_strdel(&file);
		error_handling(451);
	}
	if ((recv(ctx->socket, file, len, 0)) == -1)
	{
		ft_strdel(&file);
		return (error_handling(451));
	}
	ft_dprintf(fd, "%s", file);
	ft_strdel(&file);
	ft_tablen(cmd) == 2 ? close(fd) : 0;
	return (error_handling(200));
}

static int		get_file(char **cmd, t_context *ctx)
{
	char		*get_cmd;
	char		check[512];
	size_t		n;

	ft_bzero(check, 512);
	if ((n = ft_asprintf(&get_cmd, "%s %d", cmd[0],
		ft_strlen(cmd[1]))) == -1)
		return (error_handling(552));
	if ((send(ctx->socket, get_cmd, n, 0)) == -1)
		return (free_cmd_and_ret(get_cmd, 451));
	ft_strdel(&get_cmd);
	if ((recv(ctx->socket, check, 512, 0)) == -1)
		return (error_handling(451));
	if (!ft_strcmp(check, ACCEPT))
	{
		if ((n = ft_asprintf(&get_cmd, "%s", cmd[1])) == -1)
			return (error_handling(552));
		if ((send(ctx->socket, get_cmd, n, 0)) == -1)
			return (free_cmd_and_ret(get_cmd, 451));
		ft_strdel(&get_cmd);
		if ((recv(ctx->socket, check, 512, 0)) == -1)
			return (error_handling(451));
		return (get_accept_file(cmd, ctx, check));
	}
	return (error_handling(500));
}

int				send_get(char **cmd, t_context *ctx)
{
	if (ft_tablen(cmd) < 2 || ft_tablen(cmd) > 3)
		return (error_handling(501));
	return (get_file(cmd, ctx));
}
