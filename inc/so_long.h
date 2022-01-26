/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:23:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/26 16:51:46 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	"../Libft/inc/libft.h"
# include	<stdio.h>

# define RED	"\033[0;31m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[0;32m"
# define RESET	"\033[0m"

# define TXT_PX 64
# define NO_OF_TXT 8

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

enum e_textures {
	floor,
	wall,
	collect,
	finish,
	player_down,
	player_left,
	player_right,
	player_up
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
	char		*path_map;
	char		**map;
	int			width;
	int			height;
	int			collect_count;
	int			exit_count;
	int			player_count;
	t_vector	player_pos;
	int			moves;
	t_image		textures[NO_OF_TXT];
}		t_data;

void	init_map(t_data *data);
void	print_map(char **map);
void	check_map(t_data *data);
void	set_textures(t_data *data);
void	draw_map(t_data *data);
void	draw_img(t_data *data, int x, int y, int txt);

size_t	ft_strlen_wo_c(const char *s, char c);

void	show_game_info(t_data *data);
void	init_vals(t_data *data);
void	*get_mlx_window(t_data *data);
void	get_collect_count(t_data *data);
void	get_exit_count(t_data *data);
void	get_player_count(t_data *data);
void	get_player_pos(t_data *data);

int		key_hook(int keycode, t_data *data);
void	move(t_data *data, int x, int y, int dir);
void	move_player(t_data *data, t_vector old_pos, int dir);
void	move_to_exit(t_data *data);
void	print_moves(t_data *data);

int		quit_game(t_data *data);
void	quit_game_err(t_data *data, char *err_msg);

#	endif