/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pass_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:59 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:00 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int	split_line(char *line, t_user **list, char ***tab)
{
	if (!(*tab = ft_strsplit(line, ':')))
	{
		ft_dprintf(2, "ERROR: strsplit error\n");
		free(line);
		free_user_list(list);
		return (1);
	}
	ft_strdel(&line);
	return (0);
}

static int	check_tab(char **tab, t_user **list, char *pass_file)
{
	if (!tab[1] || tab[2])
	{
		ft_free_tab(tab);
		ft_dprintf(2, "ERROR: %s file corrupted\n", pass_file);
		free_user_list(list);
		return (1);
	}
	return (0);
}

static int	read_file(int pass_fd, t_user **list, char *pass_file)
{
	char	**tab;
	char	*line;

	tab = NULL;
	while ((ft_gnl(pass_fd, &line)) > 0)
	{
		if (split_line(line, list, &tab))
			return (1);
		if (!tab[0])
		{
			ft_free_tab(tab);
			continue ;
		}
		if (check_tab(tab, list, pass_file))
			return (1);
		if (add_elem(list, tab[0], tab[1]))
		{
			ft_free_tab(tab);
			free_user_list(list);
			return (1);
		}
		ft_free_tab(tab);
	}
	return (0);
}

t_user		*get_pass_file(char *pass_file)
{
	int		pass_fd;
	t_user	*list;

	if ((pass_fd = open(pass_file, O_CREAT | O_RDONLY, 0755)) < 0)
	{
		ft_printf("ERROR: can not create or read %s\n", pass_file);
		return (NULL);
	}
	list = NULL;
	if (add_elem(&list, "", ""))
	{
		ft_printf("ERROR: can not create user list\n");
		return (NULL);
	}
	if (read_file(pass_fd, &list, pass_file))
	{
		close(pass_fd);
		return (NULL);
	}
	close(pass_fd);
	return (list);
}
