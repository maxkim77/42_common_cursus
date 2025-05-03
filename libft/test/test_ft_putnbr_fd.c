#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

#define TEST_FILE "test_putnbr_fd_output.txt"

void run_test(int n, const char *expected)
{
	char buffer[64] = {0};

	// 파일 열기
	int fd = open(TEST_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		return;
	}

	ft_putnbr_fd(n, fd);
	close(fd);

	// 파일 읽기
	fd = open(TEST_FILE, O_RDONLY);
	if (fd < 0)
	{
		perror("reopen");
		return;
	}
	read(fd, buffer, sizeof(buffer) - 1);
	close(fd);

	// 비교
	if (strcmp(buffer, expected) == 0)
		printf("[OK] %d → \"%s\"\n", n, buffer);
	else
		printf("[FAIL] %d → got: \"%s\", expected: \"%s\"\n", n, buffer, expected);
}

int main(void)
{
	run_test(0, "0");
	run_test(12345, "12345");
	run_test(-987, "-987");
	run_test(2147483647, "2147483647");      // INT_MAX
	run_test(-2147483648, "-2147483648");    // INT_MIN

	unlink(TEST_FILE); // 테스트 후 파일 삭제
	return 0;
}
