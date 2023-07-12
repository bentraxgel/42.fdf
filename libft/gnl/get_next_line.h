/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 01:59:31 by seok              #+#    #+#             */
/*   Updated: 2023/07/12 17:23:25 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_lst
{
	int				fd;
	char			buf[BUFFER_SIZE + 1];
	char			*save;
	struct s_lst	*next;
}t_lst;

size_t	my_strlen(const char *s);
void	my_lst_free(t_lst *find, t_lst *head);
char	*my_substr(char *s, unsigned int start, size_t len);
void	*my_memcpy(void *dest, const void *src, size_t len);
char	*my_strjoin(char *s1, char *s2);
t_lst	*my_lst_make(t_lst **head);
t_lst	*my_lst_find(t_lst **head, int f_fd);
int		my_save_buf(t_lst *find, char **ret, int check);
char	*my_save_check(int fd, t_lst **head);
int		get_next_line(int fd, char **ret);

#endif
