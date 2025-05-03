#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print_result(const char *label, const void *s, int c, size_t n)
{
	const unsigned char *result = ft_memchr(s, c, n);

	if (result)
		printf("%s → Found '%c' (%d) at offset %ld: \"%s\"\n",
			label, c, c, result - (unsigned char *)s, result);
	else
		printf("%s → Not found '%c' (%d) in first %zu bytes\n",
			label, c, c, n);
}

int	main(void)
{
	char str1[] = "abcdef";
	char str2[] = "123\0abc456";
	char str3[] = "xxxxxx";

	print_result("Test 1", str1, 'c', 6);        // → "cdef"
	print_result("Test 2", str1, 'z', 6);        // → Not found
	print_result("Test 3", str2, '\0', 8);       // → Found at offset 3
	print_result("Test 4", str2, 'a', 5);        // → Not found (a는 offset 4에 있지만 \0이 있어도 인식 가능)
	print_result("Test 5", str3, 'x', 3);        // → Found at offset 0
	print_result("Test 6", str3, 'x', 0);        // → Not found (길이 0이므로)

	return 0;
}
//gcc -Wall -Wextra -Werror -I.. -L.. -lft test_ft_memchr.c -o test_ft_memchr