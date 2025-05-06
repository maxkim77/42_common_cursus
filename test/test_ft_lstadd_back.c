#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// 헬퍼 함수: 리스트 전체 출력
void print_list(t_list *lst)
{
	int i = 0;
	while (lst)
	{
		printf("Node %d: %s\n", i++, (char *)lst->content);
		lst = lst->next;
	}
}

int main(void)
{
	t_list *list = NULL;
	t_list *node1 = ft_lstnew("첫 번째");
	t_list *node2 = ft_lstnew("두 번째");
	t_list *node3 = ft_lstnew("세 번째");

	// 리스트에 노드 추가
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	// 리스트 출력
	print_list(list);

	// 메모리 해제 (옵션)
	t_list *tmp;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return 0;
}
//gcc -Wall -Wextra -Werror -I.. test_ft_lstadd_back.c ../libft.a -o test_lstadd_back
