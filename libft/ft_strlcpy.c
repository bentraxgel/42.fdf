/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:10:49 by seok              #+#    #+#             */
/*   Updated: 2022/12/22 22:10:49 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	if (dstsize != 0)
	{
		while (src[idx] && idx < dstsize - 1)
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = 0;
	}
	return (ft_strlen(src));
}
