#include "libft.h"
#include <stdio.h>

void	test_case(const char *haystack, const char *needle, size_t len)
{
	char *result = ft_strnstr(haystack, needle, len);

	if (result != NULL)
		printf("✅ FOUND: haystack = \"%s\", needle = \"%s\", len = %zu -> \"%s\"\n",
			haystack, needle, len, result);
	else
		printf("❌ NOT FOUND: haystack = \"%s\", needle = \"%s\", len = %zu\n",
			haystack, needle, len);
}

int	main(void)
{
	// 기본적인 찾기
	test_case("Hello, world!", "world", 13);

	// len을 짧게 줘서 찾지 못하는 경우
	test_case("Hello, world!", "world", 5);

	// needle이 haystack 맨 앞에 있을 때
	test_case("abcde", "abc", 5);

	// needle이 haystack 중간에 있을 때
	test_case("abcde", "c", 5);

	// needle이 haystack에 없는 경우
	test_case("abcdefg", "hij", 7);

	// haystack과 needle이 완전히 같은 경우
	test_case("abcdef", "abcdef", 6);

	// 빈 needle 테스트 (무조건 haystack 반환)
	test_case("abcdef", "", 6);

	// len == 0 인 경우 (needle이 ""가 아니면 무조건 NULL)
	test_case("abcdef", "abc", 0);

	// len이 haystack보다 큰 경우
	test_case("short", "short", 100);

	// haystack이 빈 문자열일 때
	test_case("", "", 5);
	test_case("", "abc", 5);

	return (0);
}
