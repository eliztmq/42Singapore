/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:57:21 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/26 16:31:30 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putint(long n, int *count)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		*count += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putint(nb / 10, count);
		ft_putint(nb % 10, count);
	}
	else
		*count += ft_putchar(nb + '0');
}
