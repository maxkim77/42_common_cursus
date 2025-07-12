/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2025/07/12 14:00:00 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_p(void *arg)
{
	int				count;
	char			*alpha;
	unsigned long	arg2;

	arg2 = (unsigned long)arg;
	alpha = "0123456789abcdef";
	count = 0;
	count += ft_put_s("0x");
	count += ft_base16(arg2, alpha);
	return (count);
}
