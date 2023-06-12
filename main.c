#include <unistd.h>
#include <mlx.h>

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
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hellow World!");
	image.img = mlx_new_image(mlx_ptr, 500, 500); // 이미지 객체 생성
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length, &image.endian); // 이미지 주소 할당
	for (int i = 0 ; i < 500 ; i++)
	{
		for (int j = 0 ; j < 400 ; j++)
		{
			mlx_pixel_put (mlx_ptr, win_ptr, i, j, 0x00FFFFFF);
			my_mlx_pixel_put(&image, i, j, 0x0000000F);
		}	
	}
	my_mlx_pixel_put(&image, 100, 100, 0x00FFFFFF);
	my_mlx_pixel_put(&image, 101, 101, 0x00FFFFFF);
	my_mlx_pixel_put(&image, 102, 102, 0x00FFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0x00FFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, 101, 99, 0x00FFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, 102, 98, 0x00FFFFFF);
	mlx_pixel_put(mlx_ptr, win_ptr, 103, 97, 0x00FFFFFF);
	mlx_put_image_to_window(mlx_ptr, win_ptr, image.img, 10, 100);
	mlx_loop(mlx_ptr);
	return (0);
}