#include <stdio.h>
#include <stdlib.h>
#include "libft.h"


// SPLIT MAIN 
int main (int argc, char **argv)
{
	int i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	while (argv[i])
	{
		printf("pointer %p , %s \n", argv[i], argv[i]);
		++i;
	}
	while (argv[i])
		free(argv[i++]);
	free(argv);
}