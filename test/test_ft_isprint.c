#include <stdio.h>
#include "libft.h"

int main(void)
{
    int test_values[] = {
        31,     // 제어 문자 (출력 불가)
        32,     // 공백 (출력 가능 시작)
        33,     // !
        48,     // 0
        65,     // A
        90,     // Z
        97,     // a
        122,    // z
        126,    // ~ (출력 가능 끝)
        127,    // DEL (출력 불가)
        -1,     // 음수 (출력 불가)
        200     // 범위 밖
    };

    int len = sizeof(test_values) / sizeof(test_values[0]);
    int i = 0;

    while (i < len)
    {
        int c = test_values[i];
        if (ft_isprint(c))
            printf("%d '%c': ✅ printable\n", c, c);
        else
            printf("%d: ❌ not printable\n", c);
        i++;
    }
    return 0;
}
