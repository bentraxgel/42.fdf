/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:53:31 by seok              #+#    #+#             */
/*   Updated: 2023/07/07 07:50:54 by seok             ###   ########.fr       */
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
	while (get_next_line(fd, &str) == true)
		info->height++;
	close(fd);
}

void	parsing(t_vars *vars, char *av, t_info *info)
{
	int		fd;
	int		i;
	int		h;
	char	*str;
	char	**word;

	h = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		my_error("file descriptor");
	while (get_next_line(fd, &str) == true)
	{
		word = ft_split(str, ' ');
		free(str);
		i = input_coordinates(word, info, vars, h);
		h++;
		if (info->width != i)
			my_error("different width length");
	}
	while (i-- > 0)
		free(word[i]);
	free(word);
	close(fd);
}

int	input_coordinates(char **word, t_info *info, t_vars *vars, int h)
{
	int	i;

	i = -1;
	while (word[++i] && i < info->width)
	{
		vars->orimap[i + (info->width * h)].x = i;
		vars->orimap[i + (info->width * h)].y = h;
		vars->orimap[i + (info->width * h)].color = COLOR;
		vars->orimap[i + (info->width * h)].z = ft_atoi(word[i]);
		if (vars->orimap[i + (info->width * h)].z != 0)
			vars->orimap[i + (info->width * h)].color = 0x00E47AE0;
		if (info->color == true)
			vars->orimap[i + (info->width * h)].color = my_atoi_hex(split_hex(word[i]));
	}
	return (i);
}
