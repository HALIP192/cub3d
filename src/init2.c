/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:39:39 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/05 15:06:29 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	kostil2(t_texture *data, t_mlxdata *mlxData,
		char ***texture_split, int i)
{
	if (texture_split[i][0][0] == 'N' && texture_split[i][0][1] == 'O')
	{
		data->img_ptr[0] = mlx_png_file_to_image(mlxData->mlx_ptr,
				texture_split[i][1], &data->width[i], &data->height[i]);
		if (!data->img_ptr[0])
			exit (printf(RED "malloc error.\n" RESET));
	}
	else if (texture_split[i][0][0] == 'S' && texture_split[i][0][1] == 'O')
	{
		data->img_ptr[1] = mlx_png_file_to_image(mlxData->mlx_ptr,
				texture_split[i][1], &data->width[i], &data->height[i]);
		if (!data->img_ptr[1])
			exit (printf(RED "malloc error.\n" RESET));
	}
	else
	{
		return (-1);
	}
	return (0);
}

int	png_to_img(t_texture *data, t_mlxdata *mlxData,
		char ***texture_split, int i)
{
	if (kostil2(data, mlxData, texture_split, i) == 0)
	{
		return (0);
	}
	else if (texture_split[i][0][0] == 'W' && texture_split[i][0][1] == 'E')
	{
		data->img_ptr[2] = mlx_png_file_to_image(mlxData->mlx_ptr,
				texture_split[i][1], &data->width[i], &data->height[i]);
		if (!data->img_ptr[2])
			return (1);
	}
	else if (texture_split[i][0][0] == 'E' && texture_split[i][0][1] == 'A')
	{
		data->img_ptr[3] = mlx_png_file_to_image(mlxData->mlx_ptr,
				texture_split[i][1], &data->width[i], &data->height[i]);
		if (!data->img_ptr[3])
			return (1);
	}
	else if (texture_split[i][0][0] == 'F' || texture_split[i][0][0] == 'C')
		return (init_floor_ceil_colors(data, texture_split, i));
	else
		return (printf("Invalid init file \n"));
	return (0);
}

int	kostil3(t_texture *data, char ***texture_split, int i)
{
	if (texture_split[i][0][0] == 'N' && texture_split[i][0][1] == 'O')
	{
		data->imgs[0] = (int *)mlx_get_data_addr(data->img_ptr[0],
				&data->bpp[0], &data->sl[0], &data->end[0]);
		if (!data->imgs[0])
			return (1);
	}
	else if (texture_split[i][0][0] == 'S' && texture_split[i][0][1] == 'O')
	{
		data->imgs[1] = (int *)mlx_get_data_addr(data->img_ptr[1],
				&data->bpp[1], &data->sl[1], &data->end[1]);
		if (!data->imgs[1])
			return (1);
	}
	return (0);
}

int	get_textures_imgs(t_texture *data, char ***texture_split, int i)
{
	if (check_for_double(texture_split))
		exit(printf(RED "Double keys are unacceptable.\n" RESET));
	if (kostil3(data, texture_split, i))
	{
		return (1);
	}
	else if (texture_split[i][0][0] == 'W' && texture_split[i][0][1] == 'E')
	{
		data->imgs[2] = (int *)mlx_get_data_addr(data->img_ptr[2],
				&data->bpp[2], &data->sl[2], &data->end[2]);
		if (!data->imgs[2])
			return (1);
	}
	else if (texture_split[i][0][0] == 'E' && texture_split[i][0][1] == 'A')
	{
		data->imgs[3] = (int *)mlx_get_data_addr(data->img_ptr[3],
				&data->bpp[3], &data->sl[3], &data->end[3]);
		if (!data->imgs[3])
			return (1);
	}
	return (0);
}

int	init_texture(t_texture *data, t_mlxdata *mlxData, char ***texture_split)
{
	int	i;

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
			printf("Error in init_texture step = %d. Stop.\n", i);
			return (1);
		}
		i++;
	}
	free_texture_helper(texture_split);
	return (0);
}
