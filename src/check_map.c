/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:46:15 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/24 19:18:28 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "../inc/so_long.h"

static int	is_wall_surr(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width - 1)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height - 1)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_rect(char **map, int width)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!(ft_strlen_wo_c(map[i++], '\n') == (size_t) width))
			return (0);
	}
	return (1);
}

static int	is_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

static int	is_only_map_chars(char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height - 1)
	{
		x = 0;
		while (x < width - 1)
		{
			if (!is_map_char(map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

/*
	check if the map is valid
	if the validation is ok, then it will initialize the values 
	then checks again if the values are valid
*/
void	check_map(t_data *data)
{
	if (!is_only_map_chars(data->map, data->width, data->height))
		quit_game_err(data, "Only valid characters: '0', '1', 'P', 'C', 'E'");
	if (!is_rect(data->map, data->width))
		quit_game_err(data, "Map is not rectangular!");
	if (!is_wall_surr(data->map, data->width, data->height))
		quit_game_err(data, "Map is not surrounded by walls!");
	init_vals(data);
	if (data->collect_count < 1 || data->exit_count < 1)
		quit_game_err(data, "Map with at least one collectible and one exit!");
	if (data->player_count != 1)
		quit_game_err(data, "Only one player allowed!");
	get_player_pos(data);
}