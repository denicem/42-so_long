/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:00:00 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/22 22:30:28 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	show_game_info(t_data *data)
{
	printf("%sCollectibles:%s\t%d\n", BLUE, RESET, data->collect_count);
	printf("%sExits:%s\t\t%d\n", BLUE, RESET, data->exit_count);
}

void	get_game_info(t_data *data)
{
	get_collect_count(data);
	get_exit_count(data);
	get_player_count(data);
}

void	get_collect_count(t_data *data)
{
	int	x;
	int	y;

	data->collect_count = 0;
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

void	get_exit_count(t_data *data)
{
	int	x;
	int	y;

	data->exit_count = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'E')
				(data->exit_count)++;
			x++;
		}
		y++;
	}
}

void	get_player_count(t_data *data)
{
	int	x;
	int	y;

	data->player_count = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
				(data->player_count)++;
			x++;
		}
		y++;
	}
}

void	get_player_pos(t_data *data)
{
	int	x;
	int	y;

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
