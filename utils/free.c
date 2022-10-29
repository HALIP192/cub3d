/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 20:37:47 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 21:05:28 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	data_cleaner(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->mapheight)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_texture(t_texture *data, t_mlxdata *mlxData)
{
	int	i;

	i = 0;
	while (i < 0)
	{
		mlx_destroy_image(mlxData->mlx_ptr, data->imgs[i]);
		free(data->imgs[i]);
		i++;
	}
	free(data->img_ptr);
	free(data->imgs);
	free(data->height);
	free(data->width);
	free(data->bpp);
	free(data->end);
	free(data->sl);
}

int	ft_close_window(t_data *data)
{
	t_mlxdata	*mlxdata;

	mlxdata = mlxdata_global();
	mlx_destroy_image(mlxdata->mlx_ptr, mlxdata->img_ptr);
	mlx_destroy_window(mlxdata->mlx_ptr, mlxdata->mlx_win);
	data_cleaner(data);
	exit(0);
	return (0);
}
