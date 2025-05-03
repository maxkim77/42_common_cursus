#include <stdio.h>
#include <string.h>
#include "libft.h"
#include <string.h>

size_t	local_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	if (!dst || !src)
		return 0;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return strlen(src);
}
void	print_result(const char *label, char *ft_dst, char *lib_dst, size_t ft_ret, size_t lib_ret)
{
	if (ft_ret == lib_ret && strcmp(ft_dst, lib_dst) == 0)
		printf("[OK] %s: ret=%zu, dst='%s'\n", label, ft_ret, ft_dst);
	else
		printf("[FAIL] %s:\n  ret=%zu (expected %zu)\n  dst='%s' (expected '%s')\n",
			label, ft_ret, lib_ret, ft_dst, lib_dst);
}

int	main(void)
{
	char	buf1[20];
	char	buf2[20];
	size_t	ret1, ret2;

	// Test 1: 충분한 공간
	ret1 = ft_strlcpy(buf1, "Hello", sizeof(buf1));
	ret2 = local_strlcpy(buf2, "Hello", sizeof(buf2));
	print_result("Copy 'Hello' with enough space", buf1, buf2, ret1, ret2);

	// Test 2: 공간이 딱 맞거나 부족
	ret1 = ft_strlcpy(buf1, "HelloWorld", 6);
	ret2 = local_strlcpy(buf2, "HelloWorld", 6);
	print_result("Copy 'HelloWorld' with size 6", buf1, buf2, ret1, ret2);

	// Test 3: dstsize = 0
	ret1 = ft_strlcpy(buf1, "HelloWorld", 0);
	ret2 = local_strlcpy(buf2, "HelloWorld", 0);
	print_result("Copy with dstsize = 0", buf1, buf2, ret1, ret2);

	// Test 4: 빈 문자열 복사
	ret1 = ft_strlcpy(buf1, "", sizeof(buf1));
	ret2 = local_strlcpy(buf2, "", sizeof(buf2));
	print_result("Copy empty string", buf1, buf2, ret1, ret2);

	return 0;
}

//gcc -Wall -Wextra -Werror -I.. test_ft_strlcpy.c ../libc/ft_strlcpy.c ../libc/ft_strlen.c ../libc/ft_memcpy.c -o test_ft_strlcpy
