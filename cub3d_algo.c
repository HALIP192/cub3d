/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:54:27 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/01 21:54:10 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "stdio.h"
#include "math.h"
#include <string.h>
#include "printf_colors.h"
/* #define mapWidth 24 */
/* #define mapHeight 24 */
/* #define screenHeight 640 */
/* #define screenWidth 480 */

/* #define RED 0x00ff0000 */
/* #define GREEN 0x0000ff00 */
/* #define BLUE 0x000000ff */
/* #define YELLOW 0x00ffff00 */

#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125
#define KEY_UP 126


/* int map[mapWidth][mapHeight] = */ 
/* { */
/*   {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}, */
/*   {1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3} */
/* }; */

int map[24][24] = 
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
#define MOUSE_LEFT 1
#define MOUSE_WHEEL 2
#define MOUSE_RIGHT 3
#define MOUSE_WHEEL_DOWN 4
#define MOUSE_WHEEL_UP 5

#define key_press 2
#define key_release 3
#define mouse_press 4
#define mouse_release 5
#define mouse_move 6
#define mouse_enter_window 7
#define mouse_leave_window 8
#define focus_in 9
#define focus_out 10
#define window_close 17

double ft_abs(double num)
{
	return num > 0 ? num : num * (-1);
}

texture_t	*texture_global(void)
{
	static texture_t	texture = {};

	return (&texture);
}

mlxData_t	*mlxData_global(void)
{
	static mlxData_t	mlxData;

	return (&mlxData);
}

void	data_cleaner(data_t *data)
{
	int	i;

	i = 0;
	while (i < data->mapHeight)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_texture(texture_t *data, mlxData_t *mlxData)
{
	int	i;

	i = 0;
	while (i < 0)
	{
		mlx_destroy_image(mlxData->mlx_ptr, data->imgs[i]);
		free(data->imgs[i]);
		i++;
	}
	free(data->img_ptr);
	free(data->imgs);
	free(data->height);
	free(data->width);
	free(data->bpp);
	free(data->end);
	free(data->sl);
}

int	ft_close_window(data_t *data)
{
	mlxData_t	*mlxData;

	mlxData = mlxData_global();
	mlx_destroy_image(mlxData->mlx_ptr, mlxData->img_ptr);
	mlx_destroy_window(mlxData->mlx_ptr, mlxData->mlx_win);
	data_cleaner(data);
	exit(0);
	return (0);
}

int	init_floor_ceil_colors(texture_t *texture, char ***texture_split, int i)
{
	int		j;
	char	**buff1;

	if (!texture_split[i][1])
	{
		printf("Error in intialize file. Param number = %d\n", i);
		return (1);
	}
	buff1 = ft_split(texture_split[i][1], ',');
	j = 0;
	while (buff1[j])
	{
		if (texture_split[i][0][0] == 'F')
			texture->floor = ft_atoi(buff1[j]) << (8 * (int)ft_abs((i - 2)));
		if (texture_split[i][0][0] == 'C')
			texture->floor = ft_atoi(buff1[j]) << (8 * (int)ft_abs((i - 2)));
		j++;
		if (j > 3)
		{
			printf("Error Floor and Ceil colors must have only 3 haracteristic.\n");
			return (1);
		}
	}
	return (0);
}

int	png_to_img(texture_t *data, mlxData_t *mlxData, char ***texture_split, int i)
{
	if (texture_split[i][0][0] == 'N' && texture_split[i][0][1] == 'O')
	{
		data->img_ptr[0] = mlx_png_file_to_image(mlxData->mlx_ptr, texture_split[i][1], &data->width[i], &data->height[i]);
		if (!data->img_ptr[0])
			return (1);
	} else if (texture_split[i][0][0] == 'S' && texture_split[i][0][1] == 'O')
	{
		data->img_ptr[1] = mlx_png_file_to_image(mlxData->mlx_ptr, texture_split[i][1], &data->width[i], &data->height[i]);
		if (!data->img_ptr[1])
			return (1);
	} else if (texture_split[i][0][0] == 'W' && texture_split[i][0][1] == 'E')
	{
		data->img_ptr[2] = mlx_png_file_to_image(mlxData->mlx_ptr, texture_split[i][1], &data->width[i], &data->height[i]);
		if (!data->img_ptr[2])
			return (1);
	} else if (texture_split[i][0][0] == 'E' && texture_split[i][0][1] == 'A')
	{
		data->img_ptr[3] = mlx_png_file_to_image(mlxData->mlx_ptr, texture_split[i][1], &data->width[i], &data->height[i]);
		if (!data->img_ptr[3])
			return (1);
	} else if (texture_split[i][0][0] == 'F')
		return (init_floor_ceil_colors(data, texture_split, i));
	else if (texture_split[i][0][0] == 'C')
		return (init_floor_ceil_colors(data, texture_split, i));
	else
	{
		printf("Invalid init file \n");
		return (1);
	}
	return (0);
}

void	free_texture_helper(char ***texture_split)
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (texture_split[i][j])
		{
			free(texture_split[i][j]);
			j++;
		}
		free(texture_split[i]);
		i++;
	}
	free(texture_split);
}

