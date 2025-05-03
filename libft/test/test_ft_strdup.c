#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	print_result(const char *label, const char *src, const char *dst)
{
	if (dst == NULL)
	{
		printf("[FAIL] %s: NULL returned\n", label);
		return;
	}

	if (strcmp(src, dst) == 0 && src != dst)
		printf("[OK] %s: '%s'\n", label, dst);
	else if (strcmp(src, dst) != 0)
		printf("[FAIL] %s: copied value mismatch (got '%s', expected '%s')\n", label, dst, src);
	else if (src == dst)
		printf("[FAIL] %s: memory not duplicated (same pointer)\n", label);
}

int	main(void)
{
	char *s1 = "Hello, 42!";
	char *s2 = "";
	char *s3 = "Just a longer test string to check malloc size.";

	// Test 1
	char *copy1 = ft_strdup(s1);
	print_result("Basic string", s1, copy1);
	free(copy1);

	// Test 2
	char *copy2 = ft_strdup(s2);
	print_result("Empty string", s2, copy2);
	free(copy2);

	// Test 3
	char *copy3 = ft_strdup(s3);
	print_result("Long string", s3, copy3);
	free(copy3);

	// Test 4: NULL-safe (undefined behavior but testable)
	// ft_strdup(NULL); // Uncommenting this would be unsafe (undefined behavior)

	return 0;
}
//gcc -Wall -Wextra -Werror -I.. test_ft_strdup.c ../libc/ft_strdup.c ../libc/ft_strlen.c -o test_ft_strdup
//valgrind --leak-check=full ./test_ft_strdup
