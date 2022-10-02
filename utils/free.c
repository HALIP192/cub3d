/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:37:47 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/02 20:56:58 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	***free_mas(char ***mas)
{
	int i;
	int j;

	i = 0;
	printf("malloc error in get_texture_info().\n");
	while (mas[i])
	{
		j = 0;
		while (mas[i][j])
		{
			free(mas[i][j]);
			j++;
		}
		free(mas[i]);
	}
	free(mas);
	return (NULL);
}

int	free_map(int **map, int width)
{
	int	i;

	i = 0;
	while (i < width)
		free(map[i++]);
	free(map);
	return (1);
}
