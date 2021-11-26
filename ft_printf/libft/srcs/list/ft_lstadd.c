/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:54:43 by bnoufel           #+#    #+#             */
/*   Updated: 2018/03/21 14:03:42 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/*
**	ft_lstadd add the new element on the first place of the list.
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}
