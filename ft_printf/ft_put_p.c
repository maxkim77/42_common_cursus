#include "ft_printf.h"

int	ft_put_p(void *arg)
{
	int 	count;
	char 		*alpha;
	unsigned long 	arg2;

	arg2 = (unsigned long) arg;
	alpha = "0123456789abcdef";
	count = 0;
	count += ft_put_s("0x");
	count += ft_base16(arg2, alpha);
	return (count);
}