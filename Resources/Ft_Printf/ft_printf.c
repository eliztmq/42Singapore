/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:53:35 by cooi              #+#    #+#             */
/*   Updated: 2023/09/13 15:53:39 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(char c, va_list ap)
{
	int		count;

	count = 0;
	if (c == 's' || c == 'c' || c == '%')
		count += handle_c(c, ap, 1);
	else if (c == 'i' || c == 'd' || c == 'u')
		count += handle_num(c, ap, 1);
	else if (c == 'p' || c == 'x' || c == 'X')
		count += handle_hex(c, ap, 1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", s[i + 1]))
				count += print(s[i + 1], ap);
			else
				break ;
			i++;
		}
		else
			count += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
