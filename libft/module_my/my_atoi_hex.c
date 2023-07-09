/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:25:39 by seok              #+#    #+#             */
/*   Updated: 2023/07/07 17:58:55 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../../fdf.h"

char	*split_hex(char *str)
{
	char **word;

	word = ft_split(str, ',');
	return (word[1]);
}

int	htod(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	else
	{
		if ('A' <= c && c <= 'F')
			return (c - 'A' + 10);
		else if ('a' <= c && c <= 'f')
			return (c - 'a' + 10);
		else
			my_error("atoi_hex");
	}
	return (-1);
}

int	my_atoi_hex(const char *str)
{
	int	result;
	int	digit;
	int	i;
	int	sign;

	result = 0;
	digit = 1;
	sign = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_strncmp(str, "0x", 2) == 0)
		sign = 2;
	i = 0;
	while (str[i] != 0 && str[i] != '\n')
		i++;
	while (str[--i] && i >= sign)
	{
		result += htod(str[i]) * digit;
		digit *= 16;
	}
	return (result);
}
