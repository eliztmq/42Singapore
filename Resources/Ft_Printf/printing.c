/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:12:04 by cooi              #+#    #+#             */
/*   Updated: 2023/09/14 21:12:14 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int	count;

	count = 0;
	write(fd, &c, 1);
	count++;
	return (count);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s || fd < 0)
		return (0);
	while (s[i] != '\0')
	{
		count += ft_putchar_fd(s[i], 1);
		i++;
	}
	return (count);
}

void	ft_putnbr_fd(long n, int fd, int *count)
{
	long	tmp;

	tmp = n;
	if (tmp < 0)
	{
		*count += ft_putchar_fd('-', fd);
		tmp *= -1;
	}
	if (tmp > 9)
	{
		ft_putnbr_fd(tmp / 10, fd, count);
		ft_putnbr_fd(tmp % 10, fd, count);
	}
	else
		*count += ft_putchar_fd(tmp + '0', fd);
}

void	ft_putnbr_base(unsigned long nbr, int flag, int *count)
{
	char	*base;

	if (flag == 1)
		base = ft_substr("0123456789abcdef", 0, 16);
	if (flag == 2)
		base = ft_substr("0123456789ABCDEF", 0, 16);
	if (nbr > 15)
	{
		free (base);
		ft_putnbr_base(nbr / 16, flag, count);
		ft_putnbr_base(nbr % 16, flag, count);
	}
	else
	{
		*count += ft_putchar_fd(base[nbr], 1);
		free (base);
	}
}
