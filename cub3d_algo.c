/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:54:27 by ntitan            #+#    #+#             */
/*   Updated: 2022/09/18 20:10:13 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include "math.h"
#include <string.h>
/* #define mapWidth 24 */
/* #define mapHeight 24 */
/* #define screenHeight 640 */
/* #define screenWidth 480 */

#define RED 0x00ff0000
#define GREEN 0x0000ff00
#define BLUE 0x000000ff
#define YELLOW 0x00ffff00

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

double ft_abs(double num)
{
	return num > 0 ? num : num * (-1);
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

int	ft_close_window(data_t *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	data_cleaner(data);
	exit(0);
	return (0);
}

int	cub3d_init(data_t *data)
{
	int i;

	i = 0;
	data->mapWidth = 24;
	data->mapHeight = 24;
	data->screenHeight = 1440;
	data->screenWidth = 2560;
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
	data->initial_dirX = -1.0;
	data->initial_dirY = 0.0;
	data->dirX = data->initial_dirX;
	data->dirY = data->initial_dirY;
	data->initial_planeX = 0.0;
	data->initial_planeY = 0.66;
	data->planeX = data->initial_planeX;
	data->planeY = data->initial_planeY;
	data->moveSpeed = 0.07;
	data->rotSpeed = 0.03;

	data->mov_forward = 0;
	data->mov_back = 0;
	data->rot_left = 0;
	data->rot_right = 0;

	data->time = 0;
	data->oldTime = 0;
	
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->screenWidth, data->screenHeight, "cub3d");

	int sn;
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->screenWidth, data->screenHeight);
	data->image = (int *)mlx_get_data_addr(data->img_ptr, &sn, &data->line_lenght, &sn);
	return (0);
}


void	cub3d(data_t *data)
{		
	data->x = 0;
	while (data->x < data->screenWidth)
	{
		data->cameraX = 2 * data->x / (double)data->screenWidth - 1;
		data->rayDirX = data->dirX + data->planeX * data->cameraX;
		data->rayDirY = data->dirY + data->planeY * data->cameraX;
		data->mapX = (int)data->posX;
		data->mapY = (int)data->posY;
		data->deltaDistX = (data->rayDirX == 0) ? 1e30 : ft_abs(1 / data->rayDirX);
		data->deltaDistY = (data->rayDirY == 0) ? 1e30 : ft_abs(1 / data->rayDirY);
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

		data->lineHeight = (int)(data->screenHeight / data->WallDist);
		data->drawStart = -data->lineHeight / 2 + data->screenHeight / 2;
		if (data->drawStart < 0)
			data->drawStart = 0;
		data->drawEnd = data->lineHeight / 2 + data->screenHeight / 2;
		if (data->drawEnd >= data->screenHeight)
			data->drawEnd = data->screenHeight - 1;
				
		if (data->map[data->mapX][data->mapY] == 0)
			data->color = 0x00ffff00; //yellow
		if (data->map[data->mapX][data->mapY] == 1)
			data->color = 0x00ff0000; // red
		if (data->map[data->mapX][data->mapY] == 2)
			data->color = 0x0000ff00; // green
		if (data->map[data->mapX][data->mapY] == 3)
			data->color = 0x000000ff; // blue
		if (data->map[data->mapX][data->mapY] == 4)
			data->color = 0x00ffffff; // white	
		if (data->map[data->mapX][data->mapY] == 5)
			data->color = 0x34495E;
	
		if (data->side == 1)
			data->color /= 2;
//=======================================DROW_LINE=========================

		/*int y1;
		int zoom;
		zoom = 15;
		y = 0;
		y1 = y + 1;
		y *= zoom;
		y1 *= zoom;
		double y_step;
		y_step = ft_abs((double)(y1 - y));*/;
		int zoom = 30;
		data->y = 0;
		while (data->y < data->screenHeight)
		{
			if (data->y < (data->screenHeight) && data->y < data->drawStart)
			{
				//mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, 0x00ffff00);
				data->image[data->y * (data->line_lenght / 4) + data->x] = 0x87CEEB;
			}
			if (data->y < data->screenHeight && data->y > data->drawEnd)
			{
				data->image[data->y * (data->line_lenght / 4) + data->x] = 0x34495E;
			}
			if (data->y >= data->drawStart && data->y <= data->drawEnd)
			{
				/* mlx_pixel_put(data->mlx_ptr, data->mlx_win, x, y, data->color); */
				data->image[data->y * (data->line_lenght / 4) + data->x] = data->color;
			}
			data->y++;
		}
		//char s;
		//read(1, &s, 1);
		data->x++;
	
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img_ptr, 0, 0);
}

