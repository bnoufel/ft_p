/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_pass_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:56 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:57 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	write_in_pass_file(t_user *list, char *pass_file)
{
	t_user	*tmp;
	int		p_fd;

	if ((p_fd = open(pass_file, O_CREAT | O_WRONLY | O_TRUNC, 0755)) < 0)
	{
		ft_dprintf(2, "ERROR: can not write in %s\n", pass_file);
		return (1);
	}
	tmp = list;
	while (tmp)
	{
		ft_dprintf(p_fd, "%s:%s\n", tmp->login, tmp->password);
		tmp = tmp->next;
	}
	close(p_fd);
	return (0);
}

int			add_in_pass_file(char *login, char *pass, char *file, t_user **lst)
{
	int		p_fd;
	t_user	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->login, login))
		{
			ft_dprintf(2, "ERROR: %s login already used\n", login);
			return (1);
		}
		tmp = tmp->next;
	}
	if (add_elem(lst, login, pass))
	{
		ft_dprintf(2, "ERROR: can not add %s to users\n", login);
		return (1);
	}
	if ((p_fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0755)) < 0)
	{
		ft_dprintf(2, "ERROR: can not write in %s\n", file);
		return (1);
	}
	ft_dprintf(p_fd, "%s:%s\n", login, pass);
	return (close(p_fd) && 0);
}

int			remove_pass_file(char *login, char *pass, char *file, t_user **lst)
{
	t_user	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (!ft_strcmp(tmp->login, login) && !ft_strcmp(tmp->password, pass))
		{
			remove_elem(lst, tmp);
			return (write_in_pass_file(*lst, file));
		}
		tmp = tmp->next;
	}
	ft_dprintf(2, "ERROR: wrong user or password\n");
	return (1);
}
