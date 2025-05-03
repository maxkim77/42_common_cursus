#include <stdio.h>
#include "libft.h"

int main(void)
{
    // 테스트할 문자 배열
    int test_chars[] = {'A', 'z', '0', '9', '@', ' ', '\n', '5', 'b', '*'};
    int len = sizeof(test_chars) / sizeof(test_chars[0]);

    int i;

    i = 0;
    while(i < len)
    {
        int c = test_chars[i];
        if (ft_isalnum(c))
            printf("'%c' (%d) is alphanumeric.\n", c, c);
        else
            printf("'%c' (%d) is NOT alphanumeric.\n", c, c);
        i++;
    }
    return 0;
}
//gcc -Wall -Wextra -Werror -I.. -L.. -lft test_ft_isalnum.c -o test_ft_isalnum
