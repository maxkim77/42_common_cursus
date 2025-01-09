
#include "libft.h"

int    ft_atoi(const char *str)
{
    int    result;
    int    sign;
    int    i;
    
    result = 0;
    sign = 1;
    i = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] <= 32)
        i++;

    if (str[i] == '+' && str[i + 1] != '-')
        i++;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }

    while (str[i] && str[i] >= 48 && str[i] <= 57)
    {
    	result *= 10;
		result += str[i] - 48;
		i++;
	    result *= sign;
    	return (result);
	}
}