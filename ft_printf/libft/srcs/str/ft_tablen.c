/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:51:02 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 13:51:02 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

/*
**	ft_tablen return the length of the tab passed in parameter.
*/

size_t		ft_tablen(char **s1)
{
	size_t		i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}
