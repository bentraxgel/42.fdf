#include <mlx.h>

int main()
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 1000, 1000, "test");
	mlx_loop(mlx);
}