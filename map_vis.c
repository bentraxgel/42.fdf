/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:17:30 by seok              #+#    #+#             */
/*   Updated: 2023/07/07 15:54:47 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_map_scale(t_vars *vars)
{
	int i;
	int	win;
	int	map;

	i = -1;
	win = (WIN_W - 200) / (WIN_H - 200);
	map = vars->info.width / vars->info.height;
	if (win >= map)
		vars->info.scale = (WIN_W - 200) / vars->info.width;
	else
		vars->info.scale = (WIN_H - 200) / vars->info.height;
	vars->info.high = vars->info.scale / 6;
	printf("scale : %d %d\n", vars->info.scale, vars->info.high);
	while (++i < vars->info.width * vars->info.height)
	{
		vars->map[i].x *= vars->info.scale;
		vars->map[i].y *= vars->info.scale;
		vars->map[i].z *= vars->info.high;
	}
}

void	set_map_center(t_vars *vars)
{
	int i;

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		vars->map[i].x -= (vars->info.width  * vars->info.scale / 2);
		vars->map[i].y -= (vars->info.height * vars->info.scale / 2);
	}
}

void	set_window_center(t_vars *vars)
{
	int i; 

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		vars->map[i].x += (WIN_W / 2);
		vars->map[i].y += (WIN_H / 2);
	}
}

void	draw_map(t_vars *vars, t_coordinate *map)
{
	int	row;
	int	col;

	row = -1;
	while (++row < vars->info.height)
	{
		col = -1;
		while (++col < vars->info.width - 1)
			make_line(&map[vars->info.width * row + col], &map[vars->info.width * row + col + 1], &vars->image);
		col = -1;
		while (row < vars->info.height - 1 && ++col < vars->info.width)
			make_line(&map[vars->info.width * row + col], &map[vars->info.width * (row + 1) + col], &vars->image);
	}
}
