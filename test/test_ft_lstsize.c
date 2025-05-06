#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	// 노드 3개 생성
	t_list *node1 = ft_lstnew(strdup("one"));
	t_list *node2 = ft_lstnew(strdup("two"));
	t_list *node3 = ft_lstnew(strdup("three"));

	// 리스트에 노드 연결
	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);

	// 리스트 크기 측정
	int count = ft_lstsize(node1);

	// 결과 출력
	printf("✅ 리스트에 있는 노드 수: %d\n", count); // 기대값: 3

	// 메모리 해제
	t_list *tmp;
	while (node1)
	{
		tmp = node1->next;
		free(node1->content);
		free(node1);
		node1 = tmp;
	}

	return 0;
}
