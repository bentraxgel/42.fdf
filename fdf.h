/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:17:56 by seok              #+#    #+#             */
/*   Updated: 2023/06/19 21:13:57 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx/mlx.h"

#define COLOR 0xF25000
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

typedef struct s_info
{
	t_coordinate *head;
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
// void	add_coordinate(t_coordinate *dot, coordinates x, coordinates y, coordinates z);
void	add_coordinate(t_coordinate *dot, t_info *dot_info, coordinates x, coordinates y, coordinates z);


#endif