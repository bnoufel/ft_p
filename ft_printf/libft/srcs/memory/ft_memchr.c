/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 11:48:48 by bnoufel           #+#    #+#             */
/*   Updated: 2018/11/09 15:38:26 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_memchr return the address of the first occurence of byte c in s,
**	or the size n is reached.
*/

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*tmp;
	size_t				i;

	tmp = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (tmp[i] == (unsigned char)c)
			return (&tmp[i]);
	return (NULL);
}
