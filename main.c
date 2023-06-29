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
	
	for (int i = 0; i < info.width * info.height; i++)
	{
		map[i].x *= 30;
		map[i].y *= 30;
		map[i].z *= 30;
		// map[i].y -= map[i].z * 30;
		map[i].x += 300;
		map[i].y += 200;
	}
	// z_rotation(map, &info);
	x_rotation(map, &info);
	y_rotation(map, &info);
	z_rotation(map, &info);
	// map[10].y += 10;
	
/* parsing - need add exception */
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1200, 1200, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 1200, 1200);
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
	mlx_loop(mlx_ptr);
	return (0);

}
