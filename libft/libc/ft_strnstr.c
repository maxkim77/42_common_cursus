#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t j;

    if (*needle == '\0')
        return ((char *)haystack);
    for (i = 0; haystack[i] != '\0' && i < len; i++)
    {
        if (haystack[i] == needle[0])
        {
            for (j = 0; needle[j] != '\0' && haystack[i + j] == needle[j] && (i + j) < len; j++)
                ;
            if (needle[j] == '\0')
                return ((char *)(haystack + i));
        }
    }
    return (NULL);
}