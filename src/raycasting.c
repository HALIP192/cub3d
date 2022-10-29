/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:08:54 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 15:11:44 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static inline void floor_ceil_draw(data_t *data, mlxData_t *mlxData, texture_t *texture)
{
	if (data->y < (data->screenHeight) && data->y < data->drawStart)
		mlxData->image[data->y * (data->line_lenght / 4) + data->x] = texture->ceil;//SKY;
	if (data->y < data->screenHeight && data->y > data->drawEnd)
		mlxData->image[data->y * (data->line_lenght / 4) + data->x] = texture->floor;
}

void	raycasting(data_t *data, texture_t *texture, mlxData_t *mlxData, int texNum)
{
		double	step;
		double	texPos;
		int		texY;
		int		texX;

		texX = get_texX(data, texture);
		step = 1.0 * texture->height[texNum] / data->lineHeight;
		texPos = (data->drawStart - data->screenHeight / 2 + data->lineHeight / 2) * step;
		data->y = 0;
		while (data->y < data->screenHeight)
		{
			floor_ceil_draw(data, mlxData, texture);
			if (data->y >= data->drawStart && data->y <= data->drawEnd)
			{
				texY = (int)texPos & (texture->height[texNum] - 1);
				texPos += step;
				if (data->side == 1)
					mlxData->image[data->y * (data->line_lenght / 4) + data->x] =
						(texture->imgs[texNum][texture->height[texNum] * texY + texX] >> 1);
				else
					mlxData->image[data->y * (data->line_lenght / 4) + data->x] = 
						texture->imgs[texNum][texture->height[texNum] * texY + texX];
			}
			data->y++;
		}
}

void	cub3d(data_t *data)
{	
	int			texX;
	int			texNum;
	texture_t	*texture;
	mlxData_t	*mlxData;

	data->x = 0;
	texture = texture_global();
	mlxData = mlxData_global();
	while (data->x < data->screenWidth)
	{
		init_dda(data);
		init_steps_and_sideDist(data);
		Dda(data);
		set_draw_starts(data);
		texNum = data->corner;
		raycasting(data, texture, mlxData, texNum);
		data->x++;
	
	}
	mlx_put_image_to_window(mlxData->mlx_ptr, mlxData->mlx_win, mlxData->img_ptr, 0, 0);
}
