/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:23:53 by dmontema          #+#    #+#             */
/*   Updated: 2022/01/19 01:24:28 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Libft/inc/libft.h"

# define NO_OF_TXT 5
# define TXT_PX 64

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
	int y;
}		t_vector;

typedef struct	s_image
{
	void		*img;
	t_vector	size;
}		t_image;

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	char	*path_map;
	char	**map;
	t_image	textures[NO_OF_TXT];
}		t_data;

void	init_map(t_data *data, char *path_map);
void	print_map(t_data *data);

void	set_textures(t_data *data);
void	draw_floor(t_data *data);