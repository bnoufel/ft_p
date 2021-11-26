/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:53:28 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 13:53:30 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# define GNL_BUFF_SIZE 1024

# include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_gnl(const int fd, char **line);
int		ft_addncharbefore(int n, char c, char **str);
int		ft_flags(int ac, char **av, unsigned int *flags);
void	ft_bzero(void *s, size_t n);
void	ft_swap(int *a, int *b);
void	ft_memdel(void **ap);
void	ft_memrev(void *ptr, size_t size);
void	ft_free_tab(char **tab);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memalloc(size_t size);

#endif
