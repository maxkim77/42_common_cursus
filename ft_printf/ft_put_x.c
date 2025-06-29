#include "ft_pritnf.h"

int ft_put_x(unsigned int nb, int type)
{
	char 	*alpha;

	if (type == 'x')
		alpha = "0123456789abcdef";
	else 
		alpha = "0123456789ABCDEF";
	
}

int 	ft_base16(unsigned long nb, char *alpha)
{
	int		count;
	
	count = 0;
	if (nb > 15)
	{
		count += ft_base16(nb/16, alpha);
	}
}