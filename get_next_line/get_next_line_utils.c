/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2025/06/07 12:00:00 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*cpy;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	cpy = (char *)malloc(len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin(const char *left, const char *right)
{
	size_t	ll;
	size_t	rr;
	size_t	i;
	size_t	j;
	char	*out;

	ll = ft_strlen((char *)left);
	rr = ft_strlen((char *)right);
	out = (char *)malloc(ll + rr + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < ll)
	{
		out[i] = left[i];
		i++;
	}
	j = 0;
	while (j < rr)
	{
		out[i + j] = right[j];
		j++;
	}
	out[i + j] = '\0';
	return (out);
}
