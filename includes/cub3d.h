/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:15:39 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/01 21:50:59 by ntitan           ###   ########.fr       */
/*   Updated: 2022/09/24 21:24:16 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include "../utils/get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include "../minilibx_opengl_20191021/mlx.h"

#define SKY 0x87CEED
#define BITUMEN 0x34495E
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
	int		screenWidth;
	int		line_lenght;

	double	time;
	double	oldTime;

	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
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


} data_t;

typedef struct texture_s
{
	int		floor;
	int		ceil;
	void	**img_ptr;
	int		**imgs;
	int		*height;
	int		*width;
	int		*bpp;
	int		*end;
	int		*sl;
} texture_t;

typedef struct mouseAction_s
{
	float	moveSpeed;
	float	rotSpeed;
	int		mov_forward;
	int		mov_back;
	int		rot_right;
	int		rot_left;
	int		mouse_x;
	int		mouse_y;
} mouseAction_t;

typedef struct mlxData_s
{

	void	*mlx_ptr;
	void	*mlx_win;

	void	*img_ptr;
	int		*image;
} mlxData_t;

typedef struct list_s
{
	struct list_s	*next;
	void			*content;
} list_t;

int		ft_atoi(const char *str);
list_t	*ft_lstnew(void	*content);
void	ft_lstclear(list_t **lst, void (*del)(void *));
int		is_digit(int c);
char	**ft_split(char *str, char sep);
int		ft_isdigit(int c);
#endif

