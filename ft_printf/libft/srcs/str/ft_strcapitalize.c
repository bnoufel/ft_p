/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:47:32 by bnoufel           #+#    #+#             */
/*   Updated: 2018/03/21 16:20:13 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

/*
**	ft_strcapitalize take a string in argument
**	and capitalize every lower letters.
*/

char		*ft_strcapitalize(char *str)
{
	int		x;

	x = -1;
	while (str[++x])
		str[x] = ft_toupper(str[x]);
	return (str);
}
