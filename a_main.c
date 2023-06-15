#include <unistd.h>
#include "mlx.h"

//이미지의 정보를 나타내는 변수를 저장한 구조체
typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	image;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 800, 800); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	for (int i = 0 ; i < 800 ; i++)
	{
		for (int j = 0 ; j < 400 ; j++)
		{
			// mlx_pixel_put (mlx_ptr, win_ptr, i, j, 0x00FFFFFF);
			my_mlx_pixel_put(&image, i, j, 0xFF99CC);
		}	
	}
	for (int i = 100; i < 200; i++)
	{
		for (int j = 100; j < 200; j++)
			my_mlx_pixel_put(&image, i, j, 0x000000);
	}
	for (int i = 300; i < 500; i++)
		my_mlx_pixel_put(&image, i, 200, 0xFFFFFF);
	for (int i = 300; i < 500; i += 10)
	{
		my_mlx_pixel_put(&image, i, 200, 0x3399FF);
		my_mlx_pixel_put(&image, i + 1, 200, 0x3399FF);
		my_mlx_pixel_put(&image, i + 2, 200, 0x3399FF);
	}
	for (int i = 300; i < 500; i++)
		my_mlx_pixel_put(&image, i, 250, 0xFFFFFF);
	for (int i = 300; i < 500; i += 10)
	{
		my_mlx_pixel_put(&image, i, 250, 0x3399FF);
		my_mlx_pixel_put(&image, i + 1, 250, 0x3399FF);
		my_mlx_pixel_put(&image, i + 2, 250, 0x3399FF);
	}
	for (int i = 300; i < 500; i++)
		my_mlx_pixel_put(&image, i, 300, 0xFFFFFF);
	for (int i = 300; i < 500; i += 10)
	{
		my_mlx_pixel_put(&image, i, 300, 0x3399FF);
		my_mlx_pixel_put(&image, i + 1, 300, 0x3399FF);
		my_mlx_pixel_put(&image, i + 2, 300, 0x3399FF);
	}
	for (int row = 200; row <= 300; row += 50)
	{
		for (int col = 300; col <= 500; col++)
			my_mlx_pixel_put(&image, col, row, 0xFFFFFF);
		for (int col = 300; col <= 500; col += 10)
		{
			my_mlx_pixel_put(&image, col, row, 0x3388FF);
			my_mlx_pixel_put(&image, col, row + 1, 0x3388FF);
			my_mlx_pixel_put(&image, col, row + 1, 0x3388FF);
		}
	}
	for (int col = 300; col <= 500; col += 50)
	{
		for (int row = 200; row < 300; row++)
			my_mlx_pixel_put(&image, col, row, 0xFFFFFF);
		for (int row = 200; row < 300; row += 10)
		{
			my_mlx_pixel_put(&image, col, row, 0x3399FF);
			my_mlx_pixel_put(&image, col, row + 1, 0x3399FF);
			my_mlx_pixel_put(&image, col, row + 2, 0x3399FF);
		}
	}
	// my_mlx_pixel_put(&image, -500, -500, 0xFFFFFF);
	// my_mlx_pixel_put(&image, -501, -501, 0xFFFFFF);
	// my_mlx_pixel_put(&image, -502, -502, 0xFFFFFF);
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 10, 100);
	mlx_loop(mlx_ptr);
	return (0);
}