int key_act(int key, data_t *data)
{
	double buff1;
	double buff2;

	printf("key: %d\n", key);
	if (key == KEY_UP)
	{
		if (data->map[(int)(data->posX + data->dirX * data->moveSpeed)][(int)data->posY] == 0)
			data->posX += data->dirX * data->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY + data->dirY * data->moveSpeed)] == 0)
			data->posY += data->dirY * data->moveSpeed;
		printf("%d\n",data->map[(int)data->posX][(int)data->posY]);
		int x = 0;
		int y = 0;
		while (x < data->mapWidth)
		{
			y = 0;
			while(y < data->mapHeight)
			{
				printf("%d ",data->map[x][y]);
				y++;
			}
			printf("\n");
			x++;
		}
		printf("x = %d\ny = %d\n", (int)data->posX, (int)data->posY);
	}
	if (key == KEY_DOWN)
	{
		if (data->map[(int)(data->posX - data->dirX * data->moveSpeed)][(int)data->posY] == 0)
			data->posX -= data->dirX * data->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY - data->dirY * data->moveSpeed)] == 0)
			data->posY -= data->dirY * data->moveSpeed;
	}
	if (key == KEY_RIGHT)
	{
		buff1 = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		//data->dirX = data->dirX * 0 + data->dirY * 1;
		data->dirY = buff1 * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		//data->dirY = buff1 * -1 + data->dirY * 0;
		buff2 = data->planeX;
		data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
		//data->planeX = data->planeX * 0 + data->planeY * 1;
		data->planeY = buff2 * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
		//data->planeY = buff2 * -1 + data->planeY * 0;
	}
	if (key == KEY_LEFT)
	{
		buff1 = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		/* data->dirX = data->dirX * 0 - data->dirY * 1; */
		data->dirY = buff1 * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		/* data->dirY = buff1 * 1 + data->dirY * 0; */
		buff2 = data->planeX;
		/* data->planeX = data->planeX * 0 - data->planeY * 1; */
		data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
		/* data->planeY = buff2 * 1 + data->planeY * 0; */
		data->planeY = buff2 * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
	}
	cub3d(data);
	return (0);
}

int	key_hook(int key, data_t *data)
{
		if (key == KEY_UP)
			data->mov_forward = 1;
		if (key == KEY_DOWN)
			data->mov_back = 1;
		if (key == KEY_LEFT)
			data->rot_left = 1;
		if (key == KEY_RIGHT)
			data->rot_right = 1;
	return (0);
}

int	action_hook(data_t *data)
{
	if (data->mov_forward == 1)
	{
		if (data->map[(int)(data->posX + data->dirX * data->moveSpeed)][(int)data->posY] == 0)
			data->posX += data->dirX * data->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY + data->dirY * data->moveSpeed)] == 0)
			data->posY += data->dirY * data->moveSpeed;
		printf("%d\n",data->map[(int)data->posX][(int)data->posY]);
		int x = 0;
		int y = 0;
		while (x < data->mapWidth)
		{
			y = 0;
			while(y < data->mapHeight)
			{
				printf("%d ",data->map[x][y]);
				y++;
			}
			printf("\n");
			x++;
		}
		printf("x = %d\ny = %d\n", (int)data->posX, (int)data->posY);
	}
	if (data->mov_back == 1)
	{
		if (data->map[(int)(data->posX - data->dirX * data->moveSpeed)][(int)data->posY] == 0)
			data->posX -= data->dirX * data->moveSpeed;
		if (data->map[(int)data->posX][(int)(data->posY - data->dirY * data->moveSpeed)] == 0)
			data->posY -= data->dirY * data->moveSpeed;
	}
	if (data->rot_right == 1)
	{
		double buff1;
		double buff2;

		buff1 = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		//data->dirX = data->dirX * 0 + data->dirY * 1;
		data->dirY = buff1 * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		//data->dirY = buff1 * -1 + data->dirY * 0;
		buff2 = data->planeX;
		data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
		//data->planeX = data->planeX * 0 + data->planeY * 1;
		data->planeY = buff2 * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
		//data->planeY = buff2 * -1 + data->planeY * 0;
	}
	if (data->rot_left == 1)
	{
		double buff1;
		double buff2;

		buff1 = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		/* data->dirX = data->dirX * 0 - data->dirY * 1; */
		data->dirY = buff1 * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		/* data->dirY = buff1 * 1 + data->dirY * 0; */
		buff2 = data->planeX;
		/* data->planeX = data->planeX * 0 - data->planeY * 1; */
		data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
		/* data->planeY = buff2 * 1 + data->planeY * 0; */
		data->planeY = buff2 * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
	}
	cub3d(data);
	return (0);

}

int	key_hook_release(int key, data_t *data)
{
		if (key == KEY_UP)
			data->mov_forward = 0;
		if (key == KEY_DOWN)
			data->mov_back = 0;
		if (key == KEY_LEFT)
			data->rot_left = 0;
		if (key == KEY_RIGHT)
			data->rot_right = 0;
	return (0);

}

int main(/*data_t data */)
{
	data_t data;

	if (cub3d_init(&data))
	{
		printf("Malloc error in cub3d_init(). Stop...\n");
		exit(12);
	}
	cub3d(&data);
//	}
//	mlx_key_hook(data->mlx_win, key_act, data);


	mlx_hook(data.mlx_win, 2, 0, key_hook, &data);
	mlx_hook(data.mlx_win, 3, 0, key_hook_release, &data);
	mlx_hook(data.mlx_win, 17, 0, ft_close_window, &data);

	mlx_loop_hook(data.mlx_ptr, action_hook, &data);
	mlx_loop(data.mlx_ptr);
	return 0;
}
