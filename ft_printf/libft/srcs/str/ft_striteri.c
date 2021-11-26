/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:29:54 by bnoufel           #+#    #+#             */
/*   Updated: 2018/11/09 12:54:35 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_striter apply the function passed in parameter on each character of the
**	string s. The index of the character is also passed to the function.
*/

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = -1;
	if (s && f)
		while (s[++i])
			f(i, &s[i]);
}
