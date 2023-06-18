/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:17:56 by seok              #+#    #+#             */
/*   Updated: 2023/06/18 22:52:51 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include "minilibx/mlx.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#define COLOR 0x3399FF
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
	struct s_coordinate	*next;
}t_coordinate;

typedef struct s_info //TODO 초기화가 필요해
{
	t_coordinate *head;
	int			width;
	int			height;
}t_info;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

// my_mlx.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// make_line.c
int		ft_abs(int n);
void	set_position(t_position *pos, t_coordinate *dot);
void	make_line2(t_position *pos, coordinates p, t_data *image);
void	make_line(t_coordinate *dot, t_data *image);

// main.c
t_coordinate *new_coordinate(coordinates x, coordinates y, coordinates z);
void	add_coordinate(t_coordinate *dot, coordinates x, coordinates y, coordinates z);

// main_utill.c
int		my_error(char *err);
void	*alloc_guard(size_t typesize, size_t count);

// mapping.c
void	pasing(char *map);

#endif