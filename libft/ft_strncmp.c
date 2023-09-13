/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:08:28 by eteo              #+#    #+#             */
/*   Updated: 2023/09/13 17:10:28 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
/*
#include<bsd/string.h>
int	main(void)
{
	char	str1[50] = "string";
	char	str2[50] = "of comparison";
	printf("%d", ft_strncmp(str1, str2, 8));
	printf("%d", strncmp(str1, str2, 8));
}
*/
