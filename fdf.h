/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:17:56 by seok              #+#    #+#             */
/*   Updated: 2023/06/15 20:37:31 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx/mlx.h"
typedef int coordinates;

typedef struct s_position
{
	coordinates x;
	coordinates y;
	coordinates add_x;
	coordinates add_y;
	coordinates	dx;
	coordinates	dy;
}t_position;

typedef struct s_coordinate
{
	coordinates	x;
	coordinates	y;
	coordinates z;
	//+? color variable
	struct s_coordinate	next;
}t_coordinate;

typedef struct s_info
{
	t_coordinate head;
}t_info;

#endif