/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:52:32 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 13:52:56 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isxdigit(int c);
int					ft_isalnum(int c);
int					ft_isspace(int c);
int					ft_isascii(int c);
int					ft_ispunct(int c);
int					ft_iscntrl(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

#endif
