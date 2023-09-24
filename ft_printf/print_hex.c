/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:07:25 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/24 21:13:19 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(uintptr_t n)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex(n, "0123456789abcdef");
	return (count);
}

int	ft_puthex(unsigned long n, const char *str)
{
	int	count;

	count = 0;
	if (n > 15)
	{
		count += ft_puthex(n / 16, str);
		count += ft_puthex(n % 16, str);
	}
	count += ft_putchar(str[n]);
	return (count);
}
