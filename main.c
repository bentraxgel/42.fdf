#include "fdf.h"

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;
	// t_info	dot_info; // head주소 받는 애
	coordinates	x = 100;
	coordinates y = 100;
	// coordinates z = 0;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 800, 800);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	my_mlx_pixel_put(&image, x, y, COLOR);
	// dot_info.head = new_coordinate(x, y, z); //head 생성됐잖아
	// // for (;x < 400; x += 50)
	// {
	// 	// for (;y < 300; y += 50)
	// 		add_coordinate(dot_info.head, x, y, z); //head 주잖아 그러면...
	// }
	// make_line(dot_info.head, &image);
	
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 10, 100);
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

void	add_coordinate(t_coordinate *dot, coordinates x, coordinates y, coordinates z)
{
	t_coordinate	*temp;

	temp = dot;
	if (dot == NULL)
	{
		dot = new_coordinate(x, y, z);
		return ;
	}
	while (temp && temp->next != NULL)
		temp = temp->next;
	temp->next = new_coordinate(x, y, z);
}