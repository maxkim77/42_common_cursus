#include <fcntl.h>     // open
#include <unistd.h>    // close, write, read, unlink
#include <stdio.h>     // printf
#include <string.h>    // strcmp
#include "libft.h"     // ft_putchar_fd

#define TEST_FILE "test_putchar_fd_output.txt"

void	run_test(char input, const char *expected)
{
	char buffer[2] = {0};

	// 파일 열기 (쓰기 모드, 없으면 생성, 기존 내용 삭제)
	int fd = open(TEST_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return;
	}

	ft_putchar_fd(input, fd);
	close(fd);

	// 파일 다시 열기 (읽기 모드)
	fd = open(TEST_FILE, O_RDONLY);
	if (fd < 0)
	{
		perror("reopen");
		return;
	}
	read(fd, buffer, 1);
	close(fd);

	// 결과 출력
	if (strcmp(buffer, expected) == 0)
		printf("[OK] '%c' → '%s'\n", input, buffer);
	else
		printf("[FAIL] '%c' → got: '%s', expected: '%s'\n", input, buffer, expected);
}

int	main(void)
{
	run_test('A', "A");
	run_test('z', "z");
	run_test('0', "0");
	run_test('\n', "\n");

	// 테스트 파일 삭제
	unlink(TEST_FILE);

	return 0;
}
