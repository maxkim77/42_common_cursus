#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print_result(const char *label, char *ft_dst, char *lib_dst, size_t ft_ret, size_t lib_ret)
{
	if (ft_ret == lib_ret && strcmp(ft_dst, lib_dst) == 0)
		printf("[OK] %s: ret=%zu, result='%s'\n", label, ft_ret, ft_dst);
	else
		printf("[FAIL] %s:\n  ret=%zu (expected %zu)\n  result='%s' (expected '%s')\n",
			label, ft_ret, lib_ret, ft_dst, lib_dst);
}

int	main(void)
{
	char	buf1[30];
	char	buf2[30];
	size_t	ret1, ret2;

	// Test 1: Enough space to append full string
	strcpy(buf1, "Hello, ");
	strcpy(buf2, "Hello, ");
	ret1 = ft_strlcat(buf1, "World!", 30);
	ret2 = strlcat(buf2, "World!", 30);
	print_result("Append fits", buf1, buf2, ret1, ret2);

	// Test 2: Not enough space to append all
	strcpy(buf1, "Hello, ");
	strcpy(buf2, "Hello, ");
	ret1 = ft_strlcat(buf1, "ThisIsTooLong", 10);
	ret2 = strlcat(buf2, "ThisIsTooLong", 10);
	print_result("Append cut-off", buf1, buf2, ret1, ret2);

	// Test 3: dst_size smaller than dst length
	strcpy(buf1, "TooLongForDst");
	strcpy(buf2, "TooLongForDst");
	ret1 = ft_strlcat(buf1, "abc", 5);
	ret2 = strlcat(buf2, "abc", 5);
	print_result("dst_size < dst_len", buf1, buf2, ret1, ret2);

	// Test 4: dst_size == 0
	strcpy(buf1, "");
	strcpy(buf2, "");
	ret1 = ft_strlcat(buf1, "abc", 0);
	ret2 = strlcat(buf2, "abc", 0);
	print_result("dst_size = 0", buf1, buf2, ret1, ret2);

	return 0;
}
