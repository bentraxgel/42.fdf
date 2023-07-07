#include "fdf.h"
#include "libft/libft.h"

void	func(t_vars *vars, t_info *info)
{
	printf("TEST\n");
	for (int h = 0; h < info->height; h++)
	{
		printf("[%d] ", h);
		for (int w = 0; w < info->width; w++)
		{
			int	idx = w + h * info->width;
			printf("(%d, %d, %d) ", vars->map[idx].x, vars->map[idx].y, vars->map[idx].z);
		}
		printf("\n");
	}

}

void	leaks()
{
	system("leaks fdf");
}
#include <stdlib.h>
int	main(int ac, char *av[])
{
	// atexit(leaks);
	t_vars	vars;

	if (ac != 2)
		my_error("not 2 argc");
	cnt_width(av[1], &vars);
	cnt_height(av[1], &vars);
	vars.orimap = (t_coordinate *)malloc(sizeof(t_coordinate) * vars.info.width * vars.info.height);
	vars.map = (t_coordinate *)malloc(sizeof(t_coordinate) * vars.info.width * vars.info.height);
	// free(vars.map);
	parsing(&vars, av[1]);
	copy_ori(&vars);
	set_map_scale(&vars);
	set_map_center(&vars);
z_rotation(&vars, 45);
x_rotation(&vars, 30);
	set_window_center(&vars);
	init_mlx(&vars);
	init_hook(&vars);
	draw_map(&vars, vars.map);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.image.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);

}
