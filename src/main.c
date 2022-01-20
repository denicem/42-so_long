/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:05:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/20 22:01:05 by dmontema         ###   ########.fr       */
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
		data.path_map = argv[1];
		init_map(&data);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, data.width * TXT_PX, data.height * TXT_PX, "so_long");
		set_textures(&data);
		draw_map(&data);
		data.moves = 0;
		get_player_pos(&data);
		get_collect_count(&data);
		mlx_key_hook(data.mlx_win, key_hook, &data);
		mlx_loop(data.mlx);
	}
	else
		printf("Wrong number of arguments.\n");
	return (0);
}
