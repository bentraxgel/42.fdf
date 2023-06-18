#include <stdio.h>

void	func(char **str)
{
	*str = "hi";
}

int	main()
{
	char *str;
	str = "bye";
	printf("B : %s\n", str);
	func(&str);
	printf("A : %s\n", str);
}