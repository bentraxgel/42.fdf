/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:06:36 by seok              #+#    #+#             */
/*   Updated: 2022/12/22 22:06:36 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	d_idx;
	size_t	s_idx;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	d_idx = d_len;
	s_idx = 0;
	if (d_len < size)
	{
		while (src[s_idx] && size - 1 - d_idx)
		{
			dst[d_idx] = src[s_idx];
			d_idx++;
			s_idx++;
		}
		dst[d_idx] = 0;
		return (d_len + s_len);
	}
	return (s_len + size);
}
