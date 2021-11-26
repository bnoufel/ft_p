/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bracket.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:54:39 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 13:55:24 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_brackets verify the consistency of the brackets.
**	return 1 if it is valid, 0 elseway.
**	WARNING: To optimize the function, the allowed size of the stack is 128.
**	WARNING: ft_brackets can crash if the expression are too heavy.
*/

static int		ft_bracket_charcmp(char c1, char c2)
{
	return ((c1 == '(' && c2 == ')')
			|| (c1 == '{' && c2 == '}')
			|| (c1 == '[' && c2 == ']'));
}

int				ft_brackets(char *str)
{
	int		tab[128];
	int		i;

	tab[0] = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			tab[++tab[0]] = str[i];
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
			if (!ft_bracket_charcmp(tab[tab[0]--], str[i]))
				return (0);
		++i;
	}
	return (tab[0] == 0);
}
