#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// 문자열을 대문자로 바꾸는 함수
void	to_uppercase(void *content)
{
	char *str = (char *)content;
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

// 리스트 출력 함수
void	print_list(t_list *lst)
{
	int i = 0;
	while (lst)
	{
		printf("Node %d: %s\n", i++, (char *)lst->content);
		lst = lst->next;
	}
}

int	main(void)
{
	t_list *list = NULL;
	t_list *node1 = ft_lstnew(strdup("hello"));
	t_list *node2 = ft_lstnew(strdup("world"));
	t_list *node3 = ft_lstnew(strdup("libft"));

	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);

	printf("Before ft_lstiter:\n");
	print_list(list);

	// 대문자로 바꾸기
	ft_lstiter(list, to_uppercase);

	printf("\nAfter ft_lstiter:\n");
	print_list(list);

	// 메모리 해제
	t_list *tmp;
	while (list)
	{
		tmp = list->next;
		free(list->content);
		free(list);
		list = tmp;
	}
	return 0;
}
