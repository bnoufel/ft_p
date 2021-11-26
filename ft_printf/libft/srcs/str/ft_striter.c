/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:29:54 by bnoufel           #+#    #+#             */
/*   Updated: 2018/11/09 12:53:46 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_striter apply the function passed in parameter on
**	each character of the string s.
*/

void		ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(&(*s++));
}
