/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:48:53 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/27 16:31:28 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static inline int	print_helper(void)
{
	printf(RED "Invalid arguments\n" RESET);
	printf(YELLOW "Usadge:\n" RESET);
	printf(YELLOW "./cub3d [path_to_file]\n" RESET);
	return (0);
}

static inline int	check_argv(char **argv)
{
	int		fd;
	char	**str;
	int		i;

	str = ft_split(argv[1], '.');
	i = 0;
	while (str[i])
		i++;
	if (i != 2)
		exit(printf(RED "Invalid file name\n" RESET));
	if (ft_memcmp(str[1], "cub", ft_strlen(str[1])))
		exit(printf(RED "Invalid file name\n" RESET));
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data			data;
	t_texture		*texture;
	t_mouseaction	*mouse;
	t_mlxdata		*mlxdata;

	if (argc < 2)
		return (print_helper());
	check_argv(argv);
	mouse = mouse_global();
	texture = texture_global();
	mlxdata = mlxdata_global();
	if (cub3d_init(&data, argv))
	{
		printf("Malloc error in cub3d_init(). Stop...\n");
		exit(12);
	}
	cub3d(&data);
	printf("%p\n%p\n%p\n%p\n", &data, mouse, texture, mlxdata);
	mlx_hook(mlxdata->mlx_win, KEY_PRESS, 0, key_hook, mouse);
	mlx_hook(mlxdata->mlx_win, KEY_RELEASE, 0, key_hook_release, mouse);
	mlx_hook(mlxdata->mlx_win, WINDOW_CLOSE, 0, ft_close_window, &data);
	mlx_hook(mlxdata->mlx_win, MOUSE_MOVE, 0, mouse_action, &data);
	mlx_loop_hook(mlxdata->mlx_ptr, action_hook, &data);
	mlx_loop(mlxdata->mlx_ptr);
	return (0);
}
