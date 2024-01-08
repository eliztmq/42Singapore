/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:05:11 by cooi              #+#    #+#             */
/*   Updated: 2023/09/14 21:11:53 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hex(char c, va_list ap, int fd)
{
	int				count;
	unsigned long	content;

	count = 0;
	content = (unsigned long)va_arg(ap, void *);
	if (c == 'p')
	{
		if (content == 0)
		{
			write(fd, "(nil)", 5);
			return (5);
		}
		write(1, "0x", 2);
		count += 2;
		ft_putnbr_base(content, 1, &count);
	}
	else if (c == 'x')
		ft_putnbr_base((unsigned int)content, 1, &count);
	else if (c == 'X')
		ft_putnbr_base((unsigned int)content, 2, &count);
	return (count);
}
