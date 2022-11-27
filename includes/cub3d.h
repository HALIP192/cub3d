/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:26:07 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/27 15:21:37 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "printf_colors.h"
# include "../utils/get_next_line.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include "stdio.h"
# include "math.h"
# include <string.h>

# define SKY 0x87CEED
# define BITUMEN 0x34495E

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

# define MOUSE_LEFT 1
# define MOUSE_WHEEL 2
# define MOUSE_RIGHT 3
# define MOUSE_WHEEL_DOWN 4
# define MOUSE_WHEEL_UP 5

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_PRESS 4
# define MOUSE_RELEASE 5
# define MOUSE_MOVE 6
# define MOUSE_ENTER_WINDOW 7
# define MOUSE_LEAVE_WINDOW 8
# define WINDOW_CLOSE 17

/* #include "minilibx_opengl_20191021/mlx_opengl.h" */
/* #include "minilibx_opengl_20191021/mlx_new_window.h" */
/* #include "minilibx_opengl_20191021/mlx_int.h" */
/* #include "minilibx_opengl_20191021/mlx_png.h" */

typedef struct data_s
{
	int		**map;
	int		mapwidth;
	int		mapheight;
	int		screenheight;
	int		screenwidth;
	int		line_lenght;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	deltadistx;
	double	deltadisty;
	int		stepx;
	int		stepy;
	double	sidedistx;
	double	sidedisty;
	double	walldist;
	int		lineheight;
	int		color;
	int		side;
	int		drawstart;
	int		drawend;
	int		corner;

	int		x;
	int		y;
}	t_data;

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
}	t_texture;

typedef struct mouseAction_s
{
	float	movespeed;
	float	rotspeed;
	int		mov_forward;
	int		mov_back;
	int		mov_left;
	int		mov_right;
	int		rot_right;
	int		rot_left;
	int		mouse_x;
	int		mouse_y;
}	t_mouseaction;

typedef struct mlxdata_s
{
	void	*mlx_ptr;
	void	*mlx_win;

	void	*img_ptr;
	int		*image;
}	t_mlxdata;

typedef struct list_s
{
	struct list_s	*next;
	void			*content;
}	t_list;

t_texture		*texture_global(void);
t_mlxdata		*mlxdata_global(void);
t_mouseaction	*mouse_global(void);
int				ft_atoi(const char *str);
t_list			*ft_lstnew(void	*content);
void			ft_lstclear(t_list **lst, void (*del)(void *));
int				is_digit(int c);
char			**ft_split(char *str, char sep);
int				ft_isdigit(int c);
char			***free_mas(char ***mas);
int				free_map(int **mas, int width);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_max(int a, int b);
int				mouse_action(int x, int y, t_data *data);
int				key_hook_release(int key, t_data *data);
int				action_hook(t_data *data);
void			rotate(t_data *data, double angle);
void			print_map(t_data *data);
int				key_hook(int key, t_mouseaction *data);
int				esc_function(void);
void			cub3d(t_data *data);
void			raycasting(t_data *data, t_texture *texture, t_mlxdata *mlxData,
					int texNum);
int				get_texx(t_data *data, t_texture *texture);
void			set_draw_starts(t_data *data);
void			dda(t_data *data);
void			init_steps_and_sidedist(t_data *data);
void			init_dda(t_data *data);
int				cub3d_init(t_data *map_data, char **argv);
char			***get_texture_info(int fd);
int				is_line_valid(char *line);
int				map_init(t_data *data, int fd);
int				validate_map(t_data *data);
int				recursiv_check_map(t_data *data, int i_check, int j_check);
int				init_rec_check_mas(t_data *data, int **map, int i, int j);
int				lstcpy(t_data *data, char *src, int j);
t_list			*init_screen_and_map(t_data *data, int fd);
int				init_position(t_data *data, char *src, int j, int i);
void			init_mlxdata(t_mlxdata *data, t_data *map_data);
void			init_mouse_action(t_mouseaction *data);
int				init_texture(t_texture *data, t_mlxdata *mlxData,
					char ***texture_split);
int				get_textures_imgs(t_texture *data, char ***texture_split,
					int i);
int				check_for_double(char ***texture_split);
void			free_texture_helper(char ***texture_split);
int				png_to_img(t_texture *data, t_mlxdata *mlxData,
					char ***texture_split, int i);
int				init_floor_ceil_colors(t_texture *texture,
					char ***texture_split, int i);
double			ft_abs(double num);
int				ft_close_window(t_data *data);
void			minimap_draw(t_data *data, t_texture *texture,
					t_mlxdata *mlxData);

#endif
