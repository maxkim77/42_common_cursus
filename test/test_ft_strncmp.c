#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print_result(const char *label, int ft_result, int std_result)
{
	if ((ft_result == 0 && std_result == 0) ||
		(ft_result < 0 && std_result < 0) ||
		(ft_result > 0 && std_result > 0))
	{
		printf("[OK] %s: ft=%d, std=%d\n", label, ft_result, std_result);
	}
	else
	{
		printf("[FAIL] %s: ft=%d, std=%d\n", label, ft_result, std_result);
	}
}

int	main(void)
{
	// Test 1: 동일한 문자열
	print_result("Equal strings", ft_strncmp("abc", "abc", 3), strncmp("abc", "abc", 3));

	// Test 2: 다름 (중간 문자)
	print_result("Different mid", ft_strncmp("abc", "adc", 3), strncmp("abc", "adc", 3));

	// Test 3: 다름 (첫 문자)
	print_result("Different first", ft_strncmp("zbc", "abc", 3), strncmp("zbc", "abc", 3));

	// Test 4: n < 실제 길이 (비교 중단)
	print_result("Partial compare", ft_strncmp("abcdef", "abcxyz", 3), strncmp("abcdef", "abcxyz", 3));

	// Test 5: n == 0 (비교 안 함)
	print_result("n = 0", ft_strncmp("abc", "def", 0), strncmp("abc", "def", 0));

	// Test 6: 문자열 길이 차이
	print_result("Length mismatch", ft_strncmp("abc", "abcd", 10), strncmp("abc", "abcd", 10));

	// Test 7: 공백 포함
	print_result("With space", ft_strncmp("abc", "ab ", 3), strncmp("abc", "ab ", 3));

	return 0;
}
