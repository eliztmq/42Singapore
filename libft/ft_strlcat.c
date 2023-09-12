/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:26:04 by eteo              #+#    #+#             */
/*   Updated: 2023/09/11 21:29:43 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dcnt;
	size_t	scnt;
	size_t	i;

	dcnt = ft_strlen(dest);
	scnt = ft_strlen(src);
	i = 0;
	if (!dest && size == 0)
		return (scnt);
	if (size <= dcnt)
		return (size + scnt);
	while (src[i] != '\0' && dcnt + 1 < size)
	{
		dest[dcnt] = src[i];
		dcnt++;
		i++;
	}
	dest[dcnt] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[i]));
}
/*
#include <bsd/string.h>
int	main(void)
{
	char	str1[50] = "Just checking";
	char	str3[50] = "Just checking";
	char	str2[50] = "hello";
	printf("%zu", ft_strlcat(str1, str2, 50));
	printf("%s", str1);
	printf("%zu", strlcat(str3, str2, 50));
}
*/
