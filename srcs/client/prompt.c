/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:17:31 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 14:17:32 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void			print_prompt(void)
{
	char		*login;
	char		*p;

	if (g_login)
		login = g_login;
	else
		login = "anonymous";
	if ((p = getcwd(NULL, 0)))
	{
		ft_printf("%c%s%s %s[%s]%s\n", 10, MAGENTA, login, YELLOW, p, RESET);
		ft_strdel(&p);
	}
	else
		ft_printf("%c%s%s%s\n", 10, MAGENTA, login, RESET);
	ft_printf("%sclient>%s ", BLUE, RESET);
}
