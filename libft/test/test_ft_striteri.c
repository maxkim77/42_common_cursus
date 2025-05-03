#include <stdio.h>
#include <string.h>
#include "libft.h"

// 예시 함수: 알파벳 소문자를 대문자로 변환
void	to_upper(unsigned int i, char *c)
{
	(void)i;  // 인덱스 안 쓸 때는 이렇게 명시적으로 무시
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

// 또 다른 예시 함수: 인덱스가 짝수인 문자만 대문자로
void	upper_even_index(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	char str1[] = "hello42world";
	char str2[] = "libc_function";

	printf("Original: %s\n", str1);
	ft_striteri(str1, to_upper);
	printf("All upper: %s\n\n", str1);

	printf("Original: %s\n", str2);
	ft_striteri(str2, upper_even_index);
	printf("Even index upper: %s\n", str2);

	return 0;
}
