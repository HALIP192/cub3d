/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:58:46 by ntitan            #+#    #+#             */
/*   Updated: 2022/11/27 17:09:32 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_line_valid(char *line)
{
	if ((line && (line[0] == 'N' && line[1] == 'O'))
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E')
		|| (line[0] == 'E' && line[1] == 'A')
		|| (line[0] == 'F') || (line[0] == 'C'))
		return (1);
	return (0);
}

char	***kostil(int fd, char ***mas, char *line, int cnt)
{
	while (cnt < 6 && line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		if (is_line_valid(line))
		{
			mas[cnt++] = ft_split(line, ' ');
		}
		else
		{
			free(line);
			return (NULL);
		}
		if (cnt < 6)
		{
			free(line);
			line = get_next_line(fd);
		}
	}
	free(line);
	return (mas);
}

char	***get_texture_info(int fd)
{
	char	***mas;
	char	*line;
	int		cnt;

	mas = (char ***)malloc(sizeof(char **) * 7);
	if (!mas)
		return (NULL);
	mas[6] = NULL;
	line = get_next_line(fd);
	cnt = 0;
	return (kostil(fd, mas, line, cnt));
}
