/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:23:59 by eteo              #+#    #+#             */
/*   Updated: 2023/09/08 11:35:36 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*sce;
	unsigned char	*dst;
	size_t			i;

	sce = src;
	dest = dst;
	i = 0;
	while (i < n)
	{
		dst[i] = sce[i];
		i++;
	}
	return (dest);
}
