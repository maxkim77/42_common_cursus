#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print_result(const char *label, const char *result, const char *expected)
{
	if (strcmp(result, expected) == 0)
		printf("[OK] %s: %s\n", label, result);
	else
		printf("[FAIL] %s: got '%s', expected '%s'\n", label, result, expected);
}

int	main(void)
{
	char	buffer1[50] = "Hello, World!";
	char	buffer2[50] = "Hello, World!";

	// Test 1: Non-overlapping copy
	ft_memmove(buffer1 + 7, buffer1, 5); // Copy "Hello" to position 7
	memmove(buffer2 + 7, buffer2, 5);    // Expected result
	print_result("Non-overlapping", buffer1, buffer2);

	// Test 2: Overlapping (dst > src)
	char	buf3[] = "1234567890";
	char	buf4[] = "1234567890";
	ft_memmove(buf3 + 2, buf3, 8);
	memmove(buf4 + 2, buf4, 8);
	print_result("Overlap dst > src", buf3, buf4);

	// Test 3: Overlapping (dst < src)
	char	buf5[] = "abcdefghij";
	char	buf6[] = "abcdefghij";
	ft_memmove(buf5, buf5 + 2, 8);
	memmove(buf6, buf6 + 2, 8);
	print_result("Overlap dst < src", buf5, buf6);

	// Test 4: NULL pointer check
	if (ft_memmove(NULL, NULL, 5) == NULL)
		printf("[OK] NULL input handled properly\n");
	else
		printf("[FAIL] NULL input not handled properly\n");

	return 0;
}
