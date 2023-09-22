/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:50:05 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/22 18:02:45 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_asgn(const char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c' || c == '%')
		count += ft_putchar(va_arg(*args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(*args, unsigned int));
	else if (c == 'd' || c == 'i')
		count += ft_putint(va_arg(*args, int));
	else if (c == 's')
		count += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		count += ft_putptr(va_arg(*args, uintptr_t));
	else if (c == 'u')	
		
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_asgn(str[++i], &args);
		else
			write(1, format[i], 1);
		i++;
	}
}
