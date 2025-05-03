#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"  // ft_split 함수 선언 포함되어야 함

void	print_result(char **result)
{
	int i = 0;
	while (result && result[i])
	{
		printf("[%d]: \"%s\"\n", i, result[i]);
		i++;
	}
	if (!result)
		printf("[NULL]\n");
	else
		printf("[END]\n\n");
}

void	free_split(char **split)
{
	int i = 0;
	if (!split)
		return;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	main(void)
{
	char **res;

	// 기본 테스트
	res = ft_split("hello world 42", ' ');
	printf("Test 1: \"hello world 42\", delim=' '\n");
	print_result(res);
	free_split(res);

	// 연속된 구분자
	res = ft_split("split::this:string", ':');
	printf("Test 2: \"split::this:string\", delim=':'\n");
	print_result(res);
	free_split(res);

	// 앞뒤 공백 포함
	res = ft_split("  a b c  ", ' ');
	printf("Test 3: \"  a b c  \", delim=' '\n");
	print_result(res);
	free_split(res);

	// 구분자만 있는 경우
	res = ft_split("::::", ':');
	printf("Test 4: \"::::\", delim=':'\n");
	print_result(res);
	free_split(res);

	// 빈 문자열
	res = ft_split("", ' ');
	printf("Test 5: \"\", delim=' '\n");
	print_result(res);
	free_split(res);

	// 단어 하나만
	res = ft_split("word", ' ');
	printf("Test 6: \"word\", delim=' '\n");
	print_result(res);
	free_split(res);

	// 문자열 전체가 구분자 한 글자
	res = ft_split(" ", ' ');
	printf("Test 7: \" \", delim=' '\n");
	print_result(res);
	free_split(res);

	return 0;
}
//gcc -Wall -Wextra -Werror -I.. test_ft_split.c ../add/ft_split.c -o test_ft_split
