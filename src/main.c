/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:05:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/22 23:04:34 by dmontema         ###   ########.fr       */
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
		if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		{
			printf("%sError%s: Only accepts .ber extension!\n", RED, RESET);
			exit(EXIT_FAILURE);
		}
		data.path_map = argv[1];
		init_map(&data);
		check_map(&data);
		show_game_info(&data);
		get_player_pos(&data);
		data.mlx = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx, data.width * TXT_PX, data.height * TXT_PX, "so_long");
		set_textures(&data);
		draw_map(&data);
		mlx_hook(data.mlx_win, 17, 1L << 0, quit_game, &data);
		mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
		mlx_loop(data.mlx);
	}
	else
		printf("Wrong number of arguments.\n");
	return (0);
}