int	get_textures_imgs(texture_t *data, char ***texture_split, int i)
{
	if (texture_split[i][0][0] == 'N' && texture_split[i][0][1] == 'O')
	{
		data->imgs[0] =	(int *)mlx_get_data_addr(data->img_ptr[0], &data->bpp[0], &data->sl[0], &data->end[0]);
		if (!data->imgs[0])
			return (1);
	} else if (texture_split[i][0][0] == 'S' && texture_split[i][0][1] == 'O')
	{
		data->imgs[1] =	(int *)mlx_get_data_addr(data->img_ptr[1], &data->bpp[1], &data->sl[1], &data->end[1]);
		if (!data->imgs[1])
			return (1);
	} else if (texture_split[i][0][0] == 'W' && texture_split[i][0][1] == 'E')
	{
		data->imgs[2] =	(int *)mlx_get_data_addr(data->img_ptr[2], &data->bpp[2], &data->sl[2], &data->end[2]);
		if (!data->imgs[2])
			return (1);
	} else if (texture_split[i][0][0] == 'E' && texture_split[i][0][1] == 'A')
	{
		data->imgs[3] =	(int *)mlx_get_data_addr(data->img_ptr[3], &data->bpp[3], &data->sl[3], &data->end[3]);
		if (!data->imgs[3])
			return (1);
	}
	return (0);
}

int	init_texture(texture_t *data, mlxData_t *mlxData, char ***texture_split)
{
	int i;

	i = 0;
	data->img_ptr = (void **)malloc(sizeof(void *) * 4);
	data->imgs = (int **)malloc(sizeof(int *) * 4);
	data->width = (int *)malloc(sizeof(int) * 4);
	data->height = (int *)malloc(sizeof(int) * 4);
	data->bpp = (int *)malloc(sizeof(int) * 4);
	data->end = (int *)malloc(sizeof(int) * 4);
	data->sl = (int *)malloc(sizeof(int) * 4); 
	
	while (i < 6)
	{
		if (png_to_img(data, mlxData, texture_split, i))
			return (1);
		if (get_textures_imgs(data, texture_split, i))
		{
			printf("Error in texture mlx_get_data_addr() step = %d. Stop.\n", i);
			return (1);
		}
		i++;
	}
	free_texture_helper(texture_split);
	return (0);
}

void	init_mouseAction(mouseAction_t *data)
{
	data->mov_forward = 0;
	data->mov_back = 0;
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
	data->posX = (double)i;
	data->posY = (double)j;
	data->planeX = 0.0;
	data->planeY = 0.66;
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

int lstcpy(data_t *data, char *src, int j)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n')
	{
		if (ft_isdigit(src[i]))
			data->map[j][i] = src[i] - '0';
		else if (src[i] != ' ')
		{
			if (init_position(data, src, j, i))
				return (1);
		}else
			data->map[j][i] = -1;
		i++;
	}
	return (0);

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
			printf("%d ", data->map[i][y]);
			y++;
		}
		printf("\n");
		i++;
		map = map->next;
	}
	return (0);
}

