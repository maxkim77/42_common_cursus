#include "libft.h"

char *strnstr(const char *big, const char *little, size_t len)
{
	size_t i = 0;
	size_t j;

	if (little[0] == '\0')
		return (char *) big;
	
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] != '\0' && big[i + j] == little[j] && i + j < len)
		{
			j++;
		}
		if (little[j] == '\0')
		{
			return (char *)(big + i);
		}
		i++;
	}
	return NULL;
}