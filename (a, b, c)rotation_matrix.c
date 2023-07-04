/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::  */
/*   rotation_matrix.c                                  :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2023/06/21 21:24:43 by seok              #+#    #+#            */
/*   Updated: 2023/07/04 23:11:35 by seok             ###   ########.fr      */
/*                                                                           */
/* ************************************************************************** */

// 기준이 되는 축을 (0, 0, 0)이 아닌 중간값으로 잡은 수식
// 근데 원하는 동작이 이루어 지지 않는다....왜?
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

void	x_rotation(t_coordinate *map, t_info *info, int deg)
{
	int	i;
	int tmp_y;
	int tmp_z;
	int	scale = 5;

	i = -1;
	while (++i < info->width * info->height)
	{
		tmp_y = map[i].y - info->height * scale / 2;
		tmp_z = map[i].z;
		map[i].y = near_int((tmp_y) * cos(deg * RAD) - tmp_z * sin(deg * RAD) + info->height * scale / 2);
		map[i].z = near_int((tmp_y) * sin(deg * RAD) + tmp_z * cos(deg * RAD));
	}
}

void	y_rotation(t_coordinate *map, t_info *info, int deg)
{
	int	i;
	int tmp_x;
	int tmp_z;
	int	scale = 5;

	i = -1;
	while (++i < info->width * info->height)
	{
		tmp_x = map[i].x - info->width * scale / 2;
		tmp_z = map[i].z;
		map[i].x = near_int(tmp_x * cos(deg * RAD) + tmp_z * sin(deg * RAD) + info->width * scale / 2);
		map[i].z = near_int(tmp_z * cos(deg * RAD) - tmp_x * sin(deg * RAD));
	}
}

void	z_rotation(t_coordinate *map, t_info *info, int deg)
{
	int i;
	int tmp_x;
	int tmp_y;
	int	scale = 5;

	i = -1;
	while (++i < info->width * info->height)
	{
		tmp_x = map[i].x - info->width * scale / 2;
		tmp_y = map[i].y - info->height * scale / 2;
		printf(">>>(%d, %d, %d)\n", map[i].x, map[i].y, map[i].z);
		map[i].x = near_int(tmp_x * cos(deg * RAD) - tmp_y * sin(deg * RAD) + info->width * scale / 2);
		map[i].y = near_int(tmp_x * sin(deg * RAD) + tmp_y * cos(deg * RAD) + info->height * scale / 2);
		printf(">>>(%d, %d, %d)\n", map[i].x, map[i].y, map[i].z);
	}
}

void	not_z_rotation(t_coordinate *map, t_info *info, int deg)
{
	int i;
	int tmp_x;
	int tmp_y;

	i = -1;
	while (++i < info->width * info->height)
	{
		tmp_x = map[i].x;
		tmp_y = map[i].y;
		map[i].x = near_int(tmp_x * cos(deg * RAD) - tmp_y * sin(deg * RAD));
		map[i].y = near_int(tmp_x * sin(deg * RAD) + tmp_y * cos(deg * RAD));
		deg = 30;
		int	tmp_z = map[i].z;
		map[i].y = near_int(map[i].y * cos(deg * RAD) - tmp_z * sin(deg * RAD));
		map[i].x = near_int(map[i].x * cos(deg * RAD) + tmp_z * sin(deg * RAD));
	}
}