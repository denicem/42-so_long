/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:56:13 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/19 18:46:38 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	print_map(t_data *data)
{
	int i;

	i = 0;
	while (data->map[i])
		ft_printf("%s", data->map[i++]);
	ft_printf("\n");
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

void	init_map(t_data *data, char *path_map)
{
	int		lines;
	int		i;
	int		fd;

	lines = count_lines(path_map);
	data->map = malloc(sizeof(char *) * (lines + 1));
	if (data->map == NULL)
		exit(1);
	fd = open(path_map, O_RDONLY);
	i = 0;
	while (i < lines)
		data->map[i++] = get_next_line(fd);
	data->map[i] = 0;
	close(fd);
	data->width = ft_strlen(data->map[0]) - 1; //minus newl
	data->height = lines;
}
