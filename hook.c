/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 07:10:46 by seok              #+#    #+#             */
/*   Updated: 2023/07/07 08:34:28 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("%d (%d, %d)\n", button, x, y);
	(void)vars;
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->map);
		exit(0);
	}
	// else if (LEFT_KEY <= keycode <= UP_KEY)
	// 	arrow_keys(keycode, vars, info, image);
// 	else if (keycode == X_KEY)
// 		x_rotation(rotate())

	return (0);
}

// void	arrow_keys(int keycode, t_vars *vars, t_info *info, t_data *image)
// {
// 	if (keycode == LEFT_KEY)
// 		move_x(vars, info, image);
// }

int	close_window(t_vars *vars)
{
	// (void)vars;
	// printf("X keycode : %d\n", keycode);
	// mlx_destroy_image(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	if (vars->map != NULL)
		free(vars->map);
	exit(0); //이거만으로 돼?
}