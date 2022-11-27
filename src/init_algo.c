/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:58:05 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/27 20:11:41 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_dda(t_data *data)
{
	data->camerax = 2 * data->x / (double)data->screenwidth - 1;
	data->raydirx = data->dirx + data->planex * data->camerax;
	data->raydiry = data->diry + data->planey * data->camerax;
	data->mapx = (int)data->posx;
	data->mapy = (int)data->posy;
	if (fabs(data->raydirx) < 0.01)
		data->deltadistx = 1e30;
	else
		data->deltadistx = ft_abs(1 / data->raydirx);
	if (fabs(data->raydiry) < 0.01)
		data->deltadisty = 1e30;
	else
		data->deltadisty = ft_abs(1 / data->raydiry);
}

void	init_steps_and_sidedist(t_data *data)
{
	if (data->raydirx < 0)
	{
		data->stepx = -1;
		data->sidedistx = (data->posx - data->mapx) * data->deltadistx;
	}
	else
	{
		data->stepx = 1;
		data->sidedistx = (data->mapx + 1.0 - data->posx) * data->deltadistx;
	}
	if (data->raydiry < 0)
	{	
		data->stepy = -1;
		data->sidedisty = (data->posy - data->mapy) * data->deltadisty;
	}
	else
	{
		data->stepy = 1;
		data->sidedisty = (data->mapy + 1.0 - data->posy) * data->deltadisty;
	}
}
