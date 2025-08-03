/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeongkim <jeongkim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:00:00 by jeongkim          #+#    #+#             */
/*   Updated: 2025/08/03 13:50:00 by jeongkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_u(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
	{
		count += ft_put_u(nb / 10);
		count += ft_put_u(nb % 10);
	}
	else
		count += ft_put_c(nb + '0');
	if (count < 0)
	{
		return (-1);
	}
	return (count);
}
