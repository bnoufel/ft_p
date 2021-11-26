/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:26:28 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:26:35 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_intlen_base return the length of the value passed
**	using the base passed in parametre.
**	If value is less than 0 and base is not 10, 0 is returned.
*/

int		ft_intlen_base(int value, int base)
{
	int	len;

	len = 0;
	if ((value < 0 && base != 10) || base < 2)
		return (0);
	if (value == 0)
		return (1);
	if (value < 0)
		len++;
	while (value > 0)
	{
		value = value / base;
		len++;
	}
	return (len);
}
