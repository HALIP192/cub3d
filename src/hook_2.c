/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 15:05:55 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/26 19:57:21 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	esc_function(void)
{
	t_mlxdata	*mlxdata;

	mlxdata = mlxdata_global();
	mlx_destroy_image(mlxdata->mlx_ptr, mlxdata->img_ptr);
	mlx_destroy_window(mlxdata->mlx_ptr, mlxdata->mlx_win);
	exit(0);
	return (0);
}

int	key_hook(int key, t_mouseaction *data)
{
	if (key == KEY_W)
		data->mov_forward = 1;
	if (key == KEY_S)
		data->mov_back = 1;
	if (key == KEY_A)
		data->mov_left = 1;
	if (key == KEY_D)
		data->mov_right = 1;
	if (key == KEY_LEFT)
		data->rot_left = 1;
	if (key == KEY_RIGHT)
		data->rot_right = 1;
	if (key == KEY_ESC)
		esc_function();
	return (0);
}

void	print_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("%d\n", data->map[(int)data->posx][(int)data->posy]);
	while (x < data->mapwidth)
	{
		y = 0;
		while (y < data->mapheight)
		{
			if (x == (int)data->posx && y == (int)data->posy)
				printf(GREEN "X " RESET);
			else if (data->map[x][y] > 0 && data->map[x][y] != 1)
				printf(RED "%d " RESET, data->map[x][y]);
			else if (data->map[x][y] == 1)
				printf(BLUE "1 " RESET);
			else if (data->map[x][y] == -1 || data->map[x][y] == 0)
				printf("0 ");
			y++;
		}
		printf("\n");
		x++;
	}
	printf("x = %f\ny = %f\n", data->posx, data->posy);
}
