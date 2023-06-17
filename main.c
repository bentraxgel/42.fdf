#include "fdf.h"

int	main(int ac, char *av[])
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;
	t_info	dot_info; // head주소 받는 애
	coordinates	x = 100;
	coordinates	y = 100;
	coordinates	z = 0;

	if (ac != 2)
		my_error("argument error");
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 800, 800);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian);

	/* TODO 파싱해서 리스트에 집어넣어야함 */
// /*
	//TODO 이거 다시 결과물 출력해봐야함. 왜냐하면 나는 add_coordinate로 출력안된거같아.....젠장@!!!
	my_mlx_pixel_put(&image, x + 1, y + 1, COLOR);
	my_mlx_pixel_put(&image, x + 2, y + 2, COLOR);
	dot_info.head = new_coordinate(x, y, z); //head 생성됐잖아
	// // for (;x < 400; x += 50)
	// {
	// 	// for (;y < 300; y += 50)
			add_coordinate(dot_info.head, x + 1, y + 1, z); //리스트 만들어서 좌표값 집어넣는것.
			add_coordinate(dot_info.head, x + 2, y + 2, z); //head 주잖아 그러면...
	// }
	for (t_coordinate *tmp = dot_info.head; tmp->next != NULL; tmp = tmp->next)
		make_line(dot_info.head, &image);
// */
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