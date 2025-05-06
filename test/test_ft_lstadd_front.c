#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

// 리스트 출력용 함수
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
	t_list *node1 = ft_lstnew("원래 마지막");
	t_list *node2 = ft_lstnew("중간");
	t_list *node3 = ft_lstnew("가장 앞");

	// 맨 앞에 노드 순서대로 추가
	ft_lstadd_front(&list, node1); // list -> node1
	ft_lstadd_front(&list, node2); // list -> node2 -> node1
	ft_lstadd_front(&list, node3); // list -> node3 -> node2 -> node1

	print_list(list);

	// 메모리 해제
	t_list *tmp;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return 0;
}
