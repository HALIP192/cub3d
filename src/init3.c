/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:42:22 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/05 18:08:47 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	ft_abs(double num)
{
	if (num > 0)
		return (num);
	return (num * (-1));
}

int	init_floor_ceil_colors(t_texture *texture, char ***texture_split, int i)
{
	int		j;
	char	**buff1;

	if (!texture_split[i][1] || (texture_split[i][0][0] == 'F' && texture->floor
				!= 0) || (texture_split[i][0][0] == 'C' && texture->ceil != 0))
	{
		printf("Error in intialize file. Param number = %d\n", i);
		return (1);
	}
	buff1 = ft_split(texture_split[i][1], ',');
	j = 0;
	while (buff1[j])
	{
		if (texture_split[i][0][0] == 'F')
			texture->floor |= ft_atoi(buff1[j]) << (8 * (int)ft_abs((j - 2)));
		if (texture_split[i][0][0] == 'C')
			texture->ceil |= ft_atoi(buff1[j]) << (8 * (int)ft_abs((j - 2)));
		j++;
		if (j > 3)
		{
			printf("Error Floor and Ceil colors must have only 3 haract-cs.\n");
			return (1);
		}
	}
	return (0);
}
