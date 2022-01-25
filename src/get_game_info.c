/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_game_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:51:57 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/25 18:10:22 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	*get_mlx_window(t_data *data)
{
	int	width;
	int	height;

	width = data->width * TXT_PX;
	height = data->height * TXT_PX;
	return (mlx_new_window(data->mlx, width, height, "so_long"));
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
