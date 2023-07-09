/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:09:33 by seok              #+#    #+#             */
/*   Updated: 2022/12/13 22:46:50 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_idx;
	size_t	n_idx;

	h_idx = 0;
	n_idx = 0;
	if (*needle == 0)
	{
		return ((char *)haystack);
	}
	while (h_idx + n_idx < len && haystack[h_idx])
	{
		if (haystack[h_idx + n_idx] == needle[n_idx])
		{
			n_idx++;
			if (needle[n_idx] == 0)
				return ((char *)haystack + h_idx);
		}
		else
		{
			h_idx++;
			n_idx = 0;
		}
	}
	return (0);
}