mouseAction_t *mouse_global(void)
{
	static mouseAction_t	mouse;

	return (&mouse);
}

int	is_line_valid(char *line)
{
	if ((line[0] == 'N' && line[1] == 'O') ||
		(line[0] == 'S' && line[1] == 'O') ||
		(line[0] == 'W' && line[1] == 'E') ||
		(line[0] == 'E' && line[1] == 'A') ||
		(line[0] == 'F') || (line[0] == 'C'))
		return (1);
	return (0);
}

char ***get_texture_info(int fd)
{
	char	***mas;
	char	*line;
	int		cnt;

	mas = (char ***)malloc(sizeof(char **) * 7);
	if (!mas)
	{
		printf("LOL\n");
	}
	mas[6] = NULL;
	line = get_next_line(fd);
	cnt = 0;
	while (cnt < 6 && line)
	{
		if (line[0] == '\n')
		{
			line = get_next_line(fd);
			continue;
		}
		if (is_line_valid(line))
		{
			mas[cnt] = ft_split(line, ' ');
			printf("%s", mas[cnt][1]);
			cnt++;
		} else
			return (NULL);
		if (cnt < 6)
			line = get_next_line(fd);
	}
	return (mas);
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
		return (1);
	}
	texture_split = get_texture_info(fd);
	if (!texture_split)
	{
		printf("Invalit initialisation map.\n");
		return (1);
	}
	map_init(map_data, fd);
	init_mouseAction(mouse);

	/* map_data->time = 0; */
	/* map_data->oldTime = 0; */
	
	
	init_mlxData(mlx_data, map_data);

	if (init_texture(texture, mlx_data, texture_split))
	{
		printf("Error while struct initialisation.Stop.\n");
		exit(12);
	}
	return (0);
}

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

void	Dda(data_t *data)
{
	int	hit = 0;

	while (hit == 0)
	{
		if (data->sideDistX < data->sideDistY)		
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		if (data->map[data->mapX][data->mapY] > 0) 
			hit = 1;
	}
		
	if (data->side == 0)
		data->WallDist = (data->mapX - data->posX + (1 - data->stepX) / 2) / data->rayDirX;
	else
		data->WallDist = (data->mapY - data->posY + (1 - data->stepY) / 2)  / data->rayDirY;
}

void	set_draw_starts(data_t *data)
{
	data->lineHeight = (int)(data->screenHeight / data->WallDist);
	data->drawStart = -data->lineHeight / 2 + data->screenHeight / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + data->screenHeight / 2;
	if (data->drawEnd >= data->screenHeight)
		data->drawEnd = data->screenHeight - 1;
}

int	get_texX(data_t *data, texture_t *texture)
{
	int		texNum;
	double	wallX;
	int		texX;

	texNum = data->map[data->mapX][data->mapY] - 1;
	if (data->side == 0)
		wallX = data->posY + data->WallDist * data->rayDirY;
	else
		wallX = data->posX + data->WallDist * data->rayDirX;
	wallX -= floor(wallX);
	texX = (int)(wallX * (double)(texture->width[texNum]));
	if (data->side == 0 && data->rayDirX > 0)
		texX = texture->width[texNum] - texX - 1;
	if (data->side == 1 && data->rayDirY < 0)
		texX = texture->width[texNum] - texX - 1;
	return (texX);
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
			if (data->y < (data->screenHeight) && data->y < data->drawStart)
				mlxData->image[data->y * (data->line_lenght / 4) + data->x] = SKY;
			if (data->y < data->screenHeight && data->y > data->drawEnd)
				mlxData->image[data->y * (data->line_lenght / 4) + data->x] = BITUMEN;
			if (data->y >= data->drawStart && data->y <= data->drawEnd)
			{
				texY = (int)texPos & (texture->height[texNum] - 1);
				texPos += step;
				if (data->side == 1)
					mlxData->image[data->y * (data->line_lenght / 4) + data->x] = (texture->imgs[texNum][texture->height[texNum] * texY + texX] >> 1);
				mlxData->image[data->y * (data->line_lenght / 4) + data->x] = texture->imgs[texNum][texture->height[texNum] * texY + texX];
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
		texNum = data->map[data->mapX][data->mapY] - 1;
		raycasting(data, texture, mlxData, texNum);
		data->x++;
	
	}
	mlx_put_image_to_window(mlxData->mlx_ptr, mlxData->mlx_win, mlxData->img_ptr, 0, 0);
}

