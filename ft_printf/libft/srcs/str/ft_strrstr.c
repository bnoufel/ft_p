/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:35:32 by bnoufel           #+#    #+#             */
/*   Updated: 2018/11/09 13:28:55 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "str.h"

/*
**	ft_strrstr A pointer of the last occurence of the string needle in
**	the haystack is returned or NULL if needle is not found.
*/

char	*ft_strrstr(const char *haystack, const char *needle)
{
	int				i;
	int				j;
	int				save;

	if (!needle[0])
		return ((char*)haystack);
	i = ft_strlen(haystack) - ft_strlen(needle) - 1;
	save = 0;
	while (i > -2)
	{
		j = -1;
		while (haystack[++i] == needle[++j])
			if (!needle[j + 1])
				return ((char*)&haystack[save]);
		i = --save - 1;
	}
	return (NULL);
}
