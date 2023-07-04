/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:53:31 by seok              #+#    #+#             */
/*   Updated: 2023/07/04 18:16:54 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	is_color(char *str, t_info *info)
{
	char	**word;

	word = ft_split(str, ',');
	if (ft_strncmp(word[1], "0x", 2) == 0)
		info->color = true;
	else
		info->color = false;
}
void	cnt_width(char *av, t_info *info)
{
	int		fd;
	int		i;
	char	*str;
	char	**word;

	i = 0;
	fd = open(av, O_RDONLY);
	if (get_next_line(fd, &str) == true)
	{
		word = ft_split(str, ' ');
		free(str);
		is_color(word[0], info);
		while (word[i])
			i++;
		info->width = i;
		while (i-- > 0)
			free(word[i]);
		free(word);
	}
	while (get_next_line(fd, &str) == true)
		free(str);
	close(fd);
}

void	cnt_height(char *av, t_info *info)
{
	int		fd;
	char	*str;

	info->height = 0;
	fd = open(av, O_RDONLY);
	// while (get_next_line(fd, &str) == true && str != NULL)
	while (get_next_line(fd, &str) == true) //TODO 뭔 차이인지는 모르겠지만 위에서 아래로 함 바꿔봄
		info->height++;
	close(fd);
}

void	parsing(t_coordinate *map, char *av, t_info *info)
{
	int		fd;
	int		i;
	int		h;
	char	*str;
	char	**word;

	h = 0;
	fd = open(av, O_RDONLY);
		int	a = 0;
	while (get_next_line(fd, &str) == true)
	{
		a++;
		i = -1;
		word = ft_split(str, ' ');
		// for (int i = 0; word[i]; i++)
		// 	printfx[%d] : %s\n", i, word[i]);
		free(str);
		// while (word[++i] && i + (info->width * h) < info->width * info->height)
		while (word[++i] && i < info->width)
		{
			// if (ft_strncmp(word[i], "\n", 2) == 0)
			// 	printf("cmp\n") ;
			// printf("word[%d] : %s++\n", i, word[i]);
			// map[i + (info->width * h)].x = i - (info->width / 2);
			// map[i + (info->width * h)].y = h - (info->height / 2);
			map[i + (info->width * h)].x = i;
			map[i + (info->width * h)].y = h;
			map[i + (info->width * h)].color = COLOR;
			map[i + (info->width * h)].z = ft_atoi(word[i]);
			if (map[i + (info->width * h)].z != 0)
				map[i + (info->width * h)].color = 0xE47AE0;
			if (info->color == true)
			{
				// printf("word[%d] : %s++\n", i, word[i]);
				map[i + (info->width * h)].color = my_atoi_hex(split_hex(word[i]));
			}
		}
		h++;
		if (info->width != i)
			my_error("different width length");
	}
	while (i-- > 0)
		free(word[i]);
	free(word);
	close(fd);
}
