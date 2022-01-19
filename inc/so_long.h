/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:23:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/19 01:02:30 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Libft/inc/libft.h"

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	char	*path_map;
	char	**map;
}		t_data;

void	init_map(t_data *data, char *path_map);
void	print_map(t_data *data);