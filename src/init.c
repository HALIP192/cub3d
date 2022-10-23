/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:49:27 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/23 20:42:17 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mouseAction(mouseAction_t *data)
{
	data->mov_forward = 0;
	data->mov_back = 0;
	data->mov_left = 0;
	data->mov_right = 0;
	data->rot_left = 0;
	data->rot_right = 0;
	data->moveSpeed = 0.07;
	data->rotSpeed = 0.03;
	data->mouse_x = 0;
	data->mouse_y = 0;

}

void	init_mlxData(mlxData_t *data, data_t *map_data)
{
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, map_data->screenWidth, map_data->screenHeight, "cub3d");
	
	int sn;
	data->img_ptr = mlx_new_image(data->mlx_ptr, map_data->screenWidth, map_data->screenHeight);
	data->image = (int *)mlx_get_data_addr(data->img_ptr, &sn, &map_data->line_lenght, &sn);

}

int	init_position(data_t *data, char *src, int j, int i)
{
	if (src[i] == 'N')
	{
		data->dirX = -1.0;
		data->dirY = 0.0;
	} else if (src[i] == 'W')
	{
		data->dirX = 0.0;
		data->dirY = 1.0;
	} else if (src[i] == 'E')
	{
		data->dirX = 0.0;
		data->dirY = -1.0;
	} else if (src[i] == 'S')
	{
		data->dirX = 1.0;
		data->dirY = 0.0;
	} else
		return (1);
	if (i >= data->mapWidth || i <= 0 ||
		j >= data->mapHeight || j <= 0)
		return (1);
	data->posX = (double)i;
	data->posY = (double)j;
	data->planeX = 0.0;
	data->planeY = 0.66;
	data->map[j][i]  = 0;
	return (0);
}

list_t	*init_screen_and_map(data_t *data, int fd)
{
	list_t *list_head;
	list_t *list_cur;
	int width;
	int height;
	int height_max;
	
	width = 0;
	height_max = 0;
	list_head = ft_lstnew(get_next_line(fd));
	list_cur = list_head;
	while (((char *)list_cur->content)[0] == '\n')
	{
		free(list_cur->content);
		list_cur->content = get_next_line(fd);
		if (!list_cur->content)
		{
			printf("Map error.\n");
			return NULL;
		}
	}
	while (list_cur->content)
	{
		height = ft_strlen(list_cur->content) - 1;
		if (height > height_max)
			height_max = height;
		width++;
		list_cur->next = ft_lstnew(get_next_line(fd));
		list_cur = list_cur->next;
	}
	free(list_cur);
	data->mapWidth = width;
	data->mapHeight = height_max;
	data->screenHeight = 720;//1440;
	data->screenWidth = 1080;//2560;
	return (list_head);
}

int	map_init(data_t *data, int fd)
{
	int		i;
	list_t	*map;

	i = 0;
	map = init_screen_and_map(data, fd);
	data->map = (int **)malloc(sizeof(int *) * data->mapWidth);
	if (!data->map)
		return (1);
	while (i < data->mapWidth)
	{
		data->map[i] = (int *)malloc(sizeof(int) * data->mapHeight);
		if (!data->map[i])
			return (1);
		if (lstcpy(data, map->content, i))
			return (1);
		int y = 0;
		while (y < data->mapHeight)
		{
			if (data->map[i][y] == -1)
				printf("0 ");
			else
				printf("%d ", data->map[i][y]);
			y++;
		}
		printf("\n");
		i++;
		map = map->next;
	}
	if (validate_map(data))
		return (1);
	return (0);
}

int	cub3d_init(data_t *map_data, char **argv)
{
	mouseAction_t	*mouse;
	mlxData_t		*mlx_data;
	texture_t		*texture;
	int				fd;
	char			***texture_split;

	mouse = mouse_global();
	mlx_data = mlxData_global();
	texture = texture_global();
	
	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		printf("Cann't open file.\n");
		exit(1);
	}
	texture_split = get_texture_info(fd);
	if (!texture_split)
	{
		printf("Invalid initialisation map.\n");
		close(fd);
		exit(1);
	}
	if (map_init(map_data, fd))
	{
		printf("Invalid map.\n");
		close(fd);
		exit(1);
	}
	init_mouseAction(mouse);

	/* map_data->time = 0; */
	/* map_data->oldTime = 0; */
	
	
	init_mlxData(mlx_data, map_data);

	if (init_texture(texture, mlx_data, texture_split))
	{
		printf("Error while struct initialisation.Stop.\n");
		exit(1);
	}
	return (0);
}

