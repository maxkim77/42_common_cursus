#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	if (n == 0)
		return (count);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*ft_putnbr(long n, char *conversion, int count)
{
	int	position;

	position = count - 2;
	while (n > 0)
	{
		conversion[position] = (n % 10) + '0';
		n = n / 10;
		position--;
	}
	return (conversion);
}

char	*ft_itoa(int n)
{
	char	*conversion;
	int		count;
	long	nbr;

	nbr = n;
	count = ft_count(nbr);
	conversion = malloc(sizeof(char) * (count + 1));
	if (!conversion)
		return (NULL);

	if (nbr < 0)
	{
		conversion[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		conversion[0] = '0';
	else
		conversion = ft_putnbr(nbr, conversion, count);

	conversion[count - 1] = '\0';
	return (conversion);
}
