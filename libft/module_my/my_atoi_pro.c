/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi_pro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:24:20 by seok              #+#    #+#             */
/*   Updated: 2023/06/28 03:47:51 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isspace_pro(int c)
{
	return (c == 32 || (8 < c && c < 14));
}

void	my_check_digit(const char *str)
{
	if (ft_strlen(str) != 1 && (*str == '-' || *str == '+'))
		str++;
	while (*str)
	{
		if (ft_isdigit((int)*str))
			str++;
		else
			exit(EXIT_FAILURE);
	}
}

void	my_check_limit(int sign, int cnt)
{
	if ((sign == -1 && cnt > 11) || (sign == 1 && cnt > 10))
		exit(EXIT_FAILURE);
}

int	my_atoi_pro(const char *str)
{
	int			sign;
	int			cnt;
	long long	result;

	sign = 1;
	cnt = 0;
	result = 0;
	while (ft_isspace_pro(*str))
		str++;
	my_check_digit(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		cnt++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = (result * 10) + *str - '0';
		str++;
		cnt++;
	}
	my_check_limit(sign, cnt);
	return (result * sign);
}
