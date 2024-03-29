/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:48:17 by bnoufel           #+#    #+#             */
/*   Updated: 2018/11/09 12:09:24 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

/*
**	print the number nb on the standard output
**	followed by carriage return (\n).
*/

void		ft_putnbr_n(int nb)
{
	ft_putnbr(nb);
	ft_putchar('\n');
}
