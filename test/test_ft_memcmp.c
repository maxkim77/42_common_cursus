#include <stdio.h>
#include <string.h>
#include "libft.h"

void print_result(const char *label, const void *s1, const void *s2, size_t n)
{
	int result = ft_memcmp(s1, s2, n);
	if (result == 0)
		printf("%s → ✅ Equal (memcmp = 0)\n", label);
	else if (result > 0)
		printf("%s → 🔺 s1 > s2 (memcmp = %d)\n", label, result);
	else
		printf("%s → 🔻 s1 < s2 (memcmp = %d)\n", label, result);
}

int	main(void)
{
	char a1[] = "abcdef";
	char a2[] = "abcdef";
	char b1[] = "abcdeF"; // 다른 문자
	char b2[] = "abcdeg";
	char c1[] = "abc";
	char c2[] = "abc\0xxx"; // 널 이후 바이트 차이
	char d1[] = "abc";
	char d2[] = "abd";

	print_result("Test 1", a1, a2, 6);  // ✅ 같음
	print_result("Test 2", a1, b1, 6);  // 🔻
	print_result("Test 3", a1, b2, 6);  // 🔺
	print_result("Test 4", c1, c2, 4);  // ✅ null 포함해도 같음
	print_result("Test 5", d1, d2, 3);  // 🔻

	return 0;
}
