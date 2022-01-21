/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:00:50 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/21 17:44:17 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <fcntl.h>
#include "../inc/so_long.h"

int	quit_game(t_data *data)
{
	int	i;
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		data->map[i++] = 0;
	}
	free(data->map);
	data->map = 0;
	mlx_destroy_window(data->mlx, data->mlx_win);
	i = 0;
	while (i < NO_OF_TXT)
		mlx_destroy_image(data->mlx, data->textures[i++].img);
	exit(1);
	return (0);
}

void	quit_game_err(t_data *data, char *err_msg)
{
	printf("%s\n", err_msg);
	int	i;
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		data->map[i++] = 0;
	}
	free(data->map);
	data->map = 0;
	exit(1);
}