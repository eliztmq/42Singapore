/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:07:25 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/26 17:18:53 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(uintptr_t n, int *count)
{
	*count += write(1, "0x", 2);
	if (n == 0)
		*count += ft_putchar('0');
	else
		ft_puthex(n, "0123456789abcdef", count);
}

void	ft_puthex(unsigned long n, const char *str, int *count)
{
	if (n > 15)
	{
		ft_puthex(n / 16, str, count);
		ft_puthex(n % 16, str, count);
	}
	else
		*count += ft_putchar(str[n]);
}
