/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:47:32 by bnoufel           #+#    #+#             */
/*   Updated: 2018/03/21 16:20:13 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_strlen return the length of the string passed in parameter.
*/

size_t		ft_strlen(const char *str)
{
	size_t		x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}
