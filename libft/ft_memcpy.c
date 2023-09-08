/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:23:59 by eteo              #+#    #+#             */
/*   Updated: 2023/09/08 12:33:16 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*sce;
	unsigned char	*dst;
	size_t			i;

	sce = src;
	dst = dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dst != sce)
	{
		while (i < n)
		{
			dst[i] = sce[i];
			i++;
		}
	}
	return (dest);
}
