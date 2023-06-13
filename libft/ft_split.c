/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:50:17 by seok              #+#    #+#             */
/*   Updated: 2022/12/30 01:18:13 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	my_free(char **arr)
{
	int	idx;

	idx = 0;
	while (arr[idx])
	{
		free(arr[idx]);
		idx++;
	}
	free(arr);
	arr = NULL;
}

int	my_word_check(char const *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			word++;
		i++;
	}
	return (word);
}

int	my_word_count(char const *s, char c, char **arr, int word)
{
	int	idx;
	int	i;
	int	count;

	idx = 0;
	i = 0;
	while (s[i] && i < word)
	{
		count = 0;
		while (s[idx] != c && s[idx] != '\0')
		{
			count++;
			idx++;
		}
		if (count != 0)
		{
			arr[i] = (char *)malloc(sizeof(char) * (count + 1));
			if (!arr[i])
				return (0);
			ft_strlcpy(arr[i], &s[idx - count], count + 1);
			i++;
		}
		idx++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word;

	if (!s)
		return (0);
	arr = NULL;
	word = my_word_check(s, c);
	arr = (char **)malloc(sizeof(char *) * (word + 1));
	if (!arr)
		return (0);
	arr[word] = 0;
	if (word)
	{
		if (!my_word_count(s, c, arr, word))
			my_free(arr);
	}
	return (arr);
}
