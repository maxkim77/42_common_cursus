/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 12:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2025/06/07 12:00:00 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*find_nl(char *s)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (&s[i]);
		i++;
	}
	return (NULL);
}

static char	*append_reads(int fd, char *stash)
{
	ssize_t	br;
	char	*buf;
	char	*tmp;

	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	br = 1;
	while (!find_nl(stash) && br > 0)
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br < 0)
			return (free(buf), free(stash), NULL);
		buf[br] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	return (stash);
}

static char	*cut_and_keep(char *line, char **stash_ref)
{
	char	*nlp;
	char	*rest;

	nlp = find_nl(line);
	if (!nlp || *(nlp + 1) == '\0')
	{
		*stash_ref = NULL;
		return (line);
	}
	rest = ft_strdup(nlp + 1);
	if (!rest)
	{
		free(line);
		*stash_ref = NULL;
		return (NULL);
	}
	*(nlp + 1) = '\0';
	*stash_ref = rest;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	line = append_reads(fd, stash);
	if (!line)
	{
		stash = NULL;
		return (NULL);
	}
	if (line[0] == '\0')
	{
		free(line);
		stash = NULL;
		return (NULL);
	}
	return (cut_and_keep(line, &stash));
}
