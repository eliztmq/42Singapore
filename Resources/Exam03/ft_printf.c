/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <cooi@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:53:35 by cooi              #+#    #+#             */
/*   Updated: 2023/11/24 22:20:21 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	printbase(long n, char *base, int l, long *c)
{
	if (n < 0)
	{
		*c += write(1, "-", 1);
		n = -n;
	}
	if (n >= l)
		printbase(n / l, base, l, c);
	*c += write(1, &(base[n % l]), 1);
}

long	ft_printf(const char *s, ...)
{
	long	count;
	char	*str;
	va_list	ap;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1) == 's' && s++ && s++)
		{
			str = (va_arg(ap, char *));
			if (!str)
				count += write(1, "(null)", 6);
			else
				while (*str)
					count += write(1, &(*str++), 1);
		}
		else if (*s == '%' && *(s + 1) == 'i' && s++ && s++)
			printbase(va_arg(ap, int), "0123456789", 10, &count);
		else if (*s == '%' && *(s + 1) == 'x' && s++ && s++)
			printbase(va_arg(ap, unsigned int), "0123456789abcdef", 16, &count);
		else
			count += write(1, &(*s++), 1);
	}
	return (va_end(ap), count);
}
