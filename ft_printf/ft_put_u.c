#include "ft_printf.h"

int ft_put_u(unsigned int nb)
{
	int count;
	count = 0;
	if (nb > 9)
	{
		count += ft_put_d_i(nb / 10);
		count += ft_put_d_i(nb % 10);
	}
	else if (nb >= 0 && nb < 10)
	{
		count += ft_put_c(nb + '0'); 
	}
	if (count < 0)
	{
		return (-1);
	}
	return (count);
}