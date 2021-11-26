/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:53:59 by bnoufel           #+#    #+#             */
/*   Updated: 2018/04/30 11:07:44 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
**	ft_random return a pseudo-random number.
*/

int	ft_random(void)
{
	static int	first = 0;

	if (!first)
	{
		srand(time(NULL));
		first = 1;
	}
	return (rand());
}
