/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:08:54 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/27 15:00:00 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static inline void	floor_ceil_draw(t_data *data, t_mlxdata *mlxData,
									t_texture *texture)
{
	if (data->y < (data->screenheight) && data->y < data->drawstart)
		mlxData->image[data->y * (data->line_lenght / 4) + data->x]
			= texture->ceil;
	if (data->y < data->screenheight && data->y > data->drawend)
		mlxData->image[data->y * (data->line_lenght / 4) + data->x]
			= texture->floor;
}

void	my_pytpixl(t_data *data, t_texture *texture, t_mlxdata *mlxData,
				int texy)
{
	int	texnum;
	int	texx;

	texnum = data->corner;
	texx = get_texx(data, texture);
	if (data->side == 1)
			mlxData->image[data->y * (data->line_lenght / 4) + data->x]
			= (texture->imgs[texnum][texture->height[texnum] * texy
				+ texx] >> 1);
	else
		mlxData->image[data->y * (data->line_lenght / 4) + data->x]
			= texture->imgs[texnum][texture->height[texnum] * texy + texx];
}

int	inside_minimap(t_data *data, int width_del, int height_del)
{
	if (data->x >= (data->screenwidth - data->mapwidth * width_del) &&
		data->y <= (data->mapheight * height_del))
		return 1;
	return 0;
}

void minimap_draw(t_data *data, t_texture *texture, t_mlxdata *mlxData)
{
	int width_del_map;
	int height_del_map;

	width_del_map = data->screenwidth / (data->mapwidth * 4);
	height_del_map = data->screenheight / (data->mapheight * 4);
	if (inside_minimap(data, width_del_map, height_del_map))
	{
		
		/* printf("x: %d\ny: %d\n",(data->x - (data->screenwidth - data->mapwidth * 4)) / 4, (data->y - data->mapheight * 4) / 4); */
		if (data->map[(data->x - (data->screenwidth - data->mapwidth * width_del_map)) / width_del_map] 
				[(data->y) / height_del_map] != 0)
		{
			mlxData->image[data->y * (data->line_lenght / 4) + data->x]
			= 0x00ff0000;
		}
		else 
		{
			if ( fabs((data->x - (data->screenwidth - data->mapwidth *
							width_del_map)) - data->posx * width_del_map) < width_del_map / 2
				&& fabs((data->y) - data->posy * height_del_map) < height_del_map / 2)
				mlxData->image[data->y * (data->line_lenght / 4) + data->x]
				= 0x0000ff00;
			else
				mlxData->image[data->y * (data->line_lenght / 4) + data->x]
				= 0x00000000;

		}

		/* if (data->x == (int)data->posx && data->y == (int)data->posy || */
		/* 	data->x == (int)data->posx && data->y - 1 == (int)data->posy || */
		/* 	data->x - 1 == (int)data->posx && data->y == (int)data->posy || */
		/* 	data->x - 1 == (int)data->posx && data->y - 1 == (int)data->posy) */
		/* 	mlxData->image[data->y * (data->line_lenght / 4) + data->x] */
		/* 	= 0x0000ff00; */
		/* if (data->map[data->x][data->y] != 0 || */
		/* 	data->map[data->x][data->y - 1] != 0 || */
		/* 	data->map[data->x - 1][data->y] != 0 || */
		/* 	data->map[data->x - 1][data->y - 1] != 0) */
		/* 	mlxData->image[data->y * (data->line_lenght / 4) + data->x] */
		/* 	= 0x00ff0000; */
		/* else */
		/* 	mlxData->image[data->y * (data->line_lenght / 4) + data->x] */
		/* 	= 0x000000ff; */
	}
}

void	raycasting(t_data *data, t_texture *texture, t_mlxdata *mlxData,
					int texNum)
{
	double	step;
	double	texpos;
	int		texy;
	int		texx;

	texx = get_texx(data, texture);
	step = 1.0 * texture->height[texNum] / data->lineheight;
	texpos = (data->drawstart - data->screenheight / 2 + data->lineheight / 2)
		* step;
	data->y = 0;
	while (data->y < data->screenheight)
	{
		floor_ceil_draw(data, mlxData, texture);
		if (data->y >= data->drawstart && data->y <= data->drawend)
		{
			texy = (int)texpos & (texture->height[texNum] - 1);
			texpos += step;
			my_pytpixl(data, texture, mlxData, texy);
		}
		minimap_draw(data, texture, mlxData);
		data->y++;
	}
}

void	cub3d(t_data *data)
{	
	int			texx;
	int			texnum;
	t_texture	*texture;
	t_mlxdata	*mlxdata;

	data->x = 0;
	texture = texture_global();
	mlxdata = mlxdata_global();
	while (data->x < data->screenwidth)
	{
		init_dda(data);
		init_steps_and_sidedist(data);
		dda(data);
		set_draw_starts(data);
		texnum = data->corner;
		raycasting(data, texture, mlxdata, texnum);
		data->x++;
	}
	mlx_put_image_to_window(mlxdata->mlx_ptr, mlxdata->mlx_win,
		mlxdata->img_ptr, 0, 0);
}
