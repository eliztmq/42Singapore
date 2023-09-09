/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:22:54 by eteo              #+#    #+#             */
/*   Updated: 2023/09/09 12:13:44 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sc;
	char			dir;
	size_t			i;

	i = 0;
	dir = 1;
	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dst > sc)
	{
		dir = -1;
		dst += n - 1;
		sc += n - 1;
	}
	while (i < n)
	{
		*dst = *sc;
		dst += dir;
		sc += dir;
		i++;
	}
	return (dest);
}
