#include "fdf.h"
#include "libft/libft.h"

void	func(t_coordinate *map, t_info *info)
{
	printf("TEST\n");
	for (int h = 0; h < info->height; h++)
	{
		printf("[%d] ", h);
		for (int w = 0; w < info->width; w++)
		{
			int	idx = w + h * info->width;
			printf("(%d, %d, %d) ", map[idx].x, map[idx].y, map[idx].z);
		}
		printf("\n");
	}

}
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
	// z_rotation(map, &info, 45);
	
	int	scale = 5;
	int down = 3;
	// for (int i = 0; i < info.width * info.height; i++)
	// {
	// 	map[i].x -= (info.width / 2);
	// 	map[i].y -= (info.height / 2);
	// 	if (map[i].x == 0 && map[i].y == 0)
	// 		map[i].color = 0x00A5FF;
	// }
	// z_rotation(map, &info, 45);
	// x_rotation(map, &info, 30);

	printf("%d, %d\n", (WIN_W - (info.width * scale)), (WIN_H - (info.width * scale)));
	printf("%d, %d\n", ((WIN_W - (info.height * scale)) / 2), ((WIN_H - (info.height * scale)) / 2));


func(map, &info);
	for (int i = 0; i < info.width * info.height; i++)
	{
		map[i].x *= scale;
		map[i].y *= scale;
		map[i].z *= down;
	}
	z_rotation(map, &info, 45);
	for (int i = 0; i < info.width * info.height; i++)
	{
		map[i].x -= (info.width  * scale / 2);
		map[i].y -= (info.height * scale / 2);
		if (map[i].x == 0 && map[i].y == 0)
			map[i].color = 0x00A5FF; //TODO 파란색
	}

	// x_rotation(map, &info, 30);
// 	printf("map[0].x  y : %d   %d\n", map[0].x, map[0].y);
	// int	x0 = map[0].x * -1;
	// int y0 = map[0].y * -1;
	// for (int i = 0; i < info.width * info.height; i++)
	// {
	// 	// map[i].x += x0;
	// 	// map[i].y += y0;
	// 	map[i].x += ((WIN_W - (info.width * scale)) /2);
	// 	map[i].y += ((WIN_H - (info.width * scale)) /2);
	// }
	for (int i = 0; i < info.width * info.height; i++)
	{
		map[i].x += (WIN_W / 2);
		map[i].y += (WIN_H / 2);
	}
	// z_rotation(map, &info, 45);
// 	// x_rotation(map, &info, 30);

// func(map, &info);
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
	return (0);

}
