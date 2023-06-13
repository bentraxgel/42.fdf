/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:53:30 by seok              #+#    #+#             */
/*   Updated: 2022/12/30 10:57:13 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*s;
	char	ch;

	len = ft_strlen(str);
	s = (char *)str;
	ch = (char)c;
	if (c == 0)
		return (&s[len]);
	while (len)
	{
		if (s[len] == ch)
			return (&s[len]);
		len--;
	}
	if (s[len] == ch)
		return (&s[len]);
	return (0);
}
