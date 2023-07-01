/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 00:17:39 by quesera           #+#    #+#             */
/*   Updated: 2023/07/01 20:25:01 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	my_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

void	*alloc_guard(size_t typesize, size_t count)
{
	void	*ret;

	if (count < 0 || typesize < 0)
		my_error("malloc error");
	if (count == 0 || typesize == 0)
	{
		count = 1;
		typesize = 1;
	}
	if (SIZE_MAX / typesize < count)
		my_error("malloc error");
	ret = (void *)malloc(count * typesize);
	if (!ret)
		my_error("malloc error_null guard");
	ft_memset(ret, 0, count * typesize);
	return (ret);
}

// int	set_center(t_info info, t_flag flag)
// {
// 	if (flag == X)
// 	{
// 		(WIN_W - info.width) / 2
// 	}
// }