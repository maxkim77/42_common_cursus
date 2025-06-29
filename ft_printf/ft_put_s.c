#include "ft_printf.h"

int ft_put_s(char *str)
{
	int count;

	count = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	if (count < 0)
		return (-1);
	return (count);
}