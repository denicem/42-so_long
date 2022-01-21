/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:54:03 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/21 17:50:38 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	move_player(t_data *data, int keycode)
{
	t_vector	old_pos;

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

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		quit_game(data);
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
		move_player(data, keycode);
	return (1);
}
