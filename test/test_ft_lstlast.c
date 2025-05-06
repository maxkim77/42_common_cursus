#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list *node1 = ft_lstnew("first");
	t_list *node2 = ft_lstnew("second");
	t_list *node3 = ft_lstnew("third");

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);

	t_list *last = ft_lstlast(node1);
	if (last)
		printf("마지막 노드의 content: %s\n", (char *)last->content);
	else
		printf("리스트가 비어 있습니다.\n");

	// 메모리 해제
	free(node1);
	free(node2);
	free(node3);
	return 0;
}
//gcc -Wall -Wextra -Werror -I.. test_ft_lstlast.c ../libft.a -o test_lstlast
//./test_lstlast
