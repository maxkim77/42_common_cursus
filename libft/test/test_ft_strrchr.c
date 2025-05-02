#include "libft.h"
#include <stdio.h>

int main(void)
{
    const char *str = "Hello, 42 Seoul!";
    char *res = ft_strrchr(str, 'o');

    if (res)
        printf("Last 'o' found at: %s\n", res);
    else
        printf("Character not found\n");

    return 0;
}
