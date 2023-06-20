#include "fdf.h"


void	a_add_coordinate(t_info *dot_info, coordinates x, coordinates y, coordinates z)
{
	// t_coordinate	*temp;

	// temp = dot;
	if (dot_info->head == NULL)
	{
		dot_info->head = new_coordinate(x, y, z);
		dot_info->tail = dot_info->head;
		return ;
	}
	else
	{
		dot_info->tail->next = new_coordinate(x, y, z);
		dot_info->tail = dot_info->tail->next;
	}
}
