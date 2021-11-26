/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serch_user.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:29 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:30 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_user			*search_user(t_user *list, char *login)
{
	t_user		*tmp;

	tmp = list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->login, login))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
