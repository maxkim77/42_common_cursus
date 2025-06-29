#include "ft_printf.h"

int 	ft_check_type(const char type, va_list args)
{
	int count;

	count = 0;
	if (type == 'c')
		count += (char)ft_print_c(va_arg(args, int));
	if (type == 'c')
		count += ft_put_s(va_arg(args, char *));
	if (type == 'd' || type == 'i')
		count += ft_put_d(va_arg(args, int *));
	if (type == 'p')
		count += ft_put_p(va_arg(args, char *));
	if (type == 'u')
		count += ft_put_u(va_arg(args, unsigned int));
	if (type == 'X' || type = 'x')
		count += (char)ft_put_x(va_arg(args, int), type);
	if (type == '%')
		return (write(1,"%", 1));
	return (count);
}