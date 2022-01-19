/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:05:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/19 23:13:15 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	find_player_pos(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_pos.x = x;
				data->player_pos.y = y;
			}
			x++;
		}
		y++;
	}
}

void	quit_game(t_data *data)
{
	free(data->map);
	data->map = 0;
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(1);
}

int key_hook(int keycode, t_data *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 53)
		quit_game(data);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		printf("moves: %d\n", ++(data->moves));
	return (1);
}

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
		find_player_pos(&data);
		printf("%d\n", data.moves);
		printf("PLAYER POS: x-%d y-%d\n", data.player_pos.x, data.player_pos.y);
		mlx_key_hook(data.mlx_win, key_hook, &data);
		mlx_loop(data.mlx);
	}
	else
		printf("Wrong number of arguments.\n");
	return (0);
}
