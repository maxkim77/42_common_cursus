#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

void print_memory(const void *ptr, size_t size)
{
	const unsigned char *p = (const unsigned char *)ptr;
	size_t i;
	
	i = 0;
	while (i < size)
	{
		printf("%02x", p[i]);
		i++;
	}
	printf("\n");
}
int main(void)
{
		size_t count = 10;
		size_t size = sizeof(char);

		char *my_ptr = (char *)ft_calloc(count, size);
		if(!my_ptr)
		{
			printf("ft_calloc failed\n");
			return 1;
		}
		printf("ft_calloc result:\n");
		print_memory(my_ptr, count);

		free(my_ptr);
		return 0;
}


//cc -Wall -Wextra -Werror -I../ -L../ -lft test_ft_calloc.c -o test_ft_calloc
