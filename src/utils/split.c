/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:59:54 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/27 17:39:22 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	words_alloc(char *s, char c)
{
	size_t	count;

	count = 0;
	while (s != (void *)0 && *s)
	{
		while (*s == c)
			s++;
		if (!(*s))
			continue ;
		s = ft_strchr(s, c);
		count++;
	}
	return (count);
}

void	*ft_free_4split(char **split, size_t id)
{
	while (id--)
		free(split[id]);
	free(split);
	return (NULL);
}

int	start_split(char *s, char c, size_t *count, char ***result)
{
	if (!s)
		return (1);
	*count = words_alloc(s, c);
	(*result) = (char **)malloc(sizeof(char *) * (*count + 1));
	if (!(*result))
		return (1);
	return (0);
}

char	**ft_split(char *s, char c)
{
	size_t	count;
	size_t	i;
	char	**result;
	char	*iter;

	if (start_split(s, c, &count, &result))
		return (NULL);
	result[count] = NULL;
	i = 0;
	while (i < count)
	{
		while (*s == c && *s && s != NULL)
			s++;
		iter = ft_strchr(s, c);
		if (iter == 0)
			iter = ft_strchr(s, '\n');
		if (iter == 0)
			iter = ft_strchr(s, '\0');
		result[i] = ft_substr(s, 0, (size_t)iter - (size_t)s);
		if (!result[i++])
			return ((char **)ft_free_4split(result, i));
		s = iter;
	}
	return (result);
}
