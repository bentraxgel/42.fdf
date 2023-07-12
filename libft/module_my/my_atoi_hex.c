/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:09:49 by seok              #+#    #+#             */
/*   Updated: 2023/07/12 17:21:45 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../../fdf.h"

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

int	my_atoi_hex2(const char *str, int sign)
{
	int	result;
	int	digit;
	int	i;

	result = 0;
	digit = 1;
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

int	my_atoi_hex(const char *str)
{
	int		result;
	int		i;
	int		sign;
	char	**word;

	sign = 0;
	word = ft_split(str, ',');
	str = word[1];
	i = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_strncmp(str, "0x", 2) == 0)
		sign = 2;
	result = my_atoi_hex2(str, sign);
	i = 0;
	while (word[i])
		free(word[i++]);
	free(word);
	return (result);
}
