/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:24:43 by seok              #+#    #+#             */
/*   Updated: 2023/06/29 16:10:02 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int near_int(double n)
{
	int	a;
	int	b;

	a = (int)n;
	b = (int)(n + 1);

	if (n - a < b - n)
		return (a);
	else
		return (b);
}

void	x_rotation(t_coordinate *map, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->width * info->height)
	{
		int tmp_y = map[i].y;
		int tmp_z = map[i].z;
		map[i].y = near_int(tmp_y * cos(DEGREE * RAD) - tmp_z * sin(DEGREE * RAD));
		map[i].z = near_int(tmp_y * sin(DEGREE * RAD) - tmp_z * cos(DEGREE * RAD));
	}
}

void	y_rotation(t_coordinate *map, t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->width * info->height)
	{
		int	tmp_x = map[i].x;
		int	tmp_z = map[i].z;
		map[i].x = near_int(tmp_x * cos(DEGREE * RAD) + tmp_z * sin(DEGREE * RAD));
		map[i].z = near_int(tmp_z * cos(DEGREE * RAD) - tmp_x * sin(DEGREE * RAD));
	}
}

void	z_rotation(t_coordinate *map, t_info *info)
{
	int i;

	i = -1;
	while (++i < info->width * info->height)
	{
		int	tmp_x = map[i].x;
		int	tmp_y = map[i].y;
		map[i].x = near_int(tmp_x * cos(DEGREE * RAD) - tmp_y * sin(DEGREE * RAD));
		map[i].y = near_int(tmp_x * sin(DEGREE * RAD) + tmp_y * cos(DEGREE * RAD));
	}
}