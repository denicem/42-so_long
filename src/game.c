/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:54:03 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/25 01:15:49 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	move_player(t_data *data, int x, int y)
{
	t_vector old_pos;

	old_pos = data->player_pos;
	if (data->map[old_pos.y + y][old_pos.x + x] != '1')
	{
		if (data->map[old_pos.y + y][old_pos.x + x] == 'E')
		{
			if (data->collect_count > 0)
			{
				printf("CAN'T EXIT. COLLECTIBLES LEFT: %d\n", data->collect_count);
				return ;
			}
			print_moves(data);
			printf("Congratz!! You completed the game.\n");
			quit_game(data);
		}
		data->player_pos.x += x;
		data->player_pos.y += y;
		if (data->map[data->player_pos.y][data->player_pos.x] == 'C')
		{
			data->map[data->player_pos.y][data->player_pos.x] = '0';
			draw_img(data, data->player_pos.x, data->player_pos.y, floor);
			(data->collect_count)--;
			printf("COLLECTIBLES LEFT %d\n", data->collect_count);
		}
		print_moves(data);
		data->map[old_pos.y][old_pos.x] = '0';
		data->map[data->player_pos.y][data->player_pos.x] = 'P';
		draw_img(data, old_pos.x, old_pos.y, floor);
		draw_img(data, data->player_pos.x, data->player_pos.y, player);
	}
}

int	key_hook(int keycode, t_data *data)
{
	int ud; // up/down
	int lr; // left/right

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
	move_player(data, lr, ud);
	return (1);
}

void	print_moves(t_data *data)
{
	char *mv;

	mv = ft_itoa(++data->moves);
	draw_img(data, 0, 0, wall);
	mlx_string_put(data->mlx, data->mlx_win, 14, 25, 16777215, "Moves:");
	mlx_string_put(data->mlx, data->mlx_win, 25, 40, 16777215, mv);
	printf("%sMoves:%s %d\n", CYAN, RESET, data->moves);
	free(mv);
}
