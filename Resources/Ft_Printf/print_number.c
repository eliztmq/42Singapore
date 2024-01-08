/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:29:55 by cooi              #+#    #+#             */
/*   Updated: 2023/09/14 21:05:03 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_num(char c, va_list ap, int fd)
{
	int	count;

	count = 0;
	if (c == 'i' || c == 'd')
		ft_putnbr_fd(va_arg(ap, int), fd, &count);
	if (c == 'u')
		ft_putnbr_fd(va_arg(ap, unsigned int), fd, &count);
	return (count);
}
