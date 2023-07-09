/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:29:45 by seok              #+#    #+#             */
/*   Updated: 2023/06/21 14:29:56 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