int	key_hook(int key, mouseAction_t *data)
{
		if (key == 13)
			data->mov_forward = 1;
		if (key == 1)
			data->mov_back = 1;
		if (key == 0)
			data->rot_left = 1;
		if (key == 2)
			data->rot_right = 1;
	return (0);
}

void	print_map(data_t *data)
{
	printf("%d\n",data->map[(int)data->posX][(int)data->posY]);
	int x = 0;
	int y = 0;
	while (x < data->mapWidth)
	{
		y = 0;
		while(y < data->mapHeight)
		{
			if (x == (int)data->posX && y == (int)data->posY)
				printf( GREEN "X " RESET );
			else if (data->map[x][y] > 0 && data->map[x][y] != 1)
				printf(RED "%d " RESET, data->map[x][y]);
			else if (data->map[x][y] == 1)
				printf(BLUE "1 " RESET);
			else
				printf("%d ",data->map[x][y]);
			y++;
		}
		printf("\n");
		x++;
	}
	printf("x = %d\ny = %d\n", (int)data->posX, (int)data->posY);
}



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



int	action_hook(data_t *data)
{
	mouseAction_t	*mouse;

	mouse = mouse_global();
	if (mouse->mov_forward == 1)
	{
		if (data->map[(int)(data->posX + data->dirX * mouse->moveSpeed)][(int)data->posY] == 0)
			data->posX += data->dirX * mouse->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY + data->dirY * mouse->moveSpeed)] == 0)
			data->posY += data->dirY * mouse->moveSpeed;
		print_map(data);
	}
	if (mouse->mov_back == 1)
	{
		if (data->map[(int)(data->posX - data->dirX * mouse->moveSpeed)][(int)data->posY] == 0)
			data->posX -= data->dirX * mouse->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY - data->dirY * mouse->moveSpeed)] == 0)
			data->posY -= data->dirY * mouse->moveSpeed;
		print_map(data);
	}
	if (mouse->rot_right == 1)
		rotate(data, -(mouse->rotSpeed));
	if (mouse->rot_left == 1)
		rotate(data, mouse->rotSpeed);
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
		mouse->rot_left = 0;
	if (key == 2)
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



int main(int argc, char **argv)
{
	data_t 			data;
	texture_t		*texture;
	mouseAction_t	*mouse;
	mlxData_t		*mlxData;

	mouse = mouse_global();
	texture = texture_global();
	mlxData = mlxData_global();
	if (cub3d_init(&data, argv))
	{
		printf("Malloc error in cub3d_init(). Stop...\n");
		exit(12);
	}
	cub3d(&data);
//	}
//	mlx_key_hook(data->mlx_win, key_act, data);


	mlx_hook(mlxData->mlx_win, 2, 0, key_hook, mouse);
	mlx_hook(mlxData->mlx_win, 3, 0, key_hook_release, mouse);
	mlx_hook(mlxData->mlx_win, 17, 0, ft_close_window, &data);
	mlx_hook(mlxData->mlx_win, mouse_move, 0, mouse_action, &data);

	mlx_loop_hook(mlxData->mlx_ptr, action_hook, &data);
	mlx_loop(mlxData->mlx_ptr);
	return 0;
}
