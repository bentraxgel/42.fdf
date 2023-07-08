/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 21:53:31 by seok              #+#    #+#             */
/*   Updated: 2023/07/08 16:41:39 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	is_color(char *str, t_vars *vars)
{
	char	**word;
	int		i;

	i = 0;
	word = ft_split(str, ',');
	if (ft_strncmp(word[1], "0x", 2) == 0)
		vars->info.color = true;
	else
		vars->info.color = false;
	while (word[i])
		i++;
	while (i-- > 0)
		free(word[i]);
	free(word);
}

void	cnt_width(char *av, t_vars *vars)
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
		is_color(word[0], vars);
		while (word[i])
			i++;
		vars->info.width = i;
		while (i-- > 0)
			free(word[i]);
		free(word);
	}
	while (get_next_line(fd, &str) == true)
		free(str);
	close(fd);
}

void	cnt_height(char *av, t_vars *vars)
{
	int		fd;
	char	*str;

	vars->info.height = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &str) == true)
	{
		vars->info.height++;
		free(str);
	}
	close(fd);
}

void	parsing(t_vars *vars, char *av)
{
	int		fd;
	int		i;
	int		h;
	char	*str;
	char	**word;

	h = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0) //TODO open오류일경우 ㅣ어디에 둘까..
		my_error("file descriptor");
	while (get_next_line(fd, &str) == true)
	{
		word = ft_split(str, ' ');
		free(str);
		i = input_coordinates(word, vars, h);
		h++;
		if (vars->info.width != i)
			my_error("different width length");
	}
	while (i-- > 0)
		free(word[i]);
	free(word);
	close(fd);
}

int	input_coordinates(char **word, t_vars *vars, int h)
{
	int	i;

	i = -1;
	vars->z_scale = 1;
	while (word[++i] && i < vars->info.width)
	{
		vars->orimap[i + (vars->info.width * h)].x = i;
		vars->orimap[i + (vars->info.width * h)].y = h;
		vars->orimap[i + (vars->info.width * h)].color = COLOR;
		vars->orimap[i + (vars->info.width * h)].z = ft_atoi(word[i]);
		if (vars->orimap[i + (vars->info.width * h)].z != 0)
			vars->orimap[i + (vars->info.width * h)].color = 0x00E47AE0;
		if (vars->info.color == true)
			vars->orimap[i + (vars->info.width * h)].color \
				= my_atoi_hex(split_hex(word[i]));
	}
	return (i);
}
