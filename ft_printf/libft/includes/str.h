/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnoufel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:53:40 by bnoufel           #+#    #+#             */
/*   Updated: 2020/02/20 13:53:43 by bnoufel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H

# include <wchar.h>

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
int			ft_char_index(const char *str, char c);
int			ft_strisdigit(const char *str);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *s1);
char		*ft_strdupfree(const char *s1, char **tofree);
char		*ft_strncat(char *dest, const char *src, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strrstr(const char *haystack, const char *needle);
char		*ft_strchr(const char *s, int c);
char		*ft_strpbrk(const char *s, const char *charset);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strrchr(const char *s, int c);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoinfree(char *s1, char *s2, size_t tofree);
char		*ft_strtrim(char const *s);
char		*ft_strrev(char *str);
char		*ft_strcapitalize(char *str);
char		*ft_strupperize(char *str);
char		*ft_strlowcase(char *str);
char		**ft_strsplit(char const *s, char c);
char		**ft_tabdup(char **s1);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t		ft_strlcat(char *dest, const char *src, size_t count);
size_t		ft_strlen(const char *str);
size_t		ft_strlen_c(const char *str, char c);
size_t		ft_strlenwcs(wchar_t *wcs);
size_t		ft_wcslen(wchar_t *str);
size_t		ft_tablen(char **s1);

#endif
