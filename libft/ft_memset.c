#include "libft.h"

void *ft_memset(void *b, int c, size_t len)
{
	unsigned char *tmp_mem;
	tmp_mem = (unsigned) b;
	while (len > 0)
	{
		*(tmp_mem++) = (unsigned char) c;
		len--;
	}
	return (b);
}