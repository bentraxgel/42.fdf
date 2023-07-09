/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:37:05 by seok              #+#    #+#             */
/*   Updated: 2022/12/30 04:33:46 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	idx;

	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		idx = 0;
		while (idx < len)
		{
			((unsigned char *)dest)[idx] = ((unsigned char *)src)[idx];
			idx++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dest)[len - 1] = ((unsigned char *)src)[len - 1];
			len--;
		}
	}
	return (dest);
}
