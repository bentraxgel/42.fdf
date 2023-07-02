#include "fdf.h"
#include "libft/libft.h"
int	main(int ac, char *av[])
{
	int	row;
	int	col;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;
	t_info	info; // head주소 받는 애
	t_coordinate	*map;

	if (ac != 2)
		my_error("not 2 argc");
	cnt_width(av[1], &info);
	cnt_height(av[1], &info);
	map = (t_coordinate *)malloc(sizeof(t_coordinate) * (info.width * info.height));
	parsing(map, av[1], &info);
	
	int	scale = 1;
	int down = 1;
	for (int i = 0; i < info.width * info.height; i++)
	{
		// map[i].x *= scale;
		// map[i].y *= scale;
		// map[i].z *= down;

		// map[i].x *= scale;
		// map[i].y *= scale;
		// map[i].z *= down;

		map[i].x *= scale;
		map[i].y *= scale;
		map[i].z *= down;
	}
	for (int i = 0; i < info.width * info.height; i++)
	{
		map[i].x += ((WIN_H - (info.width * scale)) / 2);
		map[i].y += ((WIN_W - (info.width * scale)) / 2);
	}
	// printf("%d %d %d\n", map[0].x, map[0].y, map[0].z);
	z_rotation(map, &info, 45);
	// printf("%d %d %d\n", map[0].x, map[0].y, map[0].z);
	x_rotation(map, &info, 30);
	// printf("%d, %d\n", (WIN_W - (info.width * scale)), (WIN_H - (info.width * scale)));
	// printf("%d, %d\n", ((WIN_W - (info.height * scale)) / 2), ((WIN_H - (info.height * scale)) / 2));
	printf("%d %d %d\n", map[0].x, map[0].y, map[0].z);
	printf("%d %d %d\n", map[(info.height - 1) * info.width].x, map[(info.height - 1) * info.width].y, map[(info.height - 1) * info.width].z);
	// map[0].x = 100;
	// z_rotation(map, &info, 45);
	// not_z_rotation(map, &info, 45);
	// map[10].y += 10;
	
/* parsing - need add exception */
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_W, WIN_H, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, WIN_W, WIN_H);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	row = -1;
	while (++row < info.height)
	{
		col = -1;
		while (++col < info.width - 1)
			make_line(&map[info.width * row + col], &map[info.width * row + col + 1], &image);
		col = -1;
		while (row < info.height - 1 && ++col < info.width)
			make_line(&map[info.width * row + col], &map[info.width * (row + 1) + col], &image);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 0, 0);
	// mlx_key_hook(win_ptr, keypress, )
	mlx_loop(mlx_ptr);
	// for (int h = 0; h < info.height; h++)
	// {
	// 	for (int w = 0; w < w + (h * info.width); w++)
	// 	{
	// 		int	idx = w + h * info.width;
	// 		printf("(%d, %d, %d) ", map[idx].x, map[idx].y, map[idx].z);
	// 	}
	// 	printf("\n");
	// }
	return (0);

}
