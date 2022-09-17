/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 13:54:27 by ntitan            #+#    #+#             */
/*   Updated: 2022/09/17 19:27:53 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdio.h"
#include "math.h"
#define mapWidth 24
#define mapHeight 24
#define screenHeight 640
#define screenWidth 480

#define RED 0x00ff0000
#define GREEN 0x0000ff00
#define BLUE 0x000000ff
#define YELLOW 0x00ffff00

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

int map[mapWidth][mapHeight] = 
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


int main(/*data_t data */)
{
	double	posX = 12, posY = 12;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;

	double time = 0;
	double oldTime = 0;
	int x;

//===========================DROW_FUNCTION=====================================
	void *mlx_ptr;
	void *mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "cub3d");

//==========================ACTUAL_ALGO========================================
	int sn;
	void *img_ptr;
	int *image;
	int line_lenght;
	img_ptr = mlx_new_image(mlx_ptr, screenWidth, screenHeight);
	image = (int *)mlx_get_data_addr(img_ptr, &sn, &line_lenght, &sn);
	printf("%d\n", line_lenght);	
		x = 0;
		while (x < screenWidth)
		{
			if (x == screenWidth / 2)
			{
				printf("lol\n");
			}
			printf("...x = %d\n",x);
			printf("..mapWidth = %d\n", mapWidth);
			double	cameraX = 2 * x / (double)screenWidth - 1;
			double	rayDirX = dirX + planeX * cameraX;
			double	rayDirY = dirY + planeY * cameraX;
			printf("...cameraX = %f\n",cameraX);

			int	mapX = (int)posX;
			int	mapY = (int)posY;

			double	deltaDistX = (rayDirX == 0) ? 1e30 : ft_abs(1 / rayDirX);
			double	deltaDistY = (rayDirY == 0) ? 1e30 : ft_abs(1 / rayDirY);

			int	stepX;
			int	stepY;

			double	sideDistX;
			double	sideDistY;

			if (rayDirX < 0)
			{
				stepX = -1;
				sideDistX = (posX - mapX) * deltaDistX;
			}
			else
			{
				stepX = 1;
				sideDistX = (mapX + 1.0 - posX) * deltaDistX;
			}
			if (rayDirY < 0)
			{
				stepY = -1;
				sideDistY = (posY - mapY) * deltaDistY;
			}
			else
			{
				stepY = 1;
				sideDistY = (mapY + 1.0 - posY) * deltaDistY;
			}
			

			int	hit = 0;
			int	side;
			while (hit == 0)
			{
				if (sideDistX < sideDistY)
				{
					sideDistX += deltaDistX;
					mapX += stepX;
					side = 0;
				}
				else
				{
					sideDistY += deltaDistY;
					mapY += stepY;
					side = 1;
				}
				if (map[mapX][mapY] > 0) 
					hit = 1;
			}
			double	wallDist;

			if (side == 0)
				wallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
			else
				wallDist = (mapY - posY + (1 - stepY) / 2)  / rayDirY;
			int	lineHeight;

			lineHeight = (int)(screenHeight / wallDist);

			int	drawStart;
			int	drawEnd;
			drawStart = -lineHeight / 2 + screenHeight / 2;
			if (drawStart < 0)
				drawStart = 0;
			drawEnd = lineHeight / 2 + screenHeight / 2;
			if (drawEnd >= screenHeight)
				drawEnd = screenHeight - 1;
			printf("++++++end = %f\n", rayDirX);
			printf("++++++end = %f\n", mapWidth);
			int color;

			if (map[mapX][mapY] == 0)
				color = 0x00ffff00; //yellow
			if (map[mapX][mapY] == 1)
				color = 0x00ff0000; // red
			if (map[mapX][mapY] == 2)
				color = 0x0000ff00; // green
			if (map[mapX][mapY] == 3)
				color = 0x000000ff; // blue
			if (map[mapX][mapY] == 4)
				color = 0x00ffffff; // white

			if (side == 1)
				color /= 2;
//=======================================DROW_LINE=========================
			int y;

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
			y = 0;
			while (y < screenHeight)
			{
					if (y < (screenHeight) && y < drawStart)
					{

						//mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0x00ffff00);
						image[y * (line_lenght / 4) + x] = 0x87CEEB;
					}
					if (y < screenHeight && y > drawEnd)
					{
						image[y * (line_lenght / 4) + x] = 0x34495E;
					}
					if (y > drawStart && y < drawEnd)
					{
						/* mlx_pixel_put(mlx_ptr, mlx_win, x, y, color); */
						image[y * (line_lenght / 4) + x] = color;
					}
				y++;
			}
			//char s;
			//read(1, &s, 1);
			mlx_put_image_to_window(mlx_ptr, mlx_win, img_ptr, 0, 0);
			x++;
		
	}
//	}
	mlx_loop(mlx_ptr);
	return 0;
}
