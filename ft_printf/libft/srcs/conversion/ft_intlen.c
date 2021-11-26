/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:53:59 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 13:54:02 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conversion.h"

/*
**	ft_intlen_base return the length of the value passed in base 10.
*/

int		ft_intlen(int value)
{
	return (ft_intlen_base(value, 10));
}
