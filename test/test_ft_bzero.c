#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
	char buffer[10];

	int i;
	
	i = 0;
	while (i< 10)
	{
		buffer[i] = 'A';
		i++;
	}
	printf("Before ft_bzero:\n");
	i = 0;
	while (i<10)
	{
		printf("%02x", (unsigned char)buffer[i]);
		i++;
	}
	printf("\n");

	ft_bzero(buffer+2, 5);
	printf("After ft_bzero(buffer+2, 5):\n");
	
	i = 0;
	while(i<10)
	{
		printf("%02x ", (unsigned char) buffer[i]);
		i++;
	}
	printf("\n");

	return 0;
}

//cc -Wall -Wextra -Werror -I../ -L../ -lft ../test/test_ft_bzero.c -o test_ft_bzero
