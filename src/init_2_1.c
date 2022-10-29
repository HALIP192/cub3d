/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:57:49 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 18:59:29 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_for_double(char ***texture_split)
{
	int	i;
	int	j;

	i = 0;
	while (texture_split[i])
	{
		j = i + 1;
		while (texture_split[j])
		{
			if (ft_memcmp(texture_split[i][0], texture_split[j][0],
					ft_max(ft_strlen(texture_split[i][0]),
					ft_strlen(texture_split[j][0]))) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_texture_helper(char ***texture_split)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (texture_split[i][j])
		{
			free(texture_split[i][j]);
			j++;
		}
		free(texture_split[i]);
		i++;
	}
	free(texture_split);
}
