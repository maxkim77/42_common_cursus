#include <fcntl.h>     // open
#include <unistd.h>    // close, read, write, unlink
#include <stdio.h>     // printf
#include <string.h>    // strcmp
#include "libft.h"     // ft_putendl_fd

#define TEST_FILE "test_putendl_fd_output.txt"

void	run_test(const char *input, const char *expected)
{
	char buffer[1024] = {0};

	// 파일 생성 및 열기
	int fd = open(TEST_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return;
	}

	ft_putendl_fd((char *)input, fd);
	close(fd);

	// 파일 다시 열기 (읽기)
	fd = open(TEST_FILE, O_RDONLY);
	if (fd < 0)
	{
		perror("reopen");
		return;
	}
	read(fd, buffer, sizeof(buffer) - 1);
	close(fd);

	// 결과 확인
	if (strcmp(buffer, expected) == 0)
		printf("[OK] \"%s\" → \"%s\"\n", input, buffer);
	else
		printf("[FAIL] \"%s\" → got: \"%s\", expected: \"%s\"\n", input, buffer, expected);
}

int	main(void)
{
	run_test("hello", "hello\n");
	run_test("42Seoul", "42Seoul\n");
	run_test("", "\n");
	run_test("test with space", "test with space\n");

	unlink(TEST_FILE); // 테스트 파일 삭제
	return 0;
}
