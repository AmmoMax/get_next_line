/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 21:52:59 by amayor            #+#    #+#             */
/*   Updated: 2020/06/05 21:52:59 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if BUFFER_SIZE < 1
#error The BUFFER_SIZE is less than zero
#endif
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h> //open
#include <unistd.h> //read
#include <stdlib.h> //malloc

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strclr(char *str);

#endif