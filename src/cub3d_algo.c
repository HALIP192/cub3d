/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:54:27 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 20:33:11 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static inline void	dda_step(t_data *data)
{
	if (data->sidedistx < data->sidedisty)
	{
		data->sidedisty += data->deltadisty;
		data->mapx += data->stepx;
		data->side = 0;
		if (data->posx >= data->mapx)
			data->corner = 1;
		else
			data->corner = 0;
	}
	else
	{
		data->sidedisty += data->deltadisty;
		data->mapy += data->stepy;
		data->side = 1;
		if (data->posy >= data->mapy)
			data->corner = 2;
		else
			data->corner = 3;
	}
}

void	dda(t_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		dda_step(data);
		if (data->map[(int)data->mapx][(int)data->mapy] > 0)
			hit = 1;
	}
	if (data->side == 0)
		data->walldist = (data->mapx - data->posx + (1 - data->stepx) / 2)
			/ data->raydirx;
	else
		data->walldist = (data->mapy - data->posy + (1 - data->stepy) / 2)
			/ data->raydiry;
}

void	set_draw_starts(t_data *data)
{
	data->lineheight = (int)(data->screenheight / data->walldist);
	data->drawstart = -data->lineheight / 2 + data->screenheight / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + data->screenheight / 2;
	if (data->drawend >= data->screenheight)
		data->drawend = data->screenheight - 1;
}

int	get_texx(t_data *data, t_texture *texture)
{
	int		texnum;
	double	wallx;
	int		texx;

	texnum = data->corner;
	if (data->side == 0)
		wallx = data->posy + data->walldist * data->raydiry;
	else
		wallx = data->posx + data->walldist * data->raydirx;
	wallx -= floor(wallx);
	texx = (int)(wallx * (double)(texture->width[texnum]));
	if (data->side == 0 && data->raydirx > 0)
		texx = texture->width[texnum] - texx - 1;
	if (data->side == 1 && data->raydiry < 0)
		texx = texture->width[texnum] - texx - 1;
	return (texx);
}
