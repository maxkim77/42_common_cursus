#include <stdio.h>
#include <string.h>
#include "libft.h"

// 표준 함수 대체용: 비교 대상 함수 정의
char *local_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i = 0, j;

	if (!*needle)
		return (char *)haystack;

	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] &&
				   haystack[i + j] == needle[j] &&
				   (i + j) < len)
				j++;
			if (!needle[j])
				return (char *)(haystack + i);
		}
		i++;
	}
	return NULL;
}

// 결과 출력 함수
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
	const char *haystack = "abcdefg";

	print_result("Basic match", ft_strnstr(haystack, "cde", 7), local_strnstr(haystack, "cde", 7));
	print_result("Exact range match", ft_strnstr(haystack, "cde", 5), local_strnstr(haystack, "cde", 5));
	print_result("Too short range", ft_strnstr(haystack, "cde", 3), local_strnstr(haystack, "cde", 3));
	print_result("Needle not in haystack", ft_strnstr(haystack, "xyz", 7), local_strnstr(haystack, "xyz", 7));
	print_result("Empty needle", ft_strnstr(haystack, "", 7), local_strnstr(haystack, "", 7));
	print_result("Empty haystack", ft_strnstr("", "a", 1), local_strnstr("", "a", 1));
	print_result("Zero len", ft_strnstr(haystack, "abc", 0), local_strnstr(haystack, "abc", 0));

	return 0;
}
//gcc -Wall -Wextra -Werror -I.. test_ft_strnstr.c ../libc/ft_strnstr.c -o test_ft_strnstr
