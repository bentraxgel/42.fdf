/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:58:36 by seok              #+#    #+#             */
/*   Updated: 2023/04/19 14:13:07 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_unsign(unsigned int num)
{
	unsigned int	n;
	int				len;
	char			*ret;

	n = num;
	len = 0;
	if (num == 0)
		return (ft_strdup("0"));
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	ret = malloc(len + 1);
	if (!ret)
		return (0);
	ret[len] = 0;
	while (n > 0)
	{
		ret[--len] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}
