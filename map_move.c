/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 07:20:51 by seok              #+#    #+#             */
/*   Updated: 2023/07/08 19:55:57 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_img(t_vars *vars)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
			my_mlx_pixel_put(&vars->image, x, y, 0x000000);
	}
}

void	move_x(t_vars *vars, int keycode)
{
	int i;

	i = -1;
	if (keycode == LEFT_KEY)
	{
		while (++i < vars->info.width * vars->info.height)
			vars->map[i].x -= 1;
	}
	else
	{
		while (++i < vars->info.width * vars->info.height)
			vars->map[i].x += 1;
	}
	clear_img(vars);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}

void	move_y(t_vars *vars, int keycode)
{
	int i;

	i = -1;
	if (keycode == DOWN_KEY)
	{
		while (++i < vars->info.width * vars->info.height)
			vars->map[i].y += 10;
	}
	else
	{
		while (++i < vars->info.width * vars->info.height)
			vars->map[i].y -= 10;
	}
	clear_img(vars);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
}

void	view_map(t_vars *vars, int keycode)
{
	if (keycode == ONE_KEY)
	{
		copy_ori(vars, vars->orimap, vars->map);
		// printf("map : %d\n", vars->orimap[0].x);
		set_map_scale(vars);
		set_map_center(vars);
		// set_window_center(vars);
		clear_img(vars);
		draw_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	}
	else if (keycode == TWO_KEY || keycode == W_KEY)
	{
		copy_ori(vars, vars->orimap, vars->map);
		// printf("map : %d\n", vars->orimap[0].x);
		set_map_scale(vars);
		set_map_center(vars);
		z_rotation(vars, 45);
		x_rotation(vars, 30);
		// set_window_center(vars);
		clear_img(vars);
		draw_map(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->image.img, 0, 0);
	}
}