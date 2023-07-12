/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:06:52 by seok              #+#    #+#             */
/*   Updated: 2023/07/12 17:23:34 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *s)
{
	int	idx;

	idx = 0;
	if (s == NULL)
		return (0);
	while (s[idx])
		idx++;
	return ((size_t) idx);
}

void	my_lst_free(t_lst *find, t_lst *head)
{
	t_lst	*temp;

	temp = head;
	while (temp->next != NULL && temp->next != find)
		temp = temp->next;
	if (head == NULL)
		free(head);
	if (find->save != NULL)
		free(find->save);
	temp->next = find->next;
	find->next = NULL;
	free(find);
}

char	*my_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	sstart;
	size_t	i;
	size_t	s_len;

	i = 0;
	sstart = (size_t)start;
	s_len = my_strlen(s);
	if (s_len <= sstart)
		return (NULL);
	if (s_len - start <= len)
		str = (char *)malloc(sizeof(char) * (s_len - start + 1));
	if (s_len - start > len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (s[sstart + i] && i < len)
	{
		str[i] = s[sstart + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	*my_memcpy(void *dest, const void *src, size_t len)
{
	char	*adr;

	adr = dest;
	if (dest == src)
		return (dest);
	while (len--)
	{
		*(char *)dest++ = *(char *)src++;
	}
	dest = adr;
	return (dest);
}

char	*my_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*ret;

	s1_len = my_strlen(s1);
	s2_len = my_strlen(s2);
	ret = (char *)malloc(s1_len + s2_len + 1);
	if (!ret)
		return (0);
	my_memcpy(ret, s1, s1_len);
	my_memcpy(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = 0;
	free(s1);
	return (ret);
}
