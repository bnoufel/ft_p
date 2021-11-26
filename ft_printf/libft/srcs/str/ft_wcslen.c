/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:40:16 by bnoufel           #+#    #+#             */
/*   Updated: 2018/11/09 14:52:55 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

/*
**	ft_strlen return the length of the unicode string passed in parameter.
*/

size_t		ft_wcslen(wchar_t *str)
{
	size_t		i;

	i = 0;
	while (str[i] != L'\0')
		++i;
	return (i);
}
