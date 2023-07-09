/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:27:10 by seok              #+#    #+#             */
/*   Updated: 2022/12/06 03:45:30 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				idx;

	p1 = s1;
	p2 = s2;
	idx = 0;
	if (len != 0)
	{
		while (idx < len)
		{
			if (p1[idx] != p2[idx])
				return (p1[idx] - p2[idx]);
			idx++;
		}
	}
	return (0);
}
