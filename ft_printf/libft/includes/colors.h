/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:52:42 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 13:52:58 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RED "\x1b[31;1m"
# define GREEN "\x1b[32;1m"
# define YELLOW "\x1b[33;1m"
# define BLUE "\x1b[34;1m"
# define MAGENTA "\x1b[35;1m"
# define CYAN "\x1b[36;1m"
# define RESET "\x1b[0m"

void	ft_red(char const *str);
void	ft_green(char const *str);
void	ft_yellow(char const *str);
void	ft_blue(char const *str);
void	ft_magenta(char const *str);
void	ft_cyan(char const *str);

#endif
