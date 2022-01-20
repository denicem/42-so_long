/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:05:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/20 18:05:43 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	quit_game(t_data *data)
{
	free(data->map);
	data->map = 0;
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(1);
}

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

void	move_player(t_data *data, int keycode)
{
	t_vector old_pos;
	
	old_pos = data->player_pos;
	if (keycode == 0)
		(data->player_pos.x)--;
	if (keycode == 1)
		(data->player_pos.y)++;
	if (keycode == 2)
		(data->player_pos.x)++;
	if (keycode == 13)
		(data->player_pos.y)--;
	if (data->map[data->player_pos.y][data->player_pos.x] == '1')
	{
		data->player_pos.x = old_pos.x;
		data->player_pos.y = old_pos.y;
	}
	else if (data->map[data->player_pos.y][data->player_pos.x] == 'E')
	{
		printf("GAME OVER!\n");
		quit_game(data);
	}
	else
	{
		if (data->map[data->player_pos.y][data->player_pos.x] == 'C')
		{
			data->map[data->player_pos.y][data->player_pos.x] = '0';
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[floor].img, data->player_pos.x * TXT_PX, data->player_pos.y * TXT_PX);
		}
		data->map[old_pos.y][old_pos.x] = '0';
		data->map[data->player_pos.y][data->player_pos.x] = 'P';
	}
	// mlx_clear_window(data->mlx, data->mlx_win);
	// draw_map(data);
	// mlx_destroy_image(data->mlx, data->textures[player].img);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[floor].img, old_pos.x * TXT_PX, old_pos.y * TXT_PX);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[player].img, data->player_pos.x * TXT_PX, data->player_pos.y * TXT_PX);
	print_map(data);
}


int key_hook(int keycode, t_data *data)
{
	printf("Key pressed: %d\n", keycode);
	if (keycode == 53)
		quit_game(data);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		move_player(data, keycode);
		// printf("moves: %d\n", ++(data->moves));
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
		printf("%d %d\n", data.textures[0].size.x, data.textures[0].size.y);
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
