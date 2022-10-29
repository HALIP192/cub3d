/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:15:39 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 17:40:52 by ntitan           ###   ########.fr       */
/*   Updated: 2022/09/24 21:24:16 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "printf_colors.h"
#include "../utils/get_next_line.h"
#include "../minilibx_opengl_20191021/mlx.h"
#include "stdio.h"
#include "math.h"
#include <string.h>


#define SKY 0x87CEED
#define BITUMEN 0x34495E

#define	KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_ESC 53

#define MOUSE_LEFT 1
#define MOUSE_WHEEL 2
#define MOUSE_RIGHT 3
#define MOUSE_WHEEL_DOWN 4
#define MOUSE_WHEEL_UP 5

#define KEY_PRESS 2
#define KEY_RELEASE 3
#define MOUSE_PRESS 4
#define MOUSE_RELEASE 5
#define MOUSE_MOVE 6
#define MOUSE_ENTER_WINDOW 7
#define MOUSE_LEAVE_WINDOW 8
#define WINDOW_CLOSE 17

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
	int		corner;

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
	int		mov_left;
	int		mov_right;
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

texture_t		*texture_global(void);
mlxData_t		*mlxData_global(void);
mouseAction_t	*mouse_global(void);
int				ft_atoi(const char *str);
list_t			*ft_lstnew(void	*content);
void			ft_lstclear(list_t **lst, void (*del)(void *));
int				is_digit(int c);
char			**ft_split(char *str, char sep);
int				ft_isdigit(int c);
char			***free_mas(char ***mas);
int				free_map(int **mas, int width);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_max(int a, int b);
int				mouse_action(int x, int y, data_t *data);
int				key_hook_release(int key, data_t *data);
int				action_hook(data_t *data);
void			rotate(data_t *data, double angle);
void			print_map(data_t *data);
int				key_hook(int key, mouseAction_t *data);
int				esc_function(void);
void			cub3d(data_t *data);
void			raycasting(data_t *data, texture_t *texture, mlxData_t *mlxData, int texNum);
int				get_texX(data_t *data, texture_t *texture);
void			set_draw_starts(data_t *data);
void			Dda(data_t *data);
void			init_steps_and_sideDist(data_t *data);
void			init_dda(data_t *data);
int				cub3d_init(data_t *map_data, char **argv);
char			***get_texture_info(int fd);
int				is_line_valid(char *line);
int				map_init(data_t *data, int fd);
int				validate_map(data_t *data);
int				recursiv_check_map(data_t *data, int i_check, int j_check);
int				init_rec_check_mas(data_t *data, int **map, int i, int j);
int				lstcpy(data_t *data, char *src, int j);
list_t			*init_screen_and_map(data_t *data, int fd);
int				init_position(data_t *data, char *src, int j, int i);
void			init_mlxData(mlxData_t *data, data_t *map_data);
void			init_mouseAction(mouseAction_t *data);
int				init_texture(texture_t *data, mlxData_t *mlxData, char ***texture_split);
int				get_textures_imgs(texture_t *data, char ***texture_split, int i);
int				heck_for_double(char ***texture_split);
void			free_texture_helper(char ***texture_split);
int				png_to_img(texture_t *data, mlxData_t *mlxData, char ***texture_split, int i);
int				init_floor_ceil_colors(texture_t *texture, char ***texture_split, int i);
double			ft_abs(double num);
int				ft_close_window(data_t *data);
#endif

