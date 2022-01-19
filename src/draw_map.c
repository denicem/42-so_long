/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:23:43 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/19 18:49:29 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	set_textures(t_data *data)
{
	data->textures[floor].img = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm", &data->textures->size.x, &data->textures->size.y);
	data->textures[wall].img = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &data->textures->size.x, &data->textures->size.y);
	data->textures[collect].img = mlx_xpm_file_to_image(data->mlx, "./textures/collect.xpm", &data->textures->size.x, &data->textures->size.y);
	data->textures[finish].img = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm", &data->textures->size.x, &data->textures->size.y);
	data->textures[player].img = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &data->textures->size.x, &data->textures->size.y);
}

void	draw_floor(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[floor].img, x * TXT_PX, y * TXT_PX);
			x++;
		}
		y++;
	}
}

void	draw_wall(t_data *data)
{
	int x;

	x = 0;
	while (x < data->width)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[wall].img, x * TXT_PX, 0 * TXT_PX);
		x++;
	}
}

void	draw_map(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[floor].img, x * TXT_PX, y * TXT_PX);
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[wall].img, x * TXT_PX, y * TXT_PX);
			else if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[collect].img, x * TXT_PX, y * TXT_PX);
			else if (data->map[y][x] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[finish].img, x * TXT_PX, y * TXT_PX);
			else if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[player].img, x * TXT_PX, y * TXT_PX);
			x++;
		}
		y++;
	}
}