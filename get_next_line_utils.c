/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayor <amayor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 21:56:05 by amayor            #+#    #+#             */
/*   Updated: 2020/07/12 23:29:42 by amayor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		len += 1;
		s++;
	}
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

char		*ft_strnew(size_t size)
{
	char	*res;

	if (!(res = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	res[size] = '\0';
	while (size--)
		res[size] = '\0';
	return (res);
}

char		*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i])
			i++;
		else
			return (NULL);
	}
	return (char *)&s[i];
}

char		*ft_strdup(char *s)
{
	char	*res;
	char	*res_start;
	size_t	len;

	len = ft_strlen(s);
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	res_start = res;
	while (*s)
	{
		*res = *s;
		res++;
		s++;
	}
	*res = '\0';
	return (res_start);
}
