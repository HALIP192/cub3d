/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:15:39 by ntitan            #+#    #+#             */
/*   Updated: 2022/09/24 21:26:21 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include "get_next_line.c"
#include "get_next_line.h"
#include "get_next_line_utils.c"
#include <stdlib.h>
#include <string.h>
#include "minilibx_opengl_20191021/mlx.h"
/* #include "minilibx_opengl_20191021/mlx_opengl.h" */
/* #include "minilibx_opengl_20191021/mlx_new_window.h" */
/* #include "minilibx_opengl_20191021/mlx_int.h" */
/* #include "minilibx_opengl_20191021/mlx_png.h" */

typedef struct data_s
{
	int		**map;
	int		mapWidth;
	int		mapHeight;
	int		screenHeight;
	int 	screenWidth;

	void	*mlx_ptr;
	void	*mlx_win;

	void	*img_ptr;
	int		*image;
	int		line_lenght;

	double	time;
	double	oldTime;

	double	posX;
	double	posY;
	double 	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int 	mapX;
	int		mapY;
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
	double	sideDistX;
	double	sideDistY;
	double	WallDist;
	int		lineHeight;
	int		color;
	int		side;
	int		drawStart;
	int		drawEnd;

	int		x;
	int		y;

	float	moveSpeed;
	float	rotSpeed;
	int		mov_forward;
	int		mov_back;
	int		rot_right;
	int		rot_left;

	void	**texture_img_ptr;
	int		**texture_imgs;
	int		texHeight[8];
	int		texWidth[8];
	int		bpp[8];
	int		end[8];
	int		sl[8];

	int		mouse_hook;
	int		rofl;
} data_t;


#endif

