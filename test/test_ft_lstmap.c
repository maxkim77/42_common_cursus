#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// content를 strdup 후 대문자로 변환
void *duplicate_uppercase(void *content)
{
	char *str = (char *)content;
	char *copy = strdup(str);
	if (!copy)
		return (NULL);
	for (int i = 0; copy[i]; i++)
		copy[i] = toupper(copy[i]);
	return (copy);
}

// content를 free하는 del 함수
void del_content(void *content)
{
	free(content);
}

// 리스트 출력 함수
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
	// 원본 리스트 생성
	t_list *old_list = ft_lstnew(strdup("hello"));
	ft_lstadd_back(&old_list, ft_lstnew(strdup("world")));
	ft_lstadd_back(&old_list, ft_lstnew(strdup("libft")));

	printf("✅ 원본 리스트:\n");
	print_list(old_list);

	// ft_lstmap 실행
	t_list *new_list = ft_lstmap(old_list, duplicate_uppercase, del_content);

	printf("\n🔄 변환된 새 리스트:\n");
	print_list(new_list);

	// 메모리 해제
	ft_lstclear(&old_list, del_content);
	ft_lstclear(&new_list, del_content);
	return 0;
}
