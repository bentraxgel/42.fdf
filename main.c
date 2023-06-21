#include "fdf.h"
#include "libft/libft.h"
int	main()
{
	int	row;
	int	col;
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;
	t_info	info; // head주소 받는 애
	t_coordinate	*map;

	info.width = 2;
	info.height = 2;
	map = (t_coordinate *)malloc(sizeof(t_coordinate) * (info.width * info.height));
	map[0].x = 100;
	map[0].y = 100;
	map[1].x = 300;
	map[1].y = 100;
	map[2].x = 100;
	map[2].y = 300;
	map[3].x = 300;
	map[3].y = 300;
	
/* parsing */
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 800, 800);
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
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 100, 100);
	mlx_loop(mlx_ptr);
	return (0);

}
