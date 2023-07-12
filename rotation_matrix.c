/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:24:43 by seok              #+#    #+#             */
/*   Updated: 2023/07/12 18:04:46 by seok             ###   ########.fr       */
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
	int		i;
	float	tmp_y;
	float	tmp_z;

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		tmp_y = vars->map[i].y;
		tmp_z = vars->map[i].z;
		vars->map[i].y = tmp_y * cos(deg * M_PI / 180) \
							- tmp_z * sin(deg * M_PI / 180);
		vars->map[i].z = tmp_y * sin(deg * M_PI / 180) \
							+ tmp_z * cos(deg * M_PI / 180);
	}
}

void	y_rotation(t_vars *vars, int deg)
{
	int		i;
	float	tmp_x;
	float	tmp_z;

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		tmp_x = vars->map[i].x;
		tmp_z = vars->map[i].z;
		vars->map[i].x = tmp_x * cos(deg * M_PI / 180) \
							+ tmp_z * sin(deg * M_PI / 180);
		vars->map[i].z = tmp_z * cos(deg * M_PI / 180) \
							- tmp_x * sin(deg * M_PI / 180);
	}
}

void	z_rotation(t_vars *vars, int deg)
{
	int		i;
	float	tmp_x;
	float	tmp_y;

	i = -1;
	while (++i < vars->info.width * vars->info.height)
	{
		tmp_x = vars->map[i].x;
		tmp_y = vars->map[i].y;
		vars->map[i].x = tmp_x * cos(deg * M_PI / 180) \
							- tmp_y * sin(deg * M_PI / 180);
		vars->map[i].y = tmp_x * sin(deg * M_PI / 180) \
							+ tmp_y * cos(deg * M_PI / 180);
	}
}
