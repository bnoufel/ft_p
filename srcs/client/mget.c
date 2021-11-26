/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mget.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:28 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:29 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int		open_and_write_files(t_context *ctx, char *name)
{
	char		len[128];
	int			fd;
	char		*file;
	uint64_t	file_len;

	ft_bzero(len, 128);
	if (recv(ctx->socket, len, 64 + ft_strlen(ACCEPT) + 1, 0) == -1
	|| ft_strncmp(ACCEPT, len, ft_strlen(ACCEPT))
	|| (fd = open(get_name_openfile(name), O_WRONLY | O_CREAT, 0755)) == -1)
		return (error_handling(451));
	file_len = ft_atoull(len + ft_strlen(ACCEPT) + 1);
	if (!(file = ft_strnew(file_len)))
	{
		close(fd);
		return (error_handling(552));
	}
	if (recv(ctx->socket, file, file_len, 0) == -1)
	{
		close(fd);
		return (error_handling(451));
	}
	write(fd, file, file_len);
	close(fd);
	ft_strdel(&file);
	return (200);
}

/*
** check sur chaque fichier si je ne reçois pas ACCEPT, dans ce cas la une
** erreur est retournée
** @param ctx
** @param nb_arg
** @return
*/

static int		get_files(t_context *ctx, uint64_t nb_arg)
{
	uint64_t	name_len;
	char		tmp[256];
	int32_t		len;

	while (nb_arg--)
	{
		if ((len = recv(ctx->socket, tmp, 64, 0)) == -1)
			continue ;
		tmp[len] = '\0';
		name_len = ft_atoull(tmp);
		if ((len = recv(ctx->socket, tmp, name_len, 0)) == -1)
			continue ;
		tmp[len] = '\0';
		open_and_write_files(ctx, tmp);
	}
	return (error_handling(200));
}

static int		send_mget_cmd(t_context *ctx, char *cmd)
{
	char		tmp[512];
	uint64_t	nb_arg;

	ft_bzero(tmp, 512);
	if (send(ctx->socket, cmd, ft_strlen(cmd), 0) == -1)
		return (error_handling(451));
	if (recv(ctx->socket, tmp, 64, 0) == -1)
		return (error_handling(451));
	if (ft_strcmp(tmp, ACCEPT))
	{
		nb_arg = ft_atoull(tmp);
		return (get_files(ctx, nb_arg));
	}
	return (error_handling(451));
}

int				send_mget(t_context *ctx, char *cmd)
{
	char		*str;
	int32_t		len;
	char		tmp[512];

	ft_bzero(tmp, 512);
	if ((len = ft_asprintf(&str, "mget %llu", ft_strlen(cmd))) == -1)
		return (error_handling(552));
	if (send(ctx->socket, str, len, 0) == -1)
	{
		ft_strdel(&str);
		return (error_handling(451));
	}
	ft_strdel(&str);
	if ((len = recv(ctx->socket, tmp, ft_strlen(ACCEPT), 0)) == -1)
	{
		return (error_handling(451));
	}
	if (!ft_strcmp(tmp, ACCEPT))
		return (send_mget_cmd(ctx, cmd));
	return (error_handling(451));
}
