/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:00:16 by seok              #+#    #+#             */
/*   Updated: 2022/12/23 10:42:01 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa2(long long num, int len, char *ret)
{
	if (num < 0)
	{
		ret[0] = '-';
		num *= -1;
	}
	while (num)
	{
		ret[--len] = num % 10 + '0';
		num /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int			len;
	long long	num;
	char		*ret;

	len = 0;
	num = (long long)n;
	if (n == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num)
	{
		len++;
		num /= 10;
	}
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = 0;
	ret = ft_itoa2(n, len, ret);
	return (ret);
}
