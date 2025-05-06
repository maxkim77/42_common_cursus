#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print_result(const char *label, const char *result, const char *expected, size_t len)
{
	if (memcmp(result, expected, len) == 0)
		printf("[OK] %s\n", label);
	else
		printf("[FAIL] %s: got '%.10s', expected '%.10s'\n", label, result, expected);
}

int	main(void)
{
	char	buffer1[20];
	char	buffer2[20];

	// Test 1: Fill all with 'A'
	memset(buffer2, 0, sizeof(buffer2));
	ft_memset(buffer1, 0, sizeof(buffer1));
	ft_memset(buffer1, 'A', 10);
	memset(buffer2, 'A', 10);
	print_result("Fill with 'A'", buffer1, buffer2, 20);

	// Test 2: Fill with zero
	ft_memset(buffer1, 0, 20);
	memset(buffer2, 0, 20);
	print_result("Fill with 0", buffer1, buffer2, 20);

	// Test 3: Fill middle of buffer
	strcpy(buffer1, "1234567890");
	strcpy(buffer2, "1234567890");
	ft_memset(buffer1 + 3, '*', 4);
	memset(buffer2 + 3, '*', 4);
	print_result("Fill middle with '*'", buffer1, buffer2, 10);

	// Test 4: Return value check
	char *ret = ft_memset(buffer1, '#', 5);
	if (ret == buffer1)
		printf("[OK] Return value matches input pointer\n");
	else
		printf("[FAIL] Return value does not match input pointer\n");

	return 0;
}
