/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:08:28 by eteo              #+#    #+#             */
/*   Updated: 2023/09/09 16:22:31 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (*str1 || *str2))
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
