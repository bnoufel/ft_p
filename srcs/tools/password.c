/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   password.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:43 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:45 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char			*sha512(char *str)
{
	char		digest[64];
	char		*ret;
	int			i;

	if (!(ret = (char*)ft_memalloc(129)))
		return (NULL);
	SHA512((unsigned char*)str, ft_strlen(str), (unsigned char*)&digest);
	i = 0;
	while (i < 64)
	{
		ret[i * 2] = BASE_HEXA[((unsigned int)digest[i]) & 0xf];
		ret[i * 2 + 1] = BASE_HEXA[(((unsigned int)digest[i]) >> 4) & 0xf];
		i++;
	}
	return (ret);
}
