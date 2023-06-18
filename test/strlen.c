#include <stdio.h>
#include "../libft/libft.h"

// void	free_array(char ***arr, int i)
// {
// 	printf("*** : %c\n", ***arr + 1);
// 	printf("** : %s\n", **arr);
// 	printf("** : %s\n", **arr + 1);
// 	printf("* : %s\n", *arr);
// 	// printf(" : %s\n", arr);
// 	while (i-- > 0)
// 		free(***(arr + i));
// 	free(**arr);
// }
typedef struct s_info //TODO 초기화가 필요해 : memset으로 히먄 돼!
{
	int			width;
	int			height;
}t_info;

void	leaks()
{
	system("leaks -q a.out");
}

int	main()
{
	t_info	info;

	printf("1 : %d\t2 : %d\n", info.width, info.height);
	ft_memset(&info, 0, sizeof(t_info));
	printf("1 : %d\t2 : %d\n", info.width, info.height);
	atexit(leaks);
	char	*str = "102 sec 3 4 5";
	char	**word;
	int		i;

	word = ft_split(str, ' ');
	for (; word[i]; i++)
		i += 0;
	char	*len;
	len = *word;
	printf("i ; %d\tlen : %lu\n", i, ft_strlen(len));
	i = 0;
	while (word[i] != NULL)
		printf("[]%s\n", word[i++]);
	i = -1;
	while (*(word + ++i) != NULL)
		printf("*%s\n", *(word + i));
	while (i-- > 0)
		free(word[i]);
	free(word);
	// free_array(&word, i);
}