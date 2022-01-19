/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:23:43 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/19 01:28:04 by dmontema         ###   ########.fr       */
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
	while (y * TXT_PX < data->height)
	{
		x = 0;
		while (x * TXT_PX < data->width)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win, data->textures[floor].img, x * TXT_PX, y * TXT_PX);
			x++;
		}
		y++;
	}
}