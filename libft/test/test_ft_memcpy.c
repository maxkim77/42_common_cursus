#include <stdio.h>
#include <string.h>
#include "libft.h"

void print_buffer(const char *label, const char *buffer, size_t len)
{
	printf("%s: \"", label);
	for (size_t i = 0; i < len; i++)
	{
		if (buffer[i] >= 32 && buffer[i] <= 126)
			printf("%c", buffer[i]);
		else
			printf("\\x%02x", (unsigned char)buffer[i]);
	}
	printf("\"\n");
}

int	main(void)
{
	char src[] = "LibftMemcpy";
	char dest1[20];
	char dest2[20];

	// memset으로 미리 초기화
	memset(dest1, '_', sizeof(dest1));
	memset(dest2, '_', sizeof(dest2));

	// memcpy 사용
	ft_memcpy(dest1, src, 6);  // "Libft"
	memcpy(dest2, src, 6);     // 표준 함수

	print_buffer("ft_memcpy result", dest1, 12);
	print_buffer("std memcpy result", dest2, 12);

	// NULL 방지 처리 테스트
	printf("\nNULL test: %s\n",
		ft_memcpy(NULL, NULL, 0) == NULL ? "✅ Passed" : "❌ Failed");

	return 0;
}
