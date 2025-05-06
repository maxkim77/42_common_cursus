#include <stdio.h>
#include <ctype.h>    // 시스템 toupper()
#include "libft.h"    // 사용자 ft_toupper()

void	print_result(int input)
{
	int	ft_res = ft_toupper(input);
	int	std_res = toupper(input);

	if (ft_res == std_res)
		printf("[OK] input: '%c' (%d) → '%c' (%d)\n", input, input, ft_res, ft_res);
	else
		printf("[FAIL] input: '%c' (%d) → got '%c' (%d), expected '%c' (%d)\n",
			input, input, ft_res, ft_res, std_res, std_res);
}

int	main(void)
{
	// 소문자 테스트
	for (int c = 'a'; c <= 'z'; c++)
		print_result(c);

	// 대문자 테스트 (변화 없어야 함)
	for (int c = 'A'; c <= 'Z'; c++)
		print_result(c);

	// 숫자 및 특수문자 테스트
	print_result('1');
	print_result('!');
	print_result(' ');
	print_result('\n');
	print_result(0);

	// 범위 밖 테스트
	print_result(-1);
	print_result(200);

	return 0;
}
//gcc -Wall -Wextra -Werror -I.. test_ft_toupper.c ../libc/ft_toupper.c -o test_ft_toupper
