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
	t_vars			vars;
	t_data			image;
	t_info			info;

	if (ac != 2)
		my_error("not 2 argc");
	cnt_width(av[1], &info);
	cnt_height(av[1], &info);
	vars.orimap = (t_coordinate *)malloc(sizeof(t_coordinate) * (info.width * info.height));
	// free(vars.map);
	parsing(&vars, av[1], &info);
	copy_ori(&vars, &info);
/* need add scale setting func */
	info.scale = 50;
	info.high = 30;
	set_map_scale(&vars, &info);
	set_map_center(&vars, &info);
z_rotation(vars.map, &info, 45);
x_rotation(vars.map, &info, 30);
	set_window_center(&vars, &info);
	init_mlx(&vars, &image);
	init_hook(&vars);
	draw_map(&vars, &info, &image);
	mlx_put_image_to_window(vars.mlx, vars.win, image.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);

}
