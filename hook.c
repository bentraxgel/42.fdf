/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 07:10:46 by seok              #+#    #+#             */
/*   Updated: 2023/07/08 19:56:58 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("%d (%d, %d)\n", button, x, y);
	(void)vars;
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->map);
		exit(0);
	}
	else if (keycode == X_KEY || keycode == Y_KEY || keycode == Z_KEY)
		handle_rot(keycode, vars);
	// else if (keycode == H_KEY || keycode == G_KEY)
	// 	handle_high(keycode, vars);	
	else if (keycode == I_KEY || keycode == O_KEY)
		handle_zoom(keycode, vars);
	else if (keycode == ONE_KEY || keycode == TWO_KEY || keycode == W_KEY || \
				(LEFT_KEY <= keycode && keycode <= UP_KEY))
		arrow_keys(keycode, vars);
	else if (keycode == E_KEY)
		make_earth(vars);
	return (0);
}

void	handle_high(int keycode, t_vars *vars)
{
	int	i;

	i = -1;
	if (keycode == H_KEY)
	{
		t_coordinate	*tmp;

		tmp = malloc(sizeof(t_coordinate) * vars->info.width * vars->info.height);
		vars->z_scale += 0.5;
		copy_ori(vars, vars->map, tmp);

		// while (++i < vars->info.width * vars->info.height)
		// 	vars->map[i].z *= 5;
		// // printf("map : %d\n", vars->orimap[0].x);
		// set_map_scale(vars);
		// set_map_center(vars);
		// z_rotation(vars, 45);
		// x_rotation(vars, 30);
		// // set_window_center(vars);
		clear_img(vars);
		draw_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	}
	// {
	// 	while (++i < vars->info.width * vars->info.height)
	// 	{
	// 		vars->map[i].z += 0.1;
	// 		// z_rotation(vars, 1);
	// 		x_rotation(vars, 1);
	// 	}
	// 	clear_img(vars);
	// 	draw_map(vars);
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	// }
	else if (keycode == G_KEY)
	{
		while (++i < vars->info.width * vars->info.height)
			vars->map[i].z *= 0.9;
		clear_img(vars);
		draw_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	}
}

void	handle_rot(int keycode, t_vars *vars)
{
	if (keycode == X_KEY)
	{
		x_rotation(vars, 2);
		clear_img(vars);
		// draw_map(vars);
		draw_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	}
	else if (keycode == Y_KEY)
	{
		y_rotation(vars, 2);
		clear_img(vars);
		// draw_map(vars);
		draw_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	}
	else if (keycode == Z_KEY)
	{
		z_rotation(vars, 2);
		clear_img(vars);
		// draw_map(vars);
		draw_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	}
}

void	handle_zoom(int keycode, t_vars *vars)
{
	int	i;

	i = -1;
	if (keycode == I_KEY)
	{
		while (++i < vars->info.width * vars->info.height)
		{
			vars->map[i].x *= 1.125;
			vars->map[i].y *= 1.125;
			vars->map[i].z *= 1.125;
		}
	}
	else
	{
		while (++i < vars->info.width * vars->info.height)
		{
			vars->map[i].x *= 0.875;
			vars->map[i].y *= 0.875;
			vars->map[i].z *= 0.875;
		}
	}
	clear_img(vars);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}

void	arrow_keys(int keycode, t_vars *vars)
{
	if (keycode == ONE_KEY || keycode == TWO_KEY || keycode == W_KEY)
		view_map(vars, keycode);
	else if (keycode == LEFT_KEY)
		move_x(vars, keycode);
	else if (keycode == RIGHT_KEY)
		move_x(vars, keycode);
	else if (keycode == DOWN_KEY)
		move_y(vars, keycode);
	else if (keycode == UP_KEY)
		move_y(vars, keycode);
}

int	close_window(t_vars *vars)
{
	// (void)vars;
	// printf("X keycode : %d\n", keycode);
	// mlx_destroy_image(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	if (vars->map != NULL)
		free(vars->map);
	exit(0); //이거만으로 돼?
}