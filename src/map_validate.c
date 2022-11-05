/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:12:44 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/05 18:10:51 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	lstcpy(t_data *data, char *src, int j)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		if (ft_isdigit(src[i]))
			data->map[j][i] = src[i] - '0';
		else if (src[i] == 'N' || src[i] == 'S'
			|| src[i] == 'W' || src[i] == 'E')
		{
			if (init_position(data, src, j, i))
				return (1);
		}
		else if (src[i] == ' ')
			data->map[j][i] = -1;
		else
			return (1);
		i++;
	}
	while (i < data->mapheight)
	{
		data->map[j][i] = -1;
		i++;
	}
	return (0);
}

int	init_rec_check_mas(t_data *data, int **map, int i, int j)
{
	if (map[i][j] == -1 || i == data->mapwidth - 1 ||
		i == 0 || j == data->mapheight - 1 || j == 0)
		return (1);
	map[i][j] = -2;
	if (map[i + 1][j] == 0)
		return (init_rec_check_mas(data, map, i + 1, j));
	if (map[i][j + 1] == 0)
		return (init_rec_check_mas(data, map, i, j + 1));
	if (map[i - 1][j] == 0)
		return (init_rec_check_mas(data, map, i - 1, j));
	if (map[i][j - 1] == 0)
		return (init_rec_check_mas(data, map, i, j - 1));
	return (0);
}

void	free_map_cp(int **mas_cp, int max)
{
	int	i;

	i = 0;
	while (i < max)
		free(mas_cp[i++]);
	free(mas_cp);
}

int	recursiv_check_map(t_data *data, int i_check, int j_check)
{
	int	**mas_cp;
	int	i;
	int	j;

	i = 0;
	mas_cp = (int **)malloc(sizeof(int *) * data->mapwidth);
	if (!mas_cp)
		exit(printf("error: %s: malloc error: %d", __FILE__, __LINE__));
	while (i < data->mapwidth)
	{
		j = 0;
		mas_cp[i] = (int *)malloc(sizeof(int) * data->mapheight);
		while (j < data->mapheight)
		{
			mas_cp[i][j] = data->map[i][j];
			j++;
		}
		i++;
	}
	if (init_rec_check_mas(data, mas_cp, i_check, j_check))
		exit (printf("Map error1.\n"));
	free_map_cp(mas_cp, data->mapwidth);
	return (0);
}

int	validate_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mapwidth)
	{
		j = 0;
		while (j < data->mapheight)
		{
			if (data->map[i][j] == 0)
				return (recursiv_check_map(data, i, j));
			j++;
		}
		i++;
	}
	return (1);
}
