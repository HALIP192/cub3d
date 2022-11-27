/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:19:59 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/27 17:21:41 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	inside_minimap(t_data *data, int width_del, int height_del)
{
	if (data->x >= (data->screenwidth - data->mapwidth * width_del)
		&& data->y <= (data->mapheight * height_del))
		return (1);
	return (0);
}

static void	minimap_put_pxl(t_data *data, t_mlxdata *mlxData, int color)
{
	mlxData->image[data->y * (data->line_lenght / 4) + data->x] = color;
}

void	minimap_draw(t_data *data, t_texture *texture, t_mlxdata *mlxData)
{
	int	width_del_map;
	int	height_del_map;

	(void)texture;
	width_del_map = data->screenwidth / (data->mapwidth * 4);
	height_del_map = data->screenheight / (data->mapheight * 4);
	if (inside_minimap(data, width_del_map, height_del_map))
	{
		if (data->map[(data->x - (data->screenwidth - data->mapwidth
						* width_del_map)) / width_del_map]
			[(data->y) / height_del_map] != 0)
		{
			minimap_put_pxl(data, mlxData, 0x00ff0000);
		}
		else
		{
			if (fabs((data->x - (data->screenwidth - data->mapwidth
							* width_del_map)) - data->posx * width_del_map)
				< width_del_map / 2 && fabs((data->y) - data->posy
					* height_del_map) < height_del_map / 2)
				minimap_put_pxl(data, mlxData, 0x0000ff00);
			else
				minimap_put_pxl(data, mlxData, 0x00000000);
		}
	}
}
