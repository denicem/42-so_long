/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:00:00 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/26 23:16:30 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	init_vals(t_data *data)
{
	get_player_count(data);
	get_collect_count(data);
	get_exit_count(data);
	data->moves = 0;
}

void	show_game_info(t_data *data)
{
	printf("%s<<< SO LONG >>>%s\n", CYAN, RESET);
	printf("%sCollectibles:%s\t%d\n", CYAN, RESET, data->collect_count);
	printf("%sExits:%s\t\t%d\n", CYAN, RESET, data->exit_count);
	printf("%sMap Layout:%s\n", CYAN, RESET);
	print_map(data->map);
}

void	print_moves(t_data *data)
{
	char	*mv;

	mv = ft_itoa(++data->moves);
	draw_img(data, 0, 0, wall);
	mlx_string_put(data->mlx, data->mlx_win, 14, 25, 16777215, "Moves:");
	mlx_string_put(data->mlx, data->mlx_win, 25, 40, 16777215, mv);
	printf("%sMoves:%s %d\n", CYAN, RESET, data->moves);
	free(mv);
}
