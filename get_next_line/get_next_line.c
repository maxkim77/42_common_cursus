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

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer);
static char	*_set_line(char *line);
static char	*ft_strchr(char *s, int c);

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !buffer || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		return (NULL);
	}
	line = _fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	left_c = _set_line(line);
	return (line);
}

static char	*_set_line(char *line_buffer)
{
	char	*left_c;
	size_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0' || line_buffer[i + 1] == '\0')
		return (0);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_c == '\0')
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (left_c);
}

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t		b_read;
	char		*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (0);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}