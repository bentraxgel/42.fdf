/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:53:31 by seok              #+#    #+#             */
/*   Updated: 2023/06/28 00:14:54 by seok             ###   ########.fr       */
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
	close(fd);
}

void	cnt_height(char *av, t_info *info)
{
	int		fd;
	char	*str;

	info->height = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &str) == true)
		info->height++;
	close(fd);
}

void	parsing(t_coordinate **map, char *av, t_info *info)
{
	int		fd;
	int		i;
	int		h;
	char	*str;
	char	**word;

	h = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &str) == true)
	{
		i = -1;
		word = ft_split(str, ' ');
		free(str);
		if (info->color == true)
			map[i + (info->width * h)]->color = ft_itoa_hex_long
		while (word[++i])
		{
			map[i + (info->width * h)]->x = i;
			map[i + (info->width * h)]->y = h;
			map[i + (info->width * h)]->z = ft_atoi_pro(word[i]);
		}
		if (info->width != i)
			my_error("different width length");
		
	}
	while (i-- > 0)
		free(word[i]);
	free(word);
}