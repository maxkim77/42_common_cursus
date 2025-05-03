#include <stdio.h>
#include "libft.h"

int main(void)
{
    int test_chars[] = {'A', 'Z', 'a', 'z', 'M', 'm', '0', '#', ' ', '\n'};
    int len = sizeof(test_chars) / sizeof(test_chars[0]);
    int i = 0;

    while (i < len)
    {
        int c = test_chars[i];
        if (ft_isalpha(c))
            printf("'%c' (%d): ✅ is alphabet\n", c, c);
        else
            printf("'%c' (%d): ❌ not alphabet\n", c, c);
        i++;
    }
    return 0;
}
