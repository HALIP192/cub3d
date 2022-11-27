/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:49:27 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/27 21:29:34 by ntitan           ###   ########.fr       */
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
	(void)src;
	data->posx = (double)i;
	data->posy = (double)j;
	data->planex = 0.0;
	data->planey = 0.66;
	data->map[j][i] = 0;
	return (0);
}

int	init_position(t_data *data, char *src, int j, int i)
{
	data->dirx = -1.0;
	data->diry = 0.0;
	if (src[i] == 'N')
		data->init_rotation = 0.;
	else if (src[i] == 'W')
		data->init_rotation = M_PI / 2.;
	else if (src[i] == 'E')
		data->init_rotation = -(M_PI / 2.);
	else if (src[i] == 'S')
		data->init_rotation = M_PI / 1.;
	else
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
		exit(printf("fail open file %s %s:%d.\n", argv[1], __FILE__, __LINE__));
	texture_split = get_texture_info(fd);
	if (!texture_split || map_init(map_data, fd))
	{
		printf("Invalid initialisation map. %s:%d\n", __FILE__, __LINE__);
		close(fd);
		exit(1);
	}
	init_mouse_action(mouse);
	init_mlxdata(mlx_data, map_data);
	if (init_texture(texture, mlx_data, texture_split))
		exit(printf("Error while struct initialisation.Stop. %s:%d\n",
				__FILE__, __LINE__));
	return (0);
}
