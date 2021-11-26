/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newdeleteuser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:17 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:18 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		free_newuser(char *login, char *pass, char *confirm_pass)
{
	if (login)
		ft_strdel(&login);
	if (pass)
		ft_strdel(&pass);
	if (confirm_pass)
		ft_strdel(&confirm_pass);
}

static char		*new_user_get_login(t_context *ctx)
{
	char		*login;

	while (1)
	{
		if (!(login = get_login()))
			return (NULL);
		if (search_user(ctx->user_list, login))
		{
			ft_strdel(&login);
			ft_dprintf(2, "login already used\n");
			continue ;
		}
		break ;
	}
	return (login);
}

static char		*new_user_get_password(char *login, char **password)
{
	char		*confirm;

	if (!(*password = get_password()))
	{
		ft_strdel(&login);
		return (NULL);
	}
	write(1, "confirm ", 8);
	if (!(confirm = get_password()))
	{
		free_newuser(login, *password, NULL);
		return (NULL);
	}
	if (ft_strncmp(*password, confirm, 256))
	{
		free_newuser(login, *password, confirm);
		ft_dprintf(2, "ERROR: different passwords\n");
		return (NULL);
	}
	return (confirm);
}

void			newuser(t_context *ctx)
{
	char		*login;
	char		*pass;
	char		*confirm_password;

	if (!(login = new_user_get_login(ctx)))
		return ;
	if (!(confirm_password = new_user_get_password(login, &pass)))
		return ;
	if (!add_in_pass_file(login, pass, ctx->pass_file, &(ctx->user_list)))
		ft_printf("%s succesfully added\n", login);
	else
		ft_dprintf(2, "%s can not be added to %s\n", login, ctx->pass_file);
	free_newuser(login, pass, confirm_password);
}

void			deleteuser(t_context *ctx)
{
	char		*login;
	char		*pass;

	if (!(login = get_login()))
		return ;
	if (!(pass = get_password()))
	{
		free(login);
		return ;
	}
	if (!(remove_pass_file(login, pass,
									ctx->pass_file, &(ctx->user_list))))
		ft_printf("%s succesfully deleted\n", login);
	else
		ft_dprintf(2, "%s can not be deleted from %s", login, ctx->pass_file);
	free_newuser(login, pass, NULL);
}
