/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:53 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:54 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_cd_second(t_process *process, char *folder)
{
	int		verif;

	if ((verif = verif_dir(process, folder)))
	{
		message(process, REFUSE);
		return ;
	}
	chdir(folder);
	free(process->pwd);
	process->pwd = getcwd(NULL, 0);
	message(process, ACCEPT);
}

void	ft_cd(t_process *process, char **command)
{
	char	*dir_name;
	int		len;

	len = ft_atoi(command[1]);
	if (ft_tablen(command) != 2 || !(dir_name = ft_strnew(len + 1)))
	{
		message(process, COMMAND_FAIL);
		return ;
	}
	message(process, ACCEPT);
	if ((recv(process->sock_fd_client, dir_name, len, 0)) == -1)
	{
		free(dir_name);
		message(process, COMMAND_FAIL);
		return ;
	}
	ft_cd_second(process, dir_name);
	free(dir_name);
}
