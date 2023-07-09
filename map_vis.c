/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:17:30 by seok              #+#    #+#             */
/*   Updated: 2023/07/09 22:17:19 by seok             ###   ########.fr       */
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
	// printf("scale : %d %d\n", vars->info.scale, vars->info.high);
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

void	set_window_center(t_vars *vars, t_coordinate *map)
{
	int i;
	

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		map[i].x += (WIN_W / 2);
		map[i].y += (WIN_H / 2);
	}
}

void	draw_map(t_vars *vars)
{
	int	row;
	int	col;
	t_coordinate	*tmp;

	tmp = malloc(sizeof(t_coordinate) * vars->info.width * vars->info.height);
	copy_ori(vars, vars->map, tmp);
	row = -1;
	set_window_center(vars, tmp);
	while (++row < vars->info.height)
	{
		col = -1;
		while (++col < vars->info.width - 1)
			make_line(&tmp[vars->info.width * row + col], &tmp[vars->info.width * row + col + 1], &vars->image);
		col = -1;
		while (row < vars->info.height - 1 && ++col < vars->info.width)
			make_line(&tmp[vars->info.width * row + col], &tmp[vars->info.width * (row + 1) + col], &vars->image);
	}
	free(tmp);
}
