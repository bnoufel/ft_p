/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:53:20 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 13:53:21 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

int		ft_random(void);
int		ft_sqrt(int nb);
int		ft_bracket(char *str);
int		ft_power(int number, int power);
int		*ft_sort_int_tab(int *tab, size_t length);
int		ft_abs(int nb);
int		ft_biggest(int a, int b);
int		ft_smallest(int a, int b);

#endif
