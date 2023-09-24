/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:50:05 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/24 22:43:35 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	strchk(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_asgn(const char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(*args, unsigned int));
	else if (c == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(*args, uintptr_t));
	else if (c == 'd' || c == 'i')
		count += ft_putint(va_arg(*args, int));
	else if (c == 'u')
		count += ft_putint(va_arg(*args, unsigned int));
	else if (c == 'x')
		count += ft_puthex(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += ft_puthex(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (strchk("cspdiuxX%", str[i + 1]))
				count += ft_asgn(str[++i], &args);
			else
			{
				count += write (1, &str[i], 1);
				count += write (1, &str[++i], 1);
			}
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}
