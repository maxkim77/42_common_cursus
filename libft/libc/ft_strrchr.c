#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	unsigned int i;
	char *res;
	char cc;

	cc = (char) c;
	res = NULL;
	i = 0;

	while (s[i])
	{
		if (s[i] == cc)
			res = (char *)&s[i];
		i++;
	}

	if (s[i] == cc)
		res = (char *)&s[i];

	return res;
}
