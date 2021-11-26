/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:12:41 by bnoufel           #+#    #+#             */
/*   Updated: 2018/03/21 16:23:30 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

/*
**	ft_strnequ return 1 if the n first characters of s1 and s2 are identical.
**	return 0 elseway.
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (!(ft_strncmp(s1, s2, n)));
}
