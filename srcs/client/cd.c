/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:19 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:20 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	ft_close_cd(int fd, char *new_dir)
{
	ft_strdel(&new_dir);
	if (fd > 0)
		close(fd);
	return (error_handling(451));
}

static int	change_to_home_or_old(t_context *ctx)
{
	char	*new_dir;
	t_stat	st;
	int		fd;

	if (!(new_dir = ft_strdup(ctx->home)))
	{
		ft_dprintf(STDERR_FILENO, "%s doesn't exist\n", new_dir);
		return (2);
	}
	if ((fd = open(new_dir, O_RDONLY)) == -1)
		return (ft_close_cd(-1, new_dir));
	if (fstat(fd, &st) == -1)
		return (ft_close_cd(fd, new_dir));
	close(fd);
	if (!S_ISDIR(st.st_mode) || chdir(new_dir) == -1)
	{
		ft_strdel(&new_dir);
		return (error_handling(451));
	}
	ft_strdel(&new_dir);
	return (error_handling(212));
}

static int	change_dir(char *new)
{
	t_stat	st;
	int		fd;

	if ((fd = open(new, O_RDONLY)) == -1)
		return (ft_close_cd(-1, NULL));
	if (fstat(fd, &st) == -1)
		return (ft_close_cd(fd, NULL));
	close(fd);
	if (!S_ISDIR(st.st_mode))
		return (error_handling(451));
	if (chdir(new) == -1)
		return (error_handling(451));
	return (error_handling(212));
}

static int	change_directory(char **cmd, t_context *ctx)
{
	if (ft_tablen(cmd) == 1 || !ft_strcmp(cmd[1], "~"))
		return (change_to_home_or_old(ctx));
	else if (!ft_strcmp(cmd[1], "-"))
		return (change_to_home_or_old(ctx));
	return (change_dir(cmd[1]));
}

int			builtin_cd(char **cmd, t_context *ctx)
{
	if (ft_tablen(cmd) > 2)
		return (error_handling(501));
	return (change_directory(cmd, ctx));
}
