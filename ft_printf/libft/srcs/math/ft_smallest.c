/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:46:17 by bnoufel           #+#    #+#             */
/*   Updated: 2018/03/30 18:07:16 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_smallest return the smallest int of the two params.
*/

int		ft_smallest(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
