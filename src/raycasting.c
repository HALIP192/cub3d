/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:08:54 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/05 18:21:59 by ntitan           ###   ########.fr       */
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
