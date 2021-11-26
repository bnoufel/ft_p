/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mget.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:14 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:15 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void		send_files_mget(char *nb, char *file, t_process *process)
{
	ft_bzero(nb, 64);
	ft_sprintf(nb, "%064llu", ft_strlen(file));
	message(process, nb);
	message(process, file);
	ft_send_file(process, file);
}

static void		ft_mget_second(t_process *process, uint64_t size, char *str)
{
	t_glob		glob;
	char		nb[65];
	char		**tmp;
	long		i;

	if ((i = (recv(process->sock_fd_client, str, size, 0))) == -1)
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	str[size] = '\0';
	if (ft_glob(str, &glob))
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	ft_sprintf(nb, "%064llu", glob.size);
	message(process, nb);
	tmp = glob.res;
	while (*tmp)
	{
		send_files_mget(nb, *tmp, process);
		tmp += 1;
	}
	ft_globfree(&glob);
}

void			ft_mget(t_process *process, char **command)
{
	char		*str;
	uint64_t	size;

	size = ft_atoull(command[1]);
	if (!(str = ft_strnew(size + 1)))
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	message(process, ACCEPT);
	ft_mget_second(process, size, str);
	free(str);
}
