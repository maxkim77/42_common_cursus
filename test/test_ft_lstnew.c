#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	// 테스트용 문자열
	char *str = strdup("libft test");

	// 노드 생성
	t_list *node = ft_lstnew(str);

	if (node == NULL)
	{
		printf("❌ 노드 생성 실패\n");
		return (1);
	}

	// 결과 출력
	printf("✅ 노드 생성 성공\n");
	printf("content: %s\n", (char *)node->content);
	printf("next: %p\n", (void *)node->next);

	// 메모리 해제
	free(str);   // content는 strdup로 할당했으므로 직접 해제
	free(node);  // 구조체 자체 해제

	return 0;
}
