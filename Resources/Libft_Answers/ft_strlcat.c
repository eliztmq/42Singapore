/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:40:10 by cooi              #+#    #+#             */
/*   Updated: 2023/09/06 21:03:27 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (*dest != '\0')
	{
		dest++;
		i++;
	}
	while (src[j] != '\0')
		j++;
	if (dstsize <= i)
		return (dstsize + j);
	k = i;
	while (*src != '\0' && k < dstsize - 1)
	{
		*dest++ = *src++;
		k++;
	}
	*dest = '\0';
	return (i + j);
}
