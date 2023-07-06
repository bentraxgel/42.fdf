/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:37:34 by seok              #+#    #+#             */
/*   Updated: 2023/07/07 06:34:41 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_position(t_position *pos, t_coordinate *cur, t_coordinate *next)
{
	pos->x = cur->x;
	pos->y = cur->y;
	pos->dx = ft_abs(cur->x - next->x);
	pos->dy = ft_abs(cur->y - next->y);
	if (cur->x <= next->x)
		pos->add_x = 1;
	else
		pos->add_x = -1;
	if (cur->y <= next->y)
		pos->add_y = 1;
	else
		pos->add_y = -1;
}

void	make_line(t_coordinate *cur, t_coordinate *next, t_data *image)
{
	t_position	pos;

	set_position(&pos, cur, next);
	if (pos.dy <= pos.dx)
	{
		pos.p = 2 * (pos.dy - pos.dx);
		if (cur->x <= next->x)
		{
			while (pos.x <= next->x)
				make_line2(&pos, cur->color, image);
		}
		else
		{
			while (pos.x >= next->x)
				make_line2(&pos, next->color, image);
		}
	}
	else
		make_line1(&pos, cur, next, image);
}

void	make_line1(t_position *pos, t_coordinate *cur, \
					t_coordinate *next, t_data *image)
{
	pos->p = 2 * (pos->dx - pos->dy);
	if (cur->y <= next->y)
	{
		while (pos->y <= next->y)
			make_line3(pos, next->color, image);
	}
	else
	{
		while (pos->y >= next->y)
			make_line3(pos, next->color, image);
	}
}

void	make_line2(t_position *pos, int color, t_data *image)
{
	if (pos->p <= 0)
		pos->p += 2 * pos->dy;
	else
	{
		pos->p += 2 * (pos->dy - pos->dx);
		pos->y += pos->add_y;
	}
	my_mlx_pixel_put(image, pos->x, pos->y, color);
	pos->x += pos->add_x;
}

void	make_line3(t_position *pos, int color, t_data *image)
{
	if (pos->p <= 0)
		pos->p += 2 * pos->dx;
	else
	{
		pos->p += 2 * (pos->dx - pos->dy);
		pos->x += pos->add_x;
	}
	my_mlx_pixel_put(image, pos->x, pos->y, color);
	pos->y += pos->add_y;
}
