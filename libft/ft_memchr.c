/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:38:09 by seok              #+#    #+#             */
/*   Updated: 2022/12/30 10:56:03 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int value, size_t len)
{
	while (len--)
	{
		if (*(unsigned char *)str != (unsigned char)value)
			str++;
		else
			return ((void *)str);
	}
	return (0);
}
