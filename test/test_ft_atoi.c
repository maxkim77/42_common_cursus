#include <stdio.h>
#include "libft.h"

int main(void)
{
    const char *test_cases[] = {
        "42",
        "   123",
        "\t\n\v\f\r 456",
        "+789",
        "-987",
        "000123",
        "-000123",
        "  +00100",
        "abc123",
        "123abc",
        "",
        "   ",
        "-",
        "+",
        "2147483647",
        "-2147483648"
    };

    int i = 0;
    int len = sizeof(test_cases) / sizeof(test_cases[0]);

    while (i < len)
    {
        const char *str = test_cases[i];
        int result = ft_atoi(str);
        printf("Input: \"%s\" → Output: %d\n", str, result);
        i++;
    }
    return 0;
}
//gcc -Wall -Wextra -Werror -I.. -L.. -lft test_ft_atoi.c -o test_ft_atoi
