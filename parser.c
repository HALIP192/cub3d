/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:06:02 by ntitan            #+#    #+#             */
/*   Updated: 2022/09/10 18:34:36 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_parse(char **argv)
{
	data_t map;

	if (!init_data(argv, &map))
	{
		ft_trow_error("Structure inicialization fail, abort.\n");
		return (1);
	}
	if ()
}
