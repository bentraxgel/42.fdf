/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:27:02 by seok              #+#    #+#             */
/*   Updated: 2023/04/19 14:49:16 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_itoa_hex_ch(char ch, unsigned int decimal)
{
	if (0 <= decimal && decimal <= 9)
		return (decimal + '0');
	else if (10 <= decimal && decimal <= 15)
	{
		if (ch == 'x')
			return (decimal - 10 + 'a');
		else if (ch == 'X')
			return (decimal - 10 + 'A');
	}
	return (0);
}

char	*ft_itoa_hex(unsigned int num, char ch)
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
		num /= 16;
	}
	ret = malloc(len + 1);
	if (!ret)
		return (0);
	ret[len] = 0;
	while (n > 0)
	{
		len--;
		ret[len] = ft_itoa_hex_ch(ch, n % 16);
		n /= 16;
	}
	return (ret);
}
