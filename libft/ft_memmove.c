/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:22:54 by eteo              #+#    #+#             */
/*   Updated: 2023/09/08 12:31:11 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*buff;
	const char	*sc;
	size_t		i;

	i = 0;
	dst = dest;
	sc = src;
	while (i < n)
}
