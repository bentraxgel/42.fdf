/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:59:40 by seok              #+#    #+#             */
/*   Updated: 2023/07/11 21:18:50 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_vars	vars;

	if (ac != 2)
		my_error("not 2 argc");
	cnt_width(av[1], &vars);
	cnt_height(av[1], &vars);
	vars.orimap = (t_coordinate *)alloc_guard(sizeof(t_coordinate) \
					, vars.info.width * vars.info.height);
	vars.map = (t_coordinate *)alloc_guard(sizeof(t_coordinate) \
					, vars.info.width * vars.info.height);
	parsing(&vars, av[1]);
	copy_ori(&vars, vars.orimap, vars.map);
	set_map_scale(&vars);
	set_map_center(&vars);
	z_rotation(&vars, 45);
	x_rotation(&vars, 30);
	init_mlx(&vars);
	init_hook(&vars);
	draw_map(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
	mlx_loop(vars.mlx);
	free(vars.orimap);
	free(vars.map);
	return (0);
}
