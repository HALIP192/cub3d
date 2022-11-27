/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 21:30:59 by ntitan            #+#    #+#             */
/*   Updated: 2022/01/06 21:31:00 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (i < len)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

static void	no_leaks(char **basket, char *karman)
{
	char	*temp;

	if (!*basket)
		*basket = ft_strdup(karman);
	else
	{
		temp = ft_strjoin(*basket, karman);
		if (basket != NULL)
			free(*basket);
		*basket = temp;
	}
}

static void	save_hvost(char *n, char **basket)
{
	char	*beg;

	beg = NULL;
	if (ft_strlen(n + 1) > 0)
	{
		beg = ft_strdup(n + 1);
		if (basket != NULL)
			free(*basket);
		*basket = ft_strdup(beg);
		free(beg);
		beg = NULL;
	}
	else
	{
		if (*basket)
		{
			if (basket != NULL)
				free(*basket);
			*basket = NULL;
			basket = NULL;
		}
	}
}

static char	*find_n_and_write_line(char **basket, char **line)
{
	char	*n;

	n = ft_strchr(*basket, '\n');
	if (n == NULL)
		*line = ft_substr(*basket, 0, ft_strlen(*basket));
	else
		*line = ft_substr(*basket, 0, (ft_strlen(*basket) - ft_strlen(n) + 1));
	if (n != NULL)
		save_hvost(n, basket);
	else
	{
		if (basket != NULL)
			free(*basket);
		*basket = NULL;
		basket = NULL;
	}
	return (*line);
}

char	*get_next_line(const int fd)
{
	static char	*basket[1024];
	char		karman[BUFF_SIZE + 1];
	long		result_op;
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || (read(fd, basket[fd], 0) < 0))
		return (NULL);
	if (basket[fd] && (ft_strchr(basket[fd], '\n') != NULL))
	{
		find_n_and_write_line(&basket[fd], &line);
		return (line);
	}
	result_op = read(fd, karman, BUFF_SIZE);
	while (result_op > 0)
	{
		karman[result_op] = '\0';
		no_leaks(&basket[fd], karman);
		if (ft_strchr(basket[fd], '\n') != NULL)
			break ;
		result_op = read(fd, karman, BUFF_SIZE);
	}
	if (result_op < BUFF_SIZE && !basket[fd])
		return (NULL);
	return (find_n_and_write_line(&basket[fd], &line));
}
