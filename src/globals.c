/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:09:44 by ntitan            #+#    #+#             */
/*   Updated: 2022/10/29 17:37:47 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

texture_t	*texture_global(void)
{
	static texture_t	texture = {};
	
	return (&texture);
}

mlxData_t	*mlxData_global(void)
{
	static mlxData_t	mlxData;

	return (&mlxData);
}

mouseAction_t *mouse_global(void)
{
	static mouseAction_t	mouse;

	return (&mouse);
}
