#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print_result(const char *label, size_t ft_result, size_t std_result)
{
	if (ft_result == std_result)
		printf("[OK] %s: len=%zu\n", label, ft_result);
	else
		printf("[FAIL] %s: got %zu, expected %zu\n", label, ft_result, std_result);
}

int	main(void)
{
	// Test 1: 일반 문자열
	print_result("Normal string", ft_strlen("Hello"), strlen("Hello"));

	// Test 2: 빈 문자열
	print_result("Empty string", ft_strlen(""), strlen(""));

	// Test 3: 공백 포함
	print_result("Whitespace", ft_strlen(" "), strlen(" "));

	// Test 4: 여러 줄 문자열
	print_result("Multiline", ft_strlen("abc\ndef"), strlen("abc\ndef"));

	// Test 5: 특수문자 포함
	print_result("Special chars", ft_strlen("@#$%^&*()"), strlen("@#$%^&*()"));

	// Test 6: 긴 문자열
	print_result("Long string", ft_strlen("123456789012345678901234567890"), strlen("123456789012345678901234567890"));

	return 0;
}
