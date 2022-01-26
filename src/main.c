/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:05:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/26 18:10:51 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "../inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2)
	{
		data.path_map = argv[1];
		if (!ft_strnstr(data.path_map, ".ber", ft_strlen(data.path_map)))
		{
			printf("%sError%s: Only .ber extension allowed!\n", RED, RESET);
			exit(EXIT_FAILURE);
		}
		init_map(&data);
		check_map(&data);
		show_game_info(&data);
		data.mlx = mlx_init();
		data.mlx_win = get_mlx_window(&data);
		set_textures(&data);
		draw_map(&data);
		mlx_hook(data.mlx_win, 17, 1L << 0, quit_game, &data);
		mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
		mlx_loop(data.mlx);
	}
	else
		printf("Wrong number of arguments.\n");
	return (0);
}
