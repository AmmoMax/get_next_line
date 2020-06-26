/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 22:31:00 by amayor            #+#    #+#             */
/*   Updated: 2020/06/03 22:31:00 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*check_rest(char *rest, char **line)
{
	char *res_strchr;

	res_strchr = NULL;
	if (rest)
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
	else
		*line = ft_strnew(1);
	return (res_strchr);
}

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_bytes;
	char	*res_strchr;
	static	char *rest;
	char	*tmp;

	if (fd < 0 || line == 0)
		return (-1);
	res_strchr = check_rest(rest, line); //или указатель на новую строку в остатке или NULL
	while (!res_strchr && ((read_bytes = read(fd, buf, BUFFER_SIZE)) != 0))
	{
		buf[read_bytes] = '\0';
		if ((res_strchr = ft_strchr(buf, '\n')))
		{
			*res_strchr = '\0';
			res_strchr++;
			rest = ft_strdup(res_strchr);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || read_bytes < 0)
			return (-1);
		free(tmp);
	}
	// free(*line);
	// free(rest);
	return ((read_bytes || ft_strlen(rest) || ft_strlen(*line)) ? 1 : 0);
	// read_bytes !=0 - что то было прочитано или в rest != 0 - что то осталось, line length != 0 - 
}
