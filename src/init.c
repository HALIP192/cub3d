/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:49:27 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 20:49:30 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mouse_action(t_mouseaction *data)
{
	data->mov_forward = 0;
	data->mov_back = 0;
	data->mov_left = 0;
	data->mov_right = 0;
	data->rot_left = 0;
	data->rot_right = 0;
	data->movespeed = 0.07;
	data->rotspeed = 0.03;
	data->mouse_x = 0;
	data->mouse_y = 0;
}

void	init_mlxdata(t_mlxdata *data, t_data *map_data)
{
	int	sn;

	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, map_data->screenwidth,
			map_data->screenheight, "cub3d");
	data->img_ptr = mlx_new_image(data->mlx_ptr, map_data->screenwidth,
			map_data->screenheight);
	data->image = (int *)mlx_get_data_addr(data->img_ptr, &sn,
			&map_data->line_lenght, &sn);
}

static inline int	init_position2(t_data *data, char *src, int j, int i)
{
	data->posx = (double)i;
	data->posy = (double)j;
	data->planex = 0.0;
	data->planey = 0.66;
	data->map[j][i] = 0;
	return (0);
}

int	init_position(t_data *data, char *src, int j, int i)
{
	if (src[i] == 'N')
	{
		data->dirx = -1.0;
		data->diry = 0.0;
	}
	else if (src[i] == 'W')
	{
		data->dirx = 0.0;
		data->diry = 1.0;
	}
	else if (src[i] == 'E')
	{
		data->dirx = 0.0;
		data->diry = -1.0;
	}
	else if (src[i] == 'S')
	{
		data->dirx = 1.0;
		data->diry = 0.0;
	}
	else
		return (1);
	if (i >= data->mapwidth || i <= 0 || j >= data->mapheight || j <= 0)
		return (1);
	return (init_position2(data, src, j, i));
}

int	cub3d_init(t_data *map_data, char **argv)
{
	t_mouseaction	*mouse;
	t_mlxdata		*mlx_data;
	t_texture		*texture;
	int				fd;
	char			***texture_split;

	mouse = mouse_global();
	mlx_data = mlxdata_global();
	texture = texture_global();
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		exit(printf("Cann't open file.\n"));
	texture_split = get_texture_info(fd);
	if (!texture_split || map_init(map_data, fd))
	{
		printf("Invalid initialisation map.\n");
		close(fd);
		exit(1);
	}
	init_mouse_action(mouse);
	init_mlxdata(mlx_data, map_data);
	if (init_texture(texture, mlx_data, texture_split))
		exit(printf("Error while struct initialisation.Stop.\n"));
	return (0);
}
