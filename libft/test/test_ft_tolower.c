#include <stdio.h>
#include <ctype.h>    // 시스템 tolower()
#include "libft.h"    // 사용자 ft_tolower()

void	print_result(int input)
{
	int	ft_res = ft_tolower(input);
	int	std_res = tolower(input);

	if (ft_res == std_res)
		printf("[OK] input: '%c' (%d) → '%c' (%d)\n", input, input, ft_res, ft_res);
	else
		printf("[FAIL] input: '%c' (%d) → got '%c' (%d), expected '%c' (%d)\n",
			input, input, ft_res, ft_res, std_res, std_res);
}

int	main(void)
{
	// 대문자 테스트
	for (int c = 'A'; c <= 'Z'; c++)
		print_result(c);

	// 소문자 테스트 (변화 없어야 함)
	for (int c = 'a'; c <= 'z'; c++)
		print_result(c);

	// 숫자 및 특수문자 테스트
	print_result('1');
	print_result('!');
	print_result(' ');
	print_result('\n');
	print_result(0);

	// 음수 및 범위 밖 입력 테스트 (정의되지 않지만 처리 테스트용)
	print_result(-1);
	print_result(200);

	return 0;
}
//gcc -Wall -Wextra -Werror -I.. test_ft_tolower.c ../libc/ft_tolower.c -o test_ft_tolower
