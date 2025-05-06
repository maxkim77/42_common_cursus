#include <stdio.h>
#include "libft.h"

int main(void)
{
    int test_values[] = {'0', '1', '5', '9', 'a', 'Z', ' ', '!', 47, 58, -1};
    int len = sizeof(test_values) / sizeof(test_values[0]);
    int i = 0;

    while (i < len)
    {
        int c = test_values[i];
        if (ft_isdigit(c))
            printf("'%c' (%d): ✅ is digit\n", c, c);
        else
            printf("'%c' (%d): ❌ not digit\n", c, c);
        i++;
    }
    return 0;
}
