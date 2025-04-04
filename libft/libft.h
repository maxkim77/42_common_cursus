#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_list
{
	void		*content;
	struct s_list *next;
	t_list;
}

int ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
size_t ft_strlen(const char *s);

#endif