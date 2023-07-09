/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:24:43 by seok              #+#    #+#             */
/*   Updated: 2023/07/08 19:25:37 by seok             ###   ########.fr       */
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

void	x_rotation(t_vars *vars, int deg)
{
	int	i;
	float	tmp_y;
	float	tmp_z;

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		tmp_y = vars->map[i].y;
		tmp_z = vars->map[i].z;
		vars->map[i].y = tmp_y * cos(deg * RAD) \
							- tmp_z * sin(deg * RAD);
		vars->map[i].z = tmp_y * sin(deg * RAD) \
							+ tmp_z * cos(deg * RAD);
		// vars->map[i].y = near_int(tmp_y * cos(deg * RAD) \
		// 					- tmp_z * sin(deg * RAD));
		// vars->map[i].z = near_int(tmp_y * sin(deg * RAD) \
							// + tmp_z * cos(deg * RAD);
	}
// printf("before : %d\n", vars->map[0].x);
}

void	y_rotation(t_vars *vars, int deg)
{
	int	i;
	float	tmp_x;
	float	tmp_z;

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		tmp_x = vars->map[i].x;
		tmp_z = vars->map[i].z;
		vars->map[i].x = tmp_x * cos(deg * RAD) \
							+ tmp_z * sin(deg * RAD);
		vars->map[i].z = tmp_z * cos(deg * RAD) \
							- tmp_x * sin(deg * RAD);
	}
}

void	z_rotation(t_vars *vars, int deg)
{
	int	i;
	float	tmp_x;
	float	tmp_y;
	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		tmp_x = vars->map[i].x;
		tmp_y = vars->map[i].y;
		vars->map[i].x = tmp_x * cos(deg * RAD) \
							- tmp_y * sin(deg * RAD);
		vars->map[i].y = tmp_x * sin(deg * RAD) \
							+ tmp_y * cos(deg * RAD);
	}
}
