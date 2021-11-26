/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:53:59 by bnoufel           #+#    #+#             */
/*   Updated: 2018/11/09 12:27:12 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_sqrt return the square root of the number passed in parameter rounded up.
*/

int		ft_sqrt(int nb)
{
	int		x;

	x = 1;
	if (nb < 0 || nb > 2147395600)
		return (0);
	while (nb > (x * x))
		x++;
	return (x);
}
