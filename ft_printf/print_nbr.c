/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:57:21 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/24 21:11:41 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(long n)
{
	int		count;
	long	nb;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb *= -1;
	}
	if (n > 9)
	{
		ft_putint(nb / 10);
		ft_putint(nb % 10);
	}
	else
		count += ft_putchar(nb + '0');
	return (count);
}
