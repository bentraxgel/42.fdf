/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:53:31 by seok              #+#    #+#             */
/*   Updated: 2023/07/02 18:54:36 by seok             ###   ########.fr       */
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
	while (get_next_line(fd, &str) == true && str != NULL)
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
	while (get_next_line(fd, &str) == true)
	{
		i = -1;
		word = ft_split(str, ' ');
		free(str);
		while (word[++i] && i < info->width)
		{
			// if (ft_strncmp(word[i], "\n", 2) == 0)
			// 	printf("cmp\n") ;
			// printf("word[%d] : %s++\n", i, word[i]);
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

char	*split_hex(char *str)
{
	char **word;

	word = ft_split(str, ',');
	return (word[1]);
}

int	htod(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else
	{
		if ('A' <= c && c <= 'F')
			return (c - 'A' + 10);
		else if ('a' <= c && c <= 'f')
			return (c - 'a' + 10);
		else
		{
			// printf("\n%d\n", c);
			my_error("atoi_hex");
		}
	}
	return (-1);
}

int	my_atoi_hex(const char *str)
{
	int	result;
	int	digit;
	int	i;
	int	sign;

	result = 0;
	digit = 1;
	sign = 0;
	if (ft_strncmp(str, "0x", 2) == 0)
		sign = 2;
	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	while (str[--i] && i >= sign)
	{
		// printf("str[%d]:%s++\n", i, str);
		result += htod(str[i]) * digit;
		digit *= 16;
	}
	return (result);
}
