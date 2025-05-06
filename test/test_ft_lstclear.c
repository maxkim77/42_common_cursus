#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// del 함수: 문자열 포인터를 free
void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*head;
	t_list	*node1;

	// malloc으로 content 할당
	char *str1 = malloc(6);
	char *str2 = malloc(6);
	if (!str1 || !str2)
		return (1);
	
	// content에 값 넣기
	ft_memcpy(str1, "Hello", 6);
	ft_memcpy(str2, "World", 6);

	// 노드 생성
	head = ft_lstnew(str1);
	node1 = ft_lstnew(str2);
	head->next = node1;

	// 연결 상태 확인
	printf("Before clear:\n");
	t_list *tmp = head;
	while (tmp)
	{
		printf("  node content = %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}

	// 리스트 삭제
	ft_lstclear(&head, del_content);

	// 결과 확인
	if (head == NULL)
		printf("After clear: ✅ head is NULL (list cleared)\n");
	else
		printf("After clear: ❌ head is NOT NULL\n");

	return 0;
}
