/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:39 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:40 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			set_env(t_context *ctx, char **env)
{
	size_t	i;
	size_t	len;
	char	**tab;

	i = -1;
	len = ft_tablen(env);
	if (!len)
		return (EXIT_FAILURE);
	while (++i < len)
	{
		if (!(tab = ft_strsplit(env[i], '=')))
			return (EXIT_FAILURE);
		if (ft_tablen(tab) != 2)
		{
			ft_free_tab(tab);
			continue ;
		}
		if (!ft_strcmp(tab[0], "HOME"))
		{
			if (!(ctx->home = ft_strdup(tab[1])))
				continue ;
		}
		ft_free_tab(tab);
	}
	return (EXIT_SUCCESS);
}
