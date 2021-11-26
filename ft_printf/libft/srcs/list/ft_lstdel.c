/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:43:03 by bnoufel           #+#    #+#             */
/*   Updated: 2018/03/21 14:04:05 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
**	ft_lstdel delete the last element of the list.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst == NULL)
		return ;
	if ((*alst)->next != NULL)
		ft_lstdel(&(*alst)->next, (del));
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
