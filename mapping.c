/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:27:59 by quesera           #+#    #+#             */
/*   Updated: 2023/06/18 03:54:00 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_width(char *map)
{
	int	fd;

	fd = open(map)
}

void	pasing(char *map, t_info *dot_info)
{
	int		fd;
	char	*str;

	dot_info->width = count_width(map);
	dot_info->height = count_height(map);
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, str) == true)
}

int	main(int ac, char *av[])
{
	t_info	info;
	pasing(av[1], &info);
	printf("width : %d\theight : %d\n", info.width, info.height);
}