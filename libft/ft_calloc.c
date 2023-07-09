/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:35 by seok              #+#    #+#             */
/*   Updated: 2022/12/20 09:46:35 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t typesize, size_t count)
{
	void	*ret;

	if (count < 0 || typesize < 0)
		return (0);
	if (count == 0 || typesize == 0)
	{
		count = 1;
		typesize = 1;
	}
	if (SIZE_MAX / typesize < count)
		return (0);
	ret = (void *)malloc(count * typesize);
	if (!ret)
		return (0);
	ft_memset(ret, 0, count * typesize);
	return (ret);
}
