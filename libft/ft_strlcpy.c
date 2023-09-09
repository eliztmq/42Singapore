/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:14:06 by eteo              #+#    #+#             */
/*   Updated: 2023/09/09 12:25:41 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	cnt;

	cnt = 0;
	if (size != 0)
	{
		while (src[cnt] != '\0' && cnt < (size - 1))
		{
			dest[cnt] = src[cnt];
			cnt++;
		}
		dest[cnt] = '\0';
	}
	return (ft_strlen(src));
}
