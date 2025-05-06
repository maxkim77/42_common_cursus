#include <stdio.h>
#include <stdlib.h>  // for system itoa (if needed)
#include "libft.h"   // ft_itoa()

void print_result(const char *label, int n, const char *result, const char *expected)
{
	if (result && expected && strcmp(result, expected) == 0)
		printf("[OK] %s (%d) → \"%s\"\n", label, n, result);
	else
		printf("[FAIL] %s (%d): got \"%s\", expected \"%s\"\n", label, n, result ? result : "NULL", expected ? expected : "NULL");
}

int main(void)
{
	char *res;

	res = ft_itoa(0);
	print_result("Zero", 0, res, "0");
	free(res);

	res = ft_itoa(123);
	print_result("Positive", 123, res, "123");
	free(res);

	res = ft_itoa(-123);
	print_result("Negative", -123, res, "-123");
	free(res);

	res = ft_itoa(2147483647);
	print_result("INT_MAX", 2147483647, res, "2147483647");
	free(res);

	res = ft_itoa(-2147483648);
	print_result("INT_MIN", -2147483648, res, "-2147483648");
	free(res);

	return 0;
}
//gcc -Wall -Wextra -Werror -I.. test_ft_itoa.c ../add/ft_itoa.c -o test_ft_itoa
