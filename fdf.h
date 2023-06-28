/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:17:56 by seok              #+#    #+#             */
/*   Updated: 2023/06/28 10:17:53 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "libft/gnl/get_next_line.h"
#include "minilibx/mlx.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

#define COLOR 0xFFFFFF

typedef struct s_position
{
	int x;
	int y;
	int add_x;
	int add_y;
	int	dx;
	int	dy;
}t_position;

typedef struct s_coordinate
{
	int	x;
	int	y;
	int z;
	int	color;
}t_coordinate;

typedef struct s_info
{
	t_coordinate *head;
	t_coordinate *tail;
	int	width;
	int	height;
	int	color;
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
void	set_position(t_position *pos, t_coordinate *cur, t_coordinate *next);
void	make_line(t_coordinate *cur, t_coordinate *next, t_data *image);

// main.c
/* 연결리스트를 사용하지 않으므로 그대들은 무덤으로 가시게
	t_coordinate *new_coordinate(int x, int y, int z);
	// void	add_coordinate(t_coordinate *dot, int x, int y, int z);
	void	add_coordinate(t_coordinate *dot, t_info *dot_info, int x, int y, int z);
	void	a_add_coordinate(t_info *dot_info, int x, int y, int z);
*/

// main_utill.c
int	my_error(char *err);
void	*alloc_guard(size_t typesize, size_t count);

// parsing.c
void	parsing(t_coordinate *map, char *av, t_info *info);
void	cnt_height(char *av, t_info *info);
void	cnt_width(char *av, t_info *info);
void	is_color(char *str, t_info *info);

#endif