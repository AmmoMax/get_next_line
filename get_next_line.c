/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:57:30 by amayor            #+#    #+#             */
/*   Updated: 2020/07/14 21:36:50 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			ft_strclr(rest);
		}
	}
	else
		*line = ft_strnew(1);
	return (res_strchr);
}

void				save_rest(char **rest, char *res_strchr)
{
	char			*rest_tmp;

	rest_tmp = *rest;
	*rest = ft_strdup(res_strchr);
	free(rest_tmp);
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

int					get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	int				read_bytes;
	char			*res_strchr;
	static	char	*rest;
	char			*tmp;

	if (fd < 0 || !line || (read(fd, buf, 0) < 0) || BUFFER_SIZE < 1)
		return (-1);
	res_strchr = check_rest(rest, line);
	while (!res_strchr && (read_bytes = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_bytes] = '\0';
		if ((res_strchr = ft_strchr(buf, '\n')))
		{
			*res_strchr = '\0';
			res_strchr++;
			save_rest(&rest, res_strchr);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(tmp);
	}
	return ((read_bytes || res_strchr) ? 1 : 0);
}

/*
Что проверять:
BUFFER_SIZE
fd
line
возможность чтения из переданного fd

*/