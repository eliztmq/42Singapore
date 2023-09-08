/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:23:59 by eteo              #+#    #+#             */
/*   Updated: 2023/09/08 23:52:33 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sce;
	unsigned char	*dst;
	size_t			i;

	sce = (unsigned char *)src;
	dst = (unsigned char *)dest;
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
