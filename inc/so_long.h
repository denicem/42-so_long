/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:23:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/21 18:24:54 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/inc/libft.h"

# define TXT_PX 64
# define NO_OF_TXT 5

enum e_textures {
	floor = 0,
	wall = 1,
	collect = 2,
	finish = 3,
	player = 4,
};

typedef struct s_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct s_image
{
	void		*img;
	t_vector	size;
}		t_image;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	char		*path_map;
	char		**map;
	int			moves;
	int			collect_count;
	int			exit_count;
	int			player_count;
	t_vector	player_pos;
	t_image		textures[NO_OF_TXT];
}		t_data;

void	init_map(t_data *data);
void	print_map(t_data *data);

void	set_textures(t_data *data);
void	draw_map(t_data *data);

int		key_hook(int keycode, t_data *data);
void	move_player(t_data *data, int keycode);

int		quit_game(t_data *data);
void	quit_game_err(t_data *data, char *err_msg);
void	get_collect_count(t_data *data);
void	get_exit_count(t_data *data);
void	get_player_count(t_data *data);
void	get_player_pos(t_data *data);
void	check_map(t_data *data);

#	endif