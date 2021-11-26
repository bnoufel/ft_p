/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showuser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:32 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:33 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void		showuser(t_user *list)
{
	t_user		*tmp;

	tmp = list;
	if (!tmp)
	{
		ft_printf("no users registered\n");
	}
	while (tmp)
	{
		ft_printf("[%s%s%s][%s%s%s]\n",
		BLUE, tmp->login, RESET, RED, tmp->password, RESET);
		tmp = tmp->next;
	}
}
