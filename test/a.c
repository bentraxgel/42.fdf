#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "get/get_next_line.h"

void	leaks(void)
{
	system("leaks -q a.out");
}

int	main()
{
	// atexit(leaks);
	int i = 0;
	char *str;
	int fd = open("c.txt", O_RDONLY);
	int	height;
	char *s = "b\n";

	if (fd < 0){
		printf("WAT");
		perror("fd!");
		return (0);
	}
	// get_next_line(fd, &str);
	// printf("%s", str);
	// while (get_next_line(fd, &str) == true && str != NULL)
	while (get_next_line(fd, &str) == true)
	{
		i++;
		if (i == 2)
		{
			perror("this is B");
			exit(-1);
		}
		printf("%d : %s", i, str);
		free(str);
	}
}

