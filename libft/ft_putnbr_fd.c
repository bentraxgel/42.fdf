/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:51:30 by seok              #+#    #+#             */
/*   Updated: 2022/12/30 10:20:09 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	my_num_len(int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

void	my_exception(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char		s[12];
	int			len;

	if (n == 0 || n == -2147483648)
	{
		my_exception(n, fd);
		return ;
	}
	len = my_num_len(n);
	if (n < 0)
	{
		len++;
		s[0] = '-';
		n *= -1;
	}
	s[len] = 0;
	while (n)
	{
		s[--len] = n % 10 + '0';
		n /= 10;
	}
	ft_putstr_fd(s, fd);
}
