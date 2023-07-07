/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:17:56 by seok              #+#    #+#             */
/*   Updated: 2023/07/07 19:39:46 by seok             ###   ########.fr       */
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
#include <math.h>

#define COLOR 0xFFFFFF
#define	RAD	3.1415926 / 180
#define	DEGREE 15 //TODO 현재 매개변수deg로 변경했음 - 고민중
#define	WIN_W	1200
#define WIN_H	1100

typedef enum e_flag
{
	X = 0,
	Y,
	ON_KEYDOWN,
	ON_KEYUP, //필요없지않나?
	ON_MOUSEDOWN,
	ON_MOUSEUP,
	ON_MOUSEMOVE,
	ON_DESTROY = 17
}t_flag;

typedef enum e_key
{
	ESC = 53,
	X_KEY = 7,
	Y_KEY = 16,
	Z_KEY = 6,
	H_KEY = 4,
	G_KEY = 5,
	I_KEY = 34,
	O_KEY = 31,
	BENT_KEY = 33,
	LINE_KEY = 31,
	ONE_KEY = 18,
	TWO_KEY = 19,
	LEFT_KEY = 123,
	RIGHT_KEY,
	DOWN_KEY,
	UP_KEY
}t_key;

typedef struct s_position
{
	int x;
	int y;
	int add_x;
	int add_y;
	int	dx;
	int	dy;
	int	p;
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
	int	width;
	int	height;
	int	color;
	int	scale;
	int	high;
}t_info;

typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_coordinate	*map;
	t_coordinate	*orimap;
	t_data			image;
	t_info			info;
}t_vars;

// my_mlx.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// make_line.c -norm
void	set_position(t_position *pos, t_coordinate *cur, t_coordinate *next);
void	make_line(t_coordinate *cur, t_coordinate *next, t_data *image);
void	make_line1(t_position *pos, t_coordinate *cur, t_coordinate *next,t_data *image);
void	make_line2(t_position *pos, int color, t_data *image);
void	make_line3(t_position *pos, int color, t_data *image);

// main.c
char	*split_hex(char *str);
int	key_hook(int keycode, t_vars *vars);
int	mouse_hook(int button, int x, int y, t_vars *vars);
int	close_window(t_vars *vars);

// main_utill.c
int		my_error(char *err);
void	*alloc_guard(size_t typesize, size_t count);
void	copy_ori(t_vars *vars);

// parsing.c -norm
void	is_color(char *str, t_vars *vars);
void	cnt_height(char *av, t_vars *vars);
void	cnt_width(char *av, t_vars *vars);
void	parsing(t_vars *vars, char *av);
int		input_coordinates(char **word, t_vars *vars, int h);

// init.c
void	init_mlx(t_vars *vars);
void	init_hook(t_vars *vars);

// map_vis.c
void	set_map_scale(t_vars *vars);
void	set_map_center(t_vars *vars);
void	set_window_center(t_vars *vars);
void	draw_map(t_vars *vars, t_coordinate *map);

// rotation_matrix.c -norm
int near_int(double n);
void	x_rotation(t_vars *vars, int deg);
void	y_rotation(t_vars *vars, int deg);
void	z_rotation(t_vars *vars, int deg);
// void	x_rotation(t_vars *vars, t_coordinate *map, deg);
// void	y_rotation(t_vars *vars, t_coordinate *map, deg);
// void	z_rotation(t_vars *vars, t_coordinate *map, deg);

// hook.c
int	mouse_hook(int button, int x, int y, t_vars *vars);
int	mouse_hook(int button, int x, int y, t_vars *vars);
int	close_window(t_vars *vars);
void	handle_high(int keycode, t_vars *vars);
void	handle_rot(int keycode, t_vars *vars);
void	handle_zoom(int keycode, t_vars *vars);
void	arrow_keys(int keycode, t_vars *vars);
void	handle_zoom(int keycode, t_vars *vars);

// map_move.c
void	clear_img(t_vars *vars);
void	move_x(t_vars *vars, int keycode);
void	move_y(t_vars *vars, int keycode);
void	view_map(t_vars *vars, int keycode);

#endif