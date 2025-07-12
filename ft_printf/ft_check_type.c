/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2025/07/12 14:00:00 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(const char type, va_list args)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_put_c(va_arg(args, int));
	else if (type == 's')
		count += ft_put_s(va_arg(args, char *));
	else if (type == 'd' || type == 'i')
		count += ft_put_d_i(va_arg(args, int));
	else if (type == 'p')
		count += ft_put_p(va_arg(args, void *));
	else if (type == 'u')
		count += ft_put_u(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		count += ft_put_x(va_arg(args, unsigned int), type);
	else if (type == '%')
		count += write(1, "%", 1);
	return (count);
}