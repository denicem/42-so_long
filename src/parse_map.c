/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:56:13 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/21 18:39:51 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//TODO: basic error management works. but some of them don't. correct them. 

size_t	ft_strlen_wo_c(const char *s, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			res++;
		i++;
	}
	return (res);
}

static int	count_lines(char *path_map)
{
	int		lines;
	int		fd;
	char	*line;

	lines = 0;
	fd = open(path_map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		lines++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (lines);
}

int	is_rect(char **map, int width)
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

int	is_map_char(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

int	is_wall_surr(char **map, int width, int height)
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

int	is_only_map_chars(char **map, int width, int height)
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

void	check_map(t_data *data)
{
	if (data->collect_count < 1 || data->exit_count < 1 || data->player_count < 1)
		quit_game_err(data, "Map should have at least one collectible and one exit!");
	if (data->player_count != 1)
		quit_game_err(data, "Only one player allowed!");
}

void	init_map(t_data *data)
{
	int		lines;
	int		i;
	int		fd;

	lines = count_lines(data->path_map);
	data->map = malloc(sizeof(char *) * (lines + 1));
	if (data->map == NULL)
		exit(1);
	fd = open(data->path_map, O_RDONLY);
	i = 0;
	while (i < lines)
		data->map[i++] = get_next_line(fd);
	data->map[i] = 0;
	close(fd);
	data->width = ft_strlen(data->map[0]) - 1; //minus newl
	data->height = lines;
	print_map(data);
	if (!is_only_map_chars(data->map, data->width, data->height))
		quit_game_err(data, "Map should only contain these characters: '0', '1', 'P', 'C' and 'E'");
	if (!is_rect(data->map, data->width))
		quit_game_err(data, "Map is not rectangular!");
	if (!is_wall_surr(data->map, data->width, data->height))
		quit_game_err(data, "Map is not surrounded by walls!");
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		ft_printf("%s", data->map[i++]);
	ft_printf("\n");
}
