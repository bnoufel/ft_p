/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:35:03 by bnoufel           #+#    #+#             */
/*   Updated: 2018/03/06 18:39:02 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_power return the number to the power passed in parameter.
**	WARNING: ft_power can overflow.
*/

int		ft_power(int number, int power)
{
	int		save;

	save = number;
	if (power < 1)
		return (1);
	while (power-- > 1)
		number = number * save;
	return (number);
}
