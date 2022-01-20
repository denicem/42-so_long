/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:05:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/20 20:01:36 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	quit_game(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		data->map[i] = 0;
		i++;
	}
	free(data->map);
	data->map = 0;
	mlx_destroy_window(data->mlx, data->mlx_win);
	i = 0;
	while (i < NO_OF_TXT)
		mlx_destroy_image(data->mlx, data->textures[i++].img);
	// system("leaks so_long");
	exit(1);
}

void	get_collect_count (t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'C')
				(data->collect_count)++;
			x++;
		}
		y++;
	}
}

void	get_player_pos(t_data *data)
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
		if (data->collect_count == 0)
		{
			data->moves++;
			printf("GAME OVER!\n");
			printf("MOVES: %d\n", data->moves);
			quit_game(data);
		}
		else 
		{
			data->player_pos.x = old_pos.x;
			data->player_pos.y = old_pos.y;
			printf("CAN'T EXIT. COLLECTIBLES LEFT: %d\n", data->collect_count);
		}
	}
	else
	{
		if (data->map[data->player_pos.y][data->player_pos.x] == 'C')
		{
			data->map[data->player_pos.y][data->player_pos.x] = '0';
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[floor].img, data->player_pos.x * TXT_PX, data->player_pos.y * TXT_PX);
			(data->collect_count)--;
			printf("COLLECTED! GJ!\n");
			printf("COLLECTIBLES LEFT %d\n", data->collect_count);
		}
		data->moves++;
		data->map[old_pos.y][old_pos.x] = '0';
		data->map[data->player_pos.y][data->player_pos.x] = 'P';
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[floor].img, old_pos.x * TXT_PX, old_pos.y * TXT_PX);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[player].img, data->player_pos.x * TXT_PX, data->player_pos.y * TXT_PX);
	// print_map(data);
}


int key_hook(int keycode, t_data *data)
{
	// printf("Key pressed: %d\n", keycode);
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
		draw_map(&data);
		data.moves = 0;
		get_player_pos(&data);
		get_collect_count(&data);
		// printf("%d\n", data.collect_count);
		mlx_key_hook(data.mlx_win, key_hook, &data);
		mlx_loop(data.mlx);
	}
	else
		printf("Wrong number of arguments.\n");
	return (0);
}
