#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print_result(const char *label, char *result, char *expected)
{
	if (result == NULL && expected == NULL)
		printf("[OK] %s: NULL returned as expected\n", label);
	else if (result != NULL && expected != NULL && strcmp(result, expected) == 0)
		printf("[OK] %s: '%s'\n", label, result);
	else
		printf("[FAIL] %s: got '%s', expected '%s'\n",
			   label,
			   result ? result : "NULL",
			   expected ? expected : "NULL");
}

int	main(void)
{
	const char	*str = "libft is fun!";

	// Test 1: 문자 'f' 찾기
	print_result("Find 'f'", ft_strchr(str, 'f'), strchr(str, 'f'));

	// Test 2: 첫 문자 'l' 찾기
	print_result("Find 'l'", ft_strchr(str, 'l'), strchr(str, 'l'));

	// Test 3: 마지막 문자 '!' 찾기
	print_result("Find '!'", ft_strchr(str, '!'), strchr(str, '!'));

	// Test 4: 널 문자 '\0' 찾기 (끝 위치)
	print_result("Find '\\0'", ft_strchr(str, '\0'), strchr(str, '\0'));

	// Test 5: 없는 문자 'z' 찾기
	print_result("Find 'z' (not present)", ft_strchr(str, 'z'), strchr(str, 'z'));

	return 0;
}
