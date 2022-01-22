/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:00:50 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/22 23:02:40 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/so_long.h"

static void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i++] = 0;
	}
	free(*map);
	map = 0;
}

int	quit_game(t_data *data)
{
	int	i;
	i = 0;
	free_map(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	i = 0;
	while (i < NO_OF_TXT)
		mlx_destroy_image(data->mlx, data->textures[i++].img);
	exit(EXIT_SUCCESS);
	return (0);
}

void	quit_game_err(t_data *data, char *err_msg)
{
	printf("%sError: %s%s\n", RED, RESET, err_msg);
	free_map(data->map);
	exit(EXIT_FAILURE);
}