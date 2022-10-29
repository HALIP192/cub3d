/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:51:40 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 21:12:50 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_list	*init_screen_and_map2(t_data *data, int fd, t_list *list_cur, t_list *list_head)
{
	int		width;
	int		height;
	int		height_max;

	width = 0;
	height_max = 0;
	list_head = ft_lstnew(get_next_line(fd));
	list_cur = list_head;
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
	data->mapwidth = width;
	data->mapheight = height_max;
	data->screenheight = 720;
	data->screenwidth = 1080;
	return (list_head);
}

t_list	*init_screen_and_map(t_data *data, int fd)
{
	t_list	*list_head;
	t_list	*list_cur;

	list_head = ft_lstnew(get_next_line(fd));
	list_cur = list_head;
	while (((char *)list_cur->content)[0] == '\n')
	{
		free(list_cur->content);
		list_cur->content = get_next_line(fd);
		if (!list_cur->content)
		{
			printf("Map error1.\n");
			return (NULL);
		}
	}
	return (init_screen_and_map2(data, fd, list_cur, list_head));
}

int	map_init(t_data *data, int fd)
{
	int		i;
	t_list	*map;

	i = 0;
	map = init_screen_and_map(data, fd);
	data->map = (int **)malloc(sizeof(int *) * data->mapwidth);
	if (!data->map)
		return (1);
	while (i < data->mapwidth)
	{
		data->map[i] = (int *)malloc(sizeof(int) * data->mapheight);
		if (!data->map[i])
			return (1);
		if (lstcpy(data, map->content, i))
			return (1);
		i++;
		map = map->next;
	}
	if (validate_map(data))
		return (1);
	return (0);
}
