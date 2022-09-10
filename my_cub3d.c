/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntitan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:34:07 by ntitan            #+#    #+#             */
/*   Updated: 2022/09/10 18:29:11 by ntitan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	data_t data;

	data = init_data();

	if (argc > 2 || !start_parse(argv, data))
	{
		print_error();
		return (1);
	}
	start_cube(&data);
	return (0);
}
