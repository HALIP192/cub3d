/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:23:40 by ntitan            #+#    #+#             */
/*   Updated: 2022/09/10 18:30:43 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_CUB3D_H
# define MY_CUB3D_H

#include <stdio.h>
#include "get_next_line.h"
#include <string.h>

typedef struct data_s
{
	char **map;
	char **no;
	char **so;
	char **we;
	char **ea;
	int *F;
	int *C;
} data_s

#endif
