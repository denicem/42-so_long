/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:05:53 by dmontema          #+#    #+#             */
/*   Updated: 2021/12/17 02:31:08 by dmontema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <mlx.h>
#include "mlx_linux/mlx.h"

typedef struct	s_vars
{
	void	*mlx;
	void	*mlx_win;
}		t_vars;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixels;
	int		line_length;
	int		endian;
}		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixels / 8));
	*(unsigned int*) dst = color;
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	return (1);
}

void	show_hide_mouse()
{
	static int show;

	if (!show)
	{
		mlx_mouse_hide();
		show++;
	}
	else
	{
		mlx_mouse_show();
		show--;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)	vars;
	printf("Key pressed: %d\n", keycode);
	if (keycode == 4)
		show_hide_mouse();
	return (1);
}

int mouse_hook(int keycode, t_vars *vars)
{
	(void) keycode;
	(void) vars;
	printf("Moved\n");
	return (1);
}


int	main(void)
{
	t_vars vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");

	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixels, &img.line_length, &img.endian);
	int i = 0;
	int j = 0;
	while (i < 1920 && j < 1080)
		my_mlx_pixel_put(&img, i++, j++, 0x00ffffff);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 2, 1L << 0, close_win, &vars);
	// mlx_mouse_hook(vars.mlx_win, &mouse_hook, &vars);
	// int x = 0;
	// int y = 0;
	// mlx_mouse_get_pos(vars.mlx_win, &x, &y);
	// printf("X: %d, Y: %d\n", x, y);

	mlx_loop(vars.mlx);
	return (0);
}
