/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:17:30 by seok              #+#    #+#             */
/*   Updated: 2023/07/07 06:51:51 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
//TODO 여기 다 for문이여!!!!!!!!
void	set_map_scale(t_vars *vars, t_info *info)
{
	for (int i = 0; i < info->width * info->height; i++)
	{
		vars->map[i].x *= info->scale;
		vars->map[i].y *= info->scale;
		vars->map[i].z *= info->high;
	}
}

void	set_map_center(t_vars *vars, t_info *info)
{
	for (int i = 0; i < info->width * info->height; i++)
	{
		vars->map[i].x -= (info->width  * info->scale / 2);
		vars->map[i].y -= (info->height * info->scale / 2);
		if (vars->map[i].x == 0 && vars->map[i].y == 0)
			vars->map[i].color = 0x00A5FF; //TODO center_blue
	}
}

void	set_window_center(t_vars *vars, t_info *info)
{
	for (int i = 0; i < info->width * info->height; i++)
	{
		vars->map[i].x += (WIN_W / 2);
		vars->map[i].y += (WIN_H / 2);
	}
}

void	draw_map(t_vars *vars, t_info *info, t_data *image)
{
	int	row;
	int	col;

	row = -1;
	while (++row < info->height)
	{
		col = -1;
		while (++col < info->width - 1)
			make_line(&vars->map[info->width * row + col], &vars->map[info->width * row + col + 1], image);
		col = -1;
		while (row < info->height - 1 && ++col < info->width)
			make_line(&vars->map[info->width * row + col], &vars->map[info->width * (row + 1) + col], image);
	}
}