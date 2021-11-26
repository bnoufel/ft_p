/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mput.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:30 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:31 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	create_cmd_mput(t_glob glob, size_t i, char ***tab)
{
	if (!((*tab) = (char **)ft_memalloc(sizeof(char *) * 3)))
	{
		ft_globfree(&glob);
		return (552);
	}
	if (!((*tab)[0] = ft_strdup("put ")))
	{
		ft_globfree(&glob);
		return (552);
	}
	if (!((*tab)[1] = ft_strdup(glob.res[i])))
	{
		ft_globfree(&glob);
		return (552);
	}
	(*tab)[2] = 0;
	return (200);
}

int			send_mput(t_context *ctx, char *cmd)
{
	t_glob	glob;
	size_t	i;
	char	**tmp;

	i = 0;
	if (ft_glob(cmd, &glob))
		return (1);
	while (i < glob.size)
	{
		if (create_cmd_mput(glob, i, &tmp) != 200)
			return (error_handling(552));
		send_put(tmp, ctx, "mput");
		ft_free_tab(tmp);
		i++;
	}
	ft_globfree(&glob);
	return (error_handling(200));
}
