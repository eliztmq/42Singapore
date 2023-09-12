/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:46:47 by eteo              #+#    #+#             */
/*   Updated: 2023/09/11 23:45:39 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	cnt;

	cnt = ft_strlen(str);
	str += cnt;
	while (cnt >= 0)
	{
		if (*str == (char)c)
			return ((char *)str);
		cnt--;
		str--;
	}
	return (NULL);
}
/*
#include<bsd/string.h>
int	main(void)
{
	char	str[50] = "Just checking";
	printf("%p", ft_strrchr(str, 99));
	printf("%p", strrchr(str, 99));
}
*/
