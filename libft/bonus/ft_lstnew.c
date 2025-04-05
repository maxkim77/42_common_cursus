#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *data;

	data = malloc(sizeof(t_list));
	if (!data)
		return (NULL);
	data->content = content;
	data->next = NULL;
	return (data);
}