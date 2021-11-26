/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 07:29:58 by bnoufel           #+#    #+#             */
/*   Updated: 2018/11/09 14:56:30 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
**	ft_lstpushback add the new element on the last place of the list.
*/

void		ft_lstpushback(t_list **begin, void *data, size_t size)
{
	t_list		*tmp;

	if (!begin)
		return ;
	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_lstnew(data, size);
}
