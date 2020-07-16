/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:57:30 by amayor            #+#    #+#             */
/*   Updated: 2020/07/16 22:12:24 by amayor           ###   ########.fr       */
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
			ft_strclr(rest);
		}
	}
	else
		*line = ft_strdup("");
	return (res_strchr);
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

int					check_buffer(int rb, char **res_strchr, \
					char **buf, char **rest, char **line)
{
	char			*tmp;
	char			*buffer;

	buffer = *buf;
	buffer[rb] = '\0';
	if ((*res_strchr = ft_strchr(buffer, '\n')))
	{
		**res_strchr = '\0';
		free(*rest);
		if (!(*rest = ft_strdup(++(*res_strchr))))
			return (-1);
	}
	tmp = *line;
	if (!(*line = ft_strjoin(*line, *buf)))
		return (-1);
	free(tmp);
	return (1);
}

int					get_next_line(int fd, char **line)
{
	char			*b;
	int				read_bytes;
	char			*res_strchr;
	static	char	*rest;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(b = malloc((BUFFER_SIZE + 1) * sizeof(char))) || read(fd, b, 0) < 0)
	{
		free(b);
		return (-1);
	}
	read_bytes = 0;
	res_strchr = check_rest(rest, line);
	while (!res_strchr && (read_bytes = read(fd, b, BUFFER_SIZE)))
		if (check_buffer(read_bytes, &res_strchr, &b, &rest, line) == -1)
			return (-1);
	free(b);
	if (read_bytes == 0 && !res_strchr)
	{
		free(rest);
		rest = NULL;
	}
	return ((read_bytes || res_strchr) ? 1 : 0);

}
