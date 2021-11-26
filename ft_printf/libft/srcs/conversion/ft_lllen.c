/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lllen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:54:30 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 13:54:32 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_lllen return the length of the value passed in base 10.
*/

int		ft_lllen(long long value)
{
	int	len;

	len = 0;
	if (value == 0)
		return (1);
	if (value < 0)
		len++;
	while (value > 0)
	{
		value = value / 10;
		len++;
	}
	return (len);
}
