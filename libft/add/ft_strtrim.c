#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char *tab;
	int		i;
	int		j;
	int		k;

	i = ft_startinit(0, s1, set);
	j = ft_endinit(ft_strlen(s1) - 1, s1, set);
	k = 0;
	if (i >= ft_strlen1(s1))
		return (ft_strdup(""));
	tab = malloc(sizeof(char) * ((j - i) + 2));
	if (!tab || !s1)
		return (NULL);
	while (i <= j)
	{
		tab[k] = s1[i];
		k++;
		i++;
	}
	tab[k] = '\0';
	return (tab);
}
