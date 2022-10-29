/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:09:44 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 20:34:38 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_texture	*texture_global(void)
{
	static t_texture	texture = {};

	return (&texture);
}

t_mlxdata	*mlxdata_global(void)
{
	static t_mlxdata	mlxdata;

	return (&mlxdata);
}

t_mouseaction	*mouse_global(void)
{
	static t_mouseaction	mouse;

	return (&mouse);
}
