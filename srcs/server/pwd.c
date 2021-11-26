/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:18:22 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:18:24 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			ft_pwd(t_process *process)
{
	char		*tmp;
	char		str[512];
	ssize_t		len;

	tmp = NULL;
	if (ft_asprintf(&tmp, "%s %d", ACCEPT, ft_strlen(process->pwd)) == -1)
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	message(process, tmp);
	free(tmp);
	if ((len = recv(process->sock_fd_client, str, ft_strlen(ACCEPT), 0)) == -1)
		return ;
	str[len] = '\0';
	if (!ft_strcmp(str, ACCEPT))
		message(process, process->pwd);
	return ;
}
