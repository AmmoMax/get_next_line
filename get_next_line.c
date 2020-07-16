/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:57:30 by amayor            #+#    #+#             */
/*   Updated: 2020/07/16 10:13:03 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char				*check_rest(char *rest, char **line)
{
	char			*res_strchr;

	res_strchr = NULL;
	if (rest)
	{
		if ((res_strchr = ft_strchr(rest, '\n')))
		{
			*res_strchr = '\0';
			*line = ft_strdup(rest);
			ft_strcpy(rest, ++res_strchr);
		}
		else
		{
			*line = ft_strdup(rest);
			free(rest);
			// ft_strclr(rest);
		}
	}
	else
		*line = ft_strdup(rest);
	return (res_strchr);
}

int				save_rest(char **rest, char *res_strchr)
{
	// free(rest);
	if(!(*rest = ft_strdup(res_strchr)))
		return (-1);
	return (1);
}

void				ft_strclr(char *str)
{
	size_t			i;

	i = 0;
	if (str)
		while (str[i])
		{
			str[i] = '\0';
			i++;
		}
}

char				*ft_strcpy(char *dst, const char *src)
{
	size_t			i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int					memory_free(char **s1, char **s2)
{
	if (*s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (*s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (-1);
}

int					get_next_line(int fd, char **line)
{
	char			*buf;
	int				read_bytes;
	char			*res_strchr;
	static	char	*rest;
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
		// return (memory_free(&buf, line));
	if(read(fd, buf, 0) < 0)
	{
		free(buf);
		return (-1);
	}
	read_bytes = 0;


	res_strchr = check_rest(rest, line);
	while (!res_strchr && (read_bytes = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_bytes] = '\0';
		if ((res_strchr = ft_strchr(buf, '\n')))
		{
			*res_strchr = '\0';
			res_strchr++;
			if (save_rest(&rest, res_strchr) == -1)
				return (-1);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(tmp);
	}
	free(buf);
	// if (read_bytes == 0 && rest != 0)
	// 	memory_free(&rest, &rest);
	if(!read_bytes || !res_strchr)
	{
		free(rest);
		rest = NULL;
	}
	return ((read_bytes || res_strchr) ? 1 : 0);
}
