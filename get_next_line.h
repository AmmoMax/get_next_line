/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 21:52:59 by amayor            #+#    #+#             */
/*   Updated: 2020/07/08 22:22:21 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
char	*check_rest(char *rest, char **line);
void	save_rest(char **rest, char **res_strchr);
char	*ft_strcpy(char *dst, const char *src);
int		get_next_line(int fd, char **line);
void	ft_strclr(char *str);

#endif
