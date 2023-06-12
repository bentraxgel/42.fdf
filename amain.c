// // /*
// #include "mlx.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "world!");
// 	img.img = mlx_new_image(mlx, 100, 800);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 100, 90, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 100, 91, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 100, 92, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 100, 93, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 100, 94, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 101, 94, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 102, 94, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 103, 94, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 104, 94, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 105, 94, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 200, 94, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 200, 93, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 200, 92, 0x00FF0000);
// 	my_mlx_pixel_put(&img, 200, 91, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 250, 190);
// 	mlx_loop(mlx);
// }
// // */
// /*
// #include "mlx.h"

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1050, 900, "Hello world!");
// 	img.img = mlx_new_image(mlx, 100, 100);// 이미지 instance 생성
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	//이미지의 주소 할당
// 	for(int i = 0; i < 1000 ; i++) {
// 		my_mlx_pixel_put(&img, i, i, 0x00FF0000);// 붉은색 선을 대각선으로 그린다.
// 		my_mlx_pixel_put(&img, 5, i, 0x00FF0000);// 붉은색 선을 세로으로 그린다.
// 		my_mlx_pixel_put(&img, i, 5, 0x00FF0000);// 붉은색 선을 가로으로 그린다.
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);//이미지를 윈도우에 올린다.
// 	mlx_loop(mlx);
// }
// // */
#include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}


int	main(void)
{
	// t_data	img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 920, 980, "Hello world!");
	mlx_pixel_put(mlx, mlx_win, 100, 100, 0xFFFFFF);
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_loop(mlx);
}