/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:50:05 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/25 23:56:24 by elizabethte      ###   ########.fr       */
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
		ft_putptr(va_arg(*args, uintptr_t), &count);
	else if (c == 'd' || c == 'i')
		ft_putint(va_arg(*args, int), &count);
	else if (c == 'u')
		ft_putint(va_arg(*args, unsigned int), &count);
	else if (c == 'x')
		ft_puthex(va_arg(*args, unsigned int), "0123456789abcdef", &count);
	else if (c == 'X')
		ft_puthex(va_arg(*args, unsigned int), "0123456789ABCDEF", &count);
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
	va_end(args);
	return (count);
}
