#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print_result(const char *label, const char *ft_res, const char *std_res)
{
	if ((ft_res == NULL && std_res == NULL) ||
		(ft_res && std_res && strcmp(ft_res, std_res) == 0))
	{
		printf("[OK] %s: '%s'\n", label, ft_res ? ft_res : "NULL");
	}
	else
	{
		printf("[FAIL] %s:\n  got     = '%s'\n  expected = '%s'\n",
			label,
			ft_res ? ft_res : "NULL",
			std_res ? std_res : "NULL");
	}
}

int	main(void)
{
	const char *text = "abcabc";

	print_result("Find 'a'", ft_strrchr(text, 'a'), strrchr(text, 'a'));       // → 마지막 'a'
	print_result("Find 'b'", ft_strrchr(text, 'b'), strrchr(text, 'b'));       // → 마지막 'b'
	print_result("Find 'c'", ft_strrchr(text, 'c'), strrchr(text, 'c'));       // → 마지막 'c'
	print_result("Find 'x'", ft_strrchr(text, 'x'), strrchr(text, 'x'));       // → 없음 → NULL
	print_result("Find '\\0'", ft_strrchr(text, '\0'), strrchr(text, '\0'));   // → 문자열 끝

	const char *only_one = "a";
	print_result("Single char - match", ft_strrchr(only_one, 'a'), strrchr(only_one, 'a')); // match
	print_result("Single char - miss", ft_strrchr(only_one, 'b'), strrchr(only_one, 'b')); // NULL

	return 0;
}
// % gcc -Wall -Wextra -Werror -I.. test_ft_strrchr.c ../libc/ft_strrchr.c -o test_ft_strrchr

