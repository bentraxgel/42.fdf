/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:27:59 by quesera           #+#    #+#             */
/*   Updated: 2023/06/27 23:47:05 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	count_width(char *map)
// {
// 	int	fd;

// 	fd = open(map)
// }

void	pasing(char *map, t_info *dot_info)
{
	int		fd;
	int		i;
	char	*str;
	char	**word;
	i = 0;
	fd = open(map, O_RDONLY);
	while (get_next_line(fd, &str) == true)
	{
		dot_info->height++;
		word = ft_split(str, ' ');
		free(str);
		while (word[i])
			i++;
		if (dot_info->width != i)
		{
			while (i-- > 0)
				free(word[i]);
			free(word);
			my_error("different width length");
		}
		i = -1;
		while (word[++i])
		{
			// TODO 18일 atoi해서 받을것 좌표구조체에 넣기
			stack->a[stack->a_len - i - 1] = ft_atoi_pro(word[i]);
			
		}
		
	}
}

int	main(int ac, char *av[])
{
	t_coordinate	*map;
	t_info	info;

	cnt_width(av[1], &info);
	cnt_height(av[1], &info);
	map = (t_coordinate *)malloc(sizeof(t_coordinate) * (info.width * info.height));

	parsing(&map, av[1], &info);
	printf("width : %d\theight : %d\n", info.width, info.height);
/* 반복문 돌리며 값 넣기 */
}