/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:27:59 by bnoufel           #+#    #+#             */
/*   Updated: 2018/11/09 12:14:44 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

/*
**	print the string s on the standard output
**	followed by carriage return (\n).
*/

void	ft_putendl(char const *s)
{
	ft_putendl_fd(s, 1);
}
