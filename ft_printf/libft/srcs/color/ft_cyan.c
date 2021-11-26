/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cyan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/21/08 13:54:05 by bnoufel           #+#    #+#             */
/*   Updated: 2019/22/08 17:53:19 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "colors.h"
#include "str.h"

/*
**	ft_cyan will write the string passed in cyan in the standar output.
**	3 syscall have been used to avoid the use of malloc, but it is not
**	optimized.
*/

void	ft_cyan(char const *s)
{
	if (s)
	{
		write(1, CYAN, ft_strlen(CYAN));
		write(1, s, ft_strlen(s));
		write(1, RESET, ft_strlen(RESET));
	}
}
