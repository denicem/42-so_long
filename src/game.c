/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:54:03 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/26 23:18:37 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "../inc/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	int	ud;
	int	lr;

	if (keycode == ESC)
		quit_game(data);
	ud = 0;
	lr = 0;
	if (keycode == A || keycode == D)
	{
		if (keycode == A)
			lr--;
		else if (keycode == D)
			lr++;
	}
	else if (keycode == W || keycode == S)
	{
		if (keycode == W)
			ud--;
		else if (keycode == S)
			ud++;
	}
	move(data, lr, ud, def_dir(ud, lr));
	return (1);
}

void	move(t_data *data, int x, int y, int dir)
{
	t_vector	old_pos;

	if (x == 0 && y == 0)
		return ;
	old_pos = data->player_pos;
	if (data->map[old_pos.y + y][old_pos.x + x] != '1')
	{
		if (data->map[old_pos.y + y][old_pos.x + x] == 'E')
		{
			if (data->collect_count > 0)
			{
				printf("CAN'T EXIT.\n");
				printf("COLLECTIBLES LEFT: %d\n", data->collect_count);
			}
			else
				move_to_exit(data);
		}
		else
		{
			data->player_pos.x += x;
			data->player_pos.y += y;
			move_player(data, old_pos, dir);
		}
	}
	print_moves(data);
}

void	move_player(t_data *data, t_vector old_pos, int dir)
{
	if (data->map[data->player_pos.y][data->player_pos.x] == 'C')
	{
		data->map[data->player_pos.y][data->player_pos.x] = '0';
		draw_img(data, data->player_pos.x, data->player_pos.y, floor);
		(data->collect_count)--;
		printf("COLLECTIBLES LEFT %d\n", data->collect_count);
	}
	data->map[old_pos.y][old_pos.x] = '0';
	data->map[data->player_pos.y][data->player_pos.x] = 'P';
	draw_img(data, old_pos.x, old_pos.y, floor);
	draw_img(data, data->player_pos.x, data->player_pos.y, dir);
}

void	move_to_exit(t_data *data)
{
	print_moves(data);
	printf("%sCongratz!!%s You completed the game.\n", GREEN, RESET);
	quit_game(data);
}

int	def_dir(int ud, int lr)
{
	int	dir;

	dir = -1;
	if (ud != 0)
	{
		if (ud < 0)
			dir = player_up;
		else
			dir = player_down;
	}
	else if (lr != 0)
	{
		if (lr < 0)
			dir = player_left;
		else
			dir = player_right;
	}
	return (dir);
}
