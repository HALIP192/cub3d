/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:47:07 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/27 17:10:51 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate(t_data *data, double angle)
{
	double	buff1;
	double	buff2;

	buff1 = data->dirx;
	data->dirx = data->dirx * cos(angle) - data->diry * sin(angle);
	data->diry = buff1 * sin(angle) + data->diry * cos(angle);
	buff2 = data->planex;
	data->planex = data->planex * cos(angle) - data->planey * sin(angle);
	data->planey = buff2 * sin(angle) + data->planey * cos(angle);
}

void	move_forwrd_bck_right(t_data *data, t_mouseaction *mouse)
{
	if (mouse->mov_forward == 1)
		if (data->map[(int)(data->posx + data->dirx
				* mouse->movespeed)][(int)data->posy] == 0)
			data->posx += data->dirx * mouse->movespeed;
	if (mouse->mov_forward == 1)
		if (data->map[(int)data->posx][(int)(data->posy
			+ data->diry * mouse->movespeed)] == 0)
			data->posy += data->diry * mouse->movespeed;
	if (mouse->mov_back == 1)
		if (data->map[(int)(data->posx - data->dirx
				* mouse->movespeed)][(int)data->posy] == 0)
			data->posx -= data->dirx * mouse->movespeed;
	if (mouse->mov_back == 1)
		if (data->map[(int)data->posx][(int)(data->posy
			- data->diry * mouse->movespeed)] == 0)
			data->posy -= data->diry * mouse->movespeed;
	if (mouse->mov_right == 1)
		if (data->map[(int)data->posx][(int)(data->posy
			- data->dirx * mouse->movespeed)] == 0)
			data->posy -= data->dirx * mouse->movespeed;
	if (mouse->mov_right == 1)
		if (data->map[(int)(data->posx + data->diry
				* mouse->movespeed)][(int)data->posy] == 0)
			data->posx += data->diry * mouse->movespeed;
}

int	action_hook(t_data *data)
{
	t_mouseaction	*mouse;

	mouse = mouse_global();
	move_forwrd_bck_right(data, mouse);
	if (mouse->mov_left == 1)
		if (data->map[(int)(data->posx - data->diry
				* mouse->movespeed)][(int)data->posy] == 0)
			data->posx -= data->diry * mouse->movespeed;
	if (mouse->mov_left == 1)
		if (data->map[(int)data->posx][(int)(data->posy
			+ data->dirx * mouse->movespeed)] == 0)
			data->posy += data->dirx * mouse->movespeed;
	if (mouse->rot_right == 1)
		rotate(data, -(mouse->rotspeed));
	if (mouse->rot_left == 1)
		rotate(data, mouse->rotspeed);
	print_map(data);
	cub3d(data);
	return (0);
}

int	key_hook_release(int key, t_data *data)
{
	t_mouseaction	*mouse;

	(void)data;
	mouse = mouse_global();
	if (key == 13)
		mouse->mov_forward = 0;
	if (key == 1)
		mouse->mov_back = 0;
	if (key == 0)
		mouse->mov_left = 0;
	if (key == 2)
		mouse->mov_right = 0;
	if (key == 123)
		mouse->rot_left = 0;
	if (key == 124)
		mouse->rot_right = 0;
	return (0);
}

int	mouse_action(int x, int y, t_data *data)
{
	double			dx;
	double			dy;
	t_mouseaction	*mouse;

	mouse = mouse_global();
	dx = (x - mouse->mouse_x) * 0.05;
	dy = y - mouse->mouse_y;
	rotate(data, mouse->rotspeed * (-dx));
	mouse->mouse_x = x;
	mouse->mouse_y = y;
	return (0);
}
