/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 07:10:46 by seok              #+#    #+#             */
/*   Updated: 2023/07/11 20:28:09 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->map);
		exit(0);
	}
	else if (keycode == X_KEY || keycode == Y_KEY || keycode == Z_KEY)
		handle_rot(keycode, vars);
	else if (keycode == I_KEY || keycode == O_KEY)
		handle_zoom(keycode, vars);
	else if (keycode == ONE_KEY || keycode == TWO_KEY || keycode == W_KEY || \
				(LEFT_KEY <= keycode && keycode <= UP_KEY))
		arrow_keys(keycode, vars);
	else if (keycode == E_KEY)
		make_earth(vars);
	return (0);
}

void	handle_rot(int keycode, t_vars *vars)
{
	if (keycode == X_KEY)
	{
		x_rotation(vars, 2);
		clear_img(vars);
		draw_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	}
	else if (keycode == Y_KEY)
	{
		y_rotation(vars, 2);
		clear_img(vars);
		draw_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	}
	else if (keycode == Z_KEY)
	{
		z_rotation(vars, 2);
		clear_img(vars);
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
	mlx_destroy_window(vars->mlx, vars->win);
	if (vars->map != NULL)
		free(vars->map);
	exit(0);
}
