#include <stdio.h>
#include <fcntl.h>
#include "gnl/get_next_line.h"

int	main()
{
	char *str;
	int fd = open("c.txt", O_RDONLY);
	int	height;

	while (get_next_line(fd, str) == true)
	{
		printf("%s\n", str);
	}
}

