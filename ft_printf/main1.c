#include "ft_printf.h"

int main(void)
{
	int len;

	len = ft_printf("정수(d): %d\n", -12345);
	ft_printf("출력길이 : %d\n", len);

	return (0);
}
