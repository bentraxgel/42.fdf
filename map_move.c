/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 07:20:51 by seok              #+#    #+#             */
/*   Updated: 2023/07/07 08:37:53 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_x(t_vars *vars, t_info *info, t_data *image)
{
	int i;

	i = -1;
	copy_ori(vars, info);
	while (++i < info->width * info->height)
	{
		vars->map[i].x += 1;
		// vars->map[i].y += (WIN_H / 2);
	}
	draw_map(vars, info, image);
}