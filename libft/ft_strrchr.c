/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:46:47 by eteo              #+#    #+#             */
/*   Updated: 2023/09/12 11:13:40 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	cnt;

	cnt = ft_strlen(str);
	str += cnt + 1;
	while ((cnt + 1) >= 0)
	{
		if (str[cnt] == (char)c)
			return ((char *)(str + cnt + 1));
		cnt--;
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
