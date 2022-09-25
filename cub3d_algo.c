/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:54:27 by ntitan            #+#    #+#             */
/*   Updated: 2022/09/25 19:14:51 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
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

int	init_texture(texture_t *data, mlxData_t *mlxData)
{
	int i;

	i = 0;
//	data->texHeight = 64;
//	data->texWidth = 64;
	data->img_ptr = (void **)malloc(sizeof(void *) * 8);
	data->imgs = (int **)malloc(sizeof(int *) * 8);
	data->width = (int *)malloc(sizeof(int) * 8);
	data->height = (int *)malloc(sizeof(int) * 8);
	data->bpp = (int *)malloc(sizeof(int) * 8);
	data->end = (int *)malloc(sizeof(int) * 8);
	data->sl = (int *)malloc(sizeof(int) * 8);
	if (!data->img_ptr || !data->imgs)
		return (1);
	data->img_ptr[0] = mlx_png_file_to_image(mlxData->mlx_ptr, "pics/greystone.png", &data->width[0], &data->height[0]);
	data->img_ptr[1] = mlx_png_file_to_image(mlxData->mlx_ptr, "pics/redbrick.png", &data->width[1], &data->height[1]);
	data->img_ptr[2] = mlx_png_file_to_image(mlxData->mlx_ptr, "pics/wood.png", &data->width[2], &data->height[2]);
	data->img_ptr[3] = mlx_png_file_to_image(mlxData->mlx_ptr, "pics/bluestone.png", &data->width[3], &data->height[3]);
	data->img_ptr[4] = mlx_png_file_to_image(mlxData->mlx_ptr, "pics/colorstone.png", &data->width[4], &data->height[4]);
	data->img_ptr[5] = mlx_png_file_to_image(mlxData->mlx_ptr, "pics/mossy.png", &data->width[5], &data->height[5]);
	data->img_ptr[6] = mlx_png_file_to_image(mlxData->mlx_ptr, "pics/purplestone.png", &data->width[6], &data->height[6]);
	data->img_ptr[7] = mlx_png_file_to_image(mlxData->mlx_ptr, "pics/eagle.png", &data->width[7], &data->height[7]);
	
	while (i < 8)
	{
		if (!data->img_ptr[i])
		{
			printf("Error in init texture from file. step = %d. Stop", i);
			return (1);
		}
		data->imgs[i] = (int *)mlx_get_data_addr(data->img_ptr[i], &data->bpp[i], &data->sl[i], &data->end[i]);
		if (!data->imgs[i])
		{
			printf("Error in texture mlx_get_data_addr() step = %d. Stop.\n", i);
			return (1);
		}
		i++;
	}
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

int	map_init(data_t *data)
{
	int	i;

	i = 0;
	data->mapWidth = 24;
	data->mapHeight = 24;

	data->map = (int **)malloc(sizeof(int *) * data->mapWidth);
	if (!data->map)
		return (1);
	while (i < data->mapHeight)
	{
		data->map[i] = (int *)malloc(sizeof(int) * data->mapHeight);
		if (!data->map[i])
			return (1);
		memcpy(data->map[i], map[i], data->mapHeight * 4);
		int y = 0;
		while (y < data->mapHeight)
		{
			printf("%d ", data->map[i][y]);
			y++;
		}
		printf("\n");
		i++;
	}
	
	data->posX = 22.0;
	data->posY = 12.0;
	data->dirX = -1.0;
	data->dirY = 0.0;
	data->planeX = 0.0;
	data->planeY = 0.66;
	return (0);

}

int	cub3d_init(data_t *map_data, mouseAction_t *mouse, mlxData_t *mlx_data, texture_t *texture)
{

	map_data->screenHeight = 720;//1440;
	map_data->screenWidth = 1080;//2560;

	map_init(map_data);
	init_mouseAction(mouse);

	map_data->time = 0;
	map_data->oldTime = 0;
	
	
	init_mlxData(mlx_data, map_data);

	if (init_texture(texture, mlx_data))
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

mouseAction_t *mouse_st(void)
{
	static mouseAction_t	mouse;

	return (&mouse);
}

int	action_hook(data_t *data)
{
	mouseAction_t	*mouse;

	mouse = mouse_st();
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

	mouse = mouse_st();
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

	mouse = mouse_st();

	dx = (x - mouse->mouse_x) * 0.05;
	dy = y - mouse->mouse_y;
	
	rotate(data, mouse->rotSpeed * dx);

	mouse->mouse_x = x;
	mouse->mouse_y = y;

	return (0);
}



int main(/*data_t data */)
{
	data_t 			data;
	texture_t		*texture;
	mouseAction_t	*mouse;
	mlxData_t		*mlxData;

	mouse = mouse_st();
	texture = texture_global();
	mlxData = mlxData_global();
	if (cub3d_init(&data, mouse, mlxData, texture))
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
