#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalnum(c) || ft_isdigit(c))
		return (c);
	return (0);
}