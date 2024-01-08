/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:23:05 by cooi              #+#    #+#             */
/*   Updated: 2023/09/14 20:29:46 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(char c, va_list ap, int fd)
{
	char	*str;
	int		count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd((char)va_arg(ap, int), fd);
	else if (c == '%')
		count += ft_putchar_fd('%', fd);
	else if (c == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			count += ft_putstr_fd("(null)", fd);
		else
			count += ft_putstr_fd(str, fd);
	}
	return (count);
}
