/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:58:05 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 15:11:41 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_dda(data_t *data)
{
		data->cameraX = 2 * data->x / (double)data->screenWidth - 1;
		data->rayDirX = data->dirX + data->planeX * data->cameraX;
		data->rayDirY = data->dirY + data->planeY * data->cameraX;
		data->mapX = (int)data->posX;
		data->mapY = (int)data->posY;
		data->deltaDistX = (data->rayDirX == 0) ? 1e30 : ft_abs(1 / data->rayDirX);
		data->deltaDistY = (data->rayDirY == 0) ? 1e30 : ft_abs(1 / data->rayDirY);

}

void	init_steps_and_sideDist(data_t *data)
{
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{	
		data->stepY = -1;
		data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
	}

}
