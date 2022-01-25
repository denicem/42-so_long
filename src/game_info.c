/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 22:00:00 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/24 19:11:04 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "../inc/so_long.h"

void	show_game_info(t_data *data)
{
	printf("%s<<< SO LONG >>>%s\n", CYAN, RESET);
	printf("%sCollectibles:%s\t%d\n", CYAN, RESET, data->collect_count);
	printf("%sExits:%s\t\t%d\n", CYAN, RESET, data->exit_count);
	printf("%sMap Layout:%s\n", CYAN, RESET);
	print_map(data->map);
}

void	init_vals(t_data *data)
{
	get_player_count(data);
	get_collect_count(data);
	get_exit_count(data);
}
