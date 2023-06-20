#include "fdf.h"
#include "libft/libft.h"
int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;
	t_info	dot_info; // head주소 받는 애
	// t_coordinate	*col;
	coordinates	x = 100;
	coordinates y = 100;
	coordinates z = 0;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 800, 800);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);
//TODO
	my_mlx_pixel_put(&image, x + 1, y + 1, 0xFFE13C);
	my_mlx_pixel_put(&image, x + 2, y + 1, 0xFFE13C);
	my_mlx_pixel_put(&image, x + 3, y + 1, 0xFFE13C);
	//my_mlx_pixel_put(&image, x + 2, y + 2, COLOR);
	// dot_info.head = new_coordinate(x, y, z); //head 생성됐잖아
//	for (;x < 400; x += 50)
//	 {
//		 for (;y < 300; y += 50)]
	//		add_coordinate(dot_info.head, x, y, z); //head 주잖아 그러면...

			// col = NULL;
			// add_coordinate(col, &dot_info, x + 2, y + 2, z);
			// // dot_info.head = col;
			// add_coordinate(col, &dot_info, x + 200, y + 200, z);
//	 }
ft_strlen("12");
	ft_memset(&dot_info, 0, sizeof(t_info));
	a_add_coordinate(&dot_info, x + 1, y + 1, z + 1);
	a_add_coordinate(&dot_info, x + 100, y + 100, z + 1);
	for (t_coordinate *tmp = dot_info.head; tmp->next != NULL; tmp = tmp->next)
	{
		make_line(tmp, &image);
	}

	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 100, 100);
	mlx_loop(mlx_ptr);
	return (0);

}

t_coordinate *new_coordinate(coordinates x, coordinates y, coordinates z)
{
	t_coordinate	*newdot;

	newdot = (t_coordinate *)malloc(sizeof(t_coordinate));
	if (!newdot)
		return (0);
	newdot->x = x;
	newdot->y = y;
	newdot->z = z;
	newdot->next = NULL;
	return (newdot);
}

void	add_coordinate(t_coordinate *dot, t_info *dot_info, coordinates x, coordinates y, coordinates z)
{
	// t_coordinate	*temp;

	// temp = dot;
	if (dot == NULL)
	{
		dot = new_coordinate(x, y, z);
		dot_info->head = dot;
		return ;
	}
	else
	{
		while (dot != NULL && dot->next != NULL)
			dot = dot->next;
		dot->next = new_coordinate(x, y, z);
	}
}
