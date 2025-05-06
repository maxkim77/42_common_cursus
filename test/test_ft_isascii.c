#include <stdio.h>
#include "libft.h"

int main(void)
{
    int test_values[] = {
        -1, 0, 1, 31, 32, 65, 90, 97, 122, 126, 127, 128, 255
    };
    int len = sizeof(test_values) / sizeof(test_values[0]);
    int i = 0;

    while (i < len)
    {
        int c = test_values[i];
        if (ft_isascii(c))
            printf("%d: ✅ is ASCII\n", c);
        else
            printf("%d: ❌ not ASCII\n", c);
        i++;
    }
    return 0;
}
