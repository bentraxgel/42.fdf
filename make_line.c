#include "fdf.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

void	make_line(t_coordinate *pos)
{
	pos->dx = ft_abs(pos->x2 - pos->x1);
	pos->dy = ft_abs(pos->y2 - pos->y1);

	if (pos->dy <= pos->dx)
	{

	}
	my_mlx_pixel_put()
}