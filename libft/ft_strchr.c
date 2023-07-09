/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:13:36 by seok              #+#    #+#             */
/*   Updated: 2022/11/29 14:46:16 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	ch;
	int		i;
	char	*s;

	s = (char *)str;
	ch = (char)c;
	i = -1;
	while (s[++i])
	{
		if (s[i] == ch)
			return (&s[i]);
	}
	if (s[i] == ch)
		return (&s[i]);
	return (0);
}
