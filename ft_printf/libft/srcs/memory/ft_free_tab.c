/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:48:41 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 13:48:43 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_free_tab(char **tab)
{
	int		i;

	if (tab)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
		tab = NULL;
	}
}
