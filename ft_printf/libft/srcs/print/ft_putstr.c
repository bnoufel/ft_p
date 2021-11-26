/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:01:45 by bnoufel           #+#    #+#             */
/*   Updated: 2018/11/09 12:14:08 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

/*
**	print the string s on the standard output.
*/

void		ft_putstr(char const *str)
{
	ft_putstr_fd(str, 1);
}
