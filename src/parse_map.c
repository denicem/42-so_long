/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:56:13 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/24 18:47:34 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	count_lines(int fd)
{
	int		lines;
	char	*line;

	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines++;
		line = get_next_line(fd);
	}
	free(line);
	return (lines);
}

void	init_map(t_data *data)
{
	int		lines;
	int		fd;
	int		i;

	fd = open(data->path_map, O_RDONLY);
	if (fd < 0)
	{
		printf("%sError%s: Map not found!\n", RED, RESET);
		exit(EXIT_FAILURE);
	}
	lines = count_lines(fd);
	close(fd);
	data->map = malloc(sizeof(char *) * (lines + 1));
	if (data->map == NULL)
		exit(EXIT_FAILURE);
	fd = open(data->path_map, O_RDONLY);
	i = 0;
	while (i < lines)
		data->map[i++] = get_next_line(fd);
	close(fd);
	data->map[i] = 0;
	data->width = ft_strlen(data->map[0]) - 1;
	data->height = lines;
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		printf("%s", map[i++]);
	printf("\n");
}
