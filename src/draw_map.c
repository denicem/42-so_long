/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 01:23:43 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/26 17:07:22 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	set_textures(t_data *data)
{
	data->textures[floor].img = mlx_xpm_file_to_image
		(data->mlx, "./textures/desert-floor.xpm",
			&data->textures->size.x, &data->textures->size.y);
	data->textures[wall].img = mlx_xpm_file_to_image
		(data->mlx, "./textures/wall.xpm",
			&data->textures->size.x, &data->textures->size.y);
	data->textures[collect].img = mlx_xpm_file_to_image
		(data->mlx, "./textures/rupy-2.xpm",
			&data->textures->size.x, &data->textures->size.y);
	data->textures[finish].img = mlx_xpm_file_to_image
		(data->mlx, "./textures/exit.xpm",
			&data->textures->size.x, &data->textures->size.y);
	data->textures[player_down].img = mlx_xpm_file_to_image
		(data->mlx, "./textures/link.xpm",
			&data->textures->size.x, &data->textures->size.y);
	data->textures[player_left].img = mlx_xpm_file_to_image
		(data->mlx, "./textures/link-left.xpm",
			&data->textures->size.x, &data->textures->size.y);
	data->textures[player_right].img = mlx_xpm_file_to_image
		(data->mlx, "./textures/link-right.xpm",
			&data->textures->size.x, &data->textures->size.y);
	data->textures[player_up].img = mlx_xpm_file_to_image
		(data->mlx, "./textures/link-back.xpm",
			&data->textures->size.x, &data->textures->size.y);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			draw_img(data, x, y, floor);
			if (data->map[y][x] == '1')
				draw_img(data, x, y, wall);
			else if (data->map[y][x] == 'C')
				draw_img(data, x, y, collect);
			else if (data->map[y][x] == 'E')
				draw_img(data, x, y, finish);
			else if (data->map[y][x] == 'P')
				draw_img(data, x, y, player_down);
			x++;
		}
		y++;
	}
}

void	draw_img(t_data *data, int x, int y, int txt)
{
	void	*mlx;
	void	*mlx_win;
	void	*img;

	mlx = data->mlx;
	mlx_win = data->mlx_win;
	img = data->textures[txt].img;
	x = x * TXT_PX;
	y = y * TXT_PX;
	mlx_put_image_to_window(mlx, mlx_win, img, x, y);
}
