/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:23:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/22 22:31:38 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/inc/libft.h"

# define BLACK	"\033[0;30m"
# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define YELLOW	"\033[0;33m"
# define BLUE	"\033[0;34m"
# define PURPLE	"\033[0;35m"
# define CYAN	"\033[0;36m"
# define WHITE	"\033[0;37m"
# define RESET	"\033[0m"

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

void	get_game_info(t_data *data);
void	show_game_info(t_data *data);
int		quit_game(t_data *data);
void	quit_game_err(t_data *data, char *err_msg);
void	get_collect_count(t_data *data);
void	get_exit_count(t_data *data);
void	get_player_count(t_data *data);
void	get_player_pos(t_data *data);
void	check_map(t_data *data);

#	endif