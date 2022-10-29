/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:47:07 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 17:31:47 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate(data_t *data, double angle)
{
	double buff1;
	double buff2;

	buff1 = data->dirX;
	data->dirX = data->dirX * cos(angle) - data->dirY * sin(angle);
	data->dirY = buff1 * sin(angle) + data->dirY * cos(angle);
	buff2 = data->planeX;
	data->planeX = data->planeX * cos(angle) - data->planeY * sin(angle);
	data->planeY = buff2 * sin(angle) + data->planeY * cos(angle);
}

void move_forwrd_bck(data_t *data, mouseAction_t *mouse)
{
	if (mouse->mov_forward == 1)
	{
		if (data->map[(int)(data->posX + data->dirX * mouse->moveSpeed)][(int)data->posY] == 0)
			data->posX += data->dirX * mouse->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY + data->dirY * mouse->moveSpeed)] == 0)
			data->posY += data->dirY * mouse->moveSpeed;
	}
	if (mouse->mov_back == 1)
	{
		if (data->map[(int)(data->posX - data->dirX * mouse->moveSpeed)][(int)data->posY] == 0)
			data->posX -= data->dirX * mouse->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY - data->dirY * mouse->moveSpeed)] == 0)
			data->posY -= data->dirY * mouse->moveSpeed;
	}
}

int	action_hook(data_t *data)
{
	mouseAction_t	*mouse;

	mouse = mouse_global();
	move_forwrd_bck(data, mouse);	
	if (mouse->mov_right == 1)
	{
		if (data->map[(int)data->posX][(int)(data->posY - data->dirX * mouse->moveSpeed)] == 0)
			data->posY -= data->dirX * mouse->moveSpeed;
		if (data->map[(int)(data->posX + data->dirY * mouse->moveSpeed)][(int)data->posY] == 0)
			data->posX += data->dirY * mouse->moveSpeed;
	}
	if (mouse->mov_left == 1)
		if (data->map[(int)(data->posX - data->dirY * mouse->moveSpeed)][(int)data->posY] == 0)
			data->posX -= data->dirY * mouse->moveSpeed; 
	if (mouse->mov_left == 1)
		if (data->map[(int)data->posX][(int)(data->posY + data->dirX * mouse->moveSpeed)] == 0)
			data->posY += data->dirX * mouse->moveSpeed;
	if (mouse->rot_right == 1)
		rotate(data, -(mouse->rotSpeed));
	if (mouse->rot_left == 1)
		rotate(data, mouse->rotSpeed);
	print_map(data);
	cub3d(data);
	return (0);
}

int	key_hook_release(int key, data_t *data)
{
	mouseAction_t	*mouse;

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

int mouse_action(int x, int y, data_t *data)
{
	double			dx;
	double			dy;
	mouseAction_t	*mouse;

	mouse = mouse_global();

	dx = (x - mouse->mouse_x) * 0.05;
	dy = y - mouse->mouse_y;
	
	rotate(data, mouse->rotSpeed * (-dx));

	mouse->mouse_x = x;
	mouse->mouse_y = y;

	return (0);
}
