/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:27:02 by seok              #+#    #+#             */
/*   Updated: 2023/04/19 14:58:10 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	my_hex_char(unsigned long long n)
{
	char	ch;

	ch = 0;
	if (0 <= (n % 16) && (n % 16) <= 9)
		ch = (n % 16) + '0';
	else if (10 <= (n % 16) && (n % 16) <= 15)
		ch = (n % 16) - 10 + 'a';
	return (ch);
}

int	my_count(unsigned long long num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

char	*ft_itoa_hex_long(unsigned long long num)
{
	int		len;
	char	*ret;

	len = 0;
	if (num == 0)
	{
		ret = ft_strdup("0");
		return (ret);
	}
	len = my_count(num);
	ret = malloc(len + 1);
	if (!ret)
		return (0);
	ret[len] = 0;
	while (num > 0)
	{
		len--;
		ret[len] = my_hex_char(num);
		num /= 16;
	}
	return (ret);
}
