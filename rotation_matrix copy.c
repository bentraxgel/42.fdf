/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:24:43 by seok              #+#    #+#             */
/*   Updated: 2023/07/07 14:18:47 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	near_int(double n)
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

void	x_rotation(t_vars *vars, t_coordinate *map, int deg)
{
	int	i;
	int	tmp_y;
	int	tmp_z;

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		tmp_y = map[i].y;
		tmp_z = map[i].z;
		map[i].y = near_int(tmp_y * cos(deg * RAD) \
							- tmp_z * sin(deg * RAD));
		map[i].z = near_int(tmp_y * sin(deg * RAD) \
							+ tmp_z * cos(deg * RAD));
	}
}

void	y_rotation(t_vars *vars, t_coordinate *map, int deg)
{
	int	i;
	int	tmp_x;
	int	tmp_z;

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		tmp_x = map[i].x;
		tmp_z = map[i].z;
		map[i].x = near_int(tmp_x * cos(deg * RAD) \
							+ tmp_z * sin(deg * RAD));
		map[i].z = near_int(tmp_z * cos(deg * RAD) \
							- tmp_x * sin(deg * RAD));
	}
}

void	z_rotation(t_vars *vars, t_coordinate *map, int deg)
{
	int	i;
	int	tmp_x;
	int	tmp_y;

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		tmp_x = map[i].x;
		tmp_y = map[i].y;
		map[i].x = near_int(tmp_x * cos(deg * RAD) \
							- tmp_y * sin(deg * RAD));
		map[i].y = near_int(tmp_x * sin(deg * RAD) \
							+ tmp_y * cos(deg * RAD));
	}
}
