#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h" // ft_strjoin 선언 포함되어야 함

void	run_test(const char *s1, const char *s2, const char *expected)
{
	char *result = ft_strjoin(s1, s2);

	if (!result)
	{
		printf("[FAIL] \"%s\" + \"%s\" → NULL (malloc 실패)\n", s1, s2);
		return;
	}

	if (strcmp(result, expected) == 0)
		printf("[OK]   \"%s\" + \"%s\" → \"%s\"\n", s1, s2, result);
	else
		printf("[FAIL] \"%s\" + \"%s\" → \"%s\" (expected: \"%s\")\n", s1, s2, result, expected);

	free(result);
}

int	main(void)
{
	run_test("hello", "world", "helloworld");
	run_test("", "abc", "abc");
	run_test("abc", "", "abc");
	run_test("", "", "");
	run_test("42", "Seoul", "42Seoul");

	return 0;
}


//gcc -Wall -Wextra -Werror -I.. test_ft_strjoin.c ../add/ft_strjoin.c ../libc/ft_strlen.c -o test_ft_strjoin
