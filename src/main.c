/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:05:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/19 18:40:07 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_data data;

	if (argc == 2)
	{
		init_map(&data, argv[1]);
		// print_map(&data);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, data.width * TXT_PX, data.height * TXT_PX, "so_long");
		set_textures(&data);
		draw_map(&data);
		// draw_floor(&data);
		// draw_wall(&data);
		mlx_loop(data.mlx);
	}
	else
		printf("Wrong number of arguments.\n");
	return (0);
}
