/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:41:11 by eteo              #+#    #+#             */
/*   Updated: 2023/09/12 16:27:48 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/*
int main ()
{
    int ret = 0;
    char s1[15] = "Hello";
    char s2[15] = "Aticleworld";
    ret = ft_memcmp(s1, s2, 5);
    if(ret > 0)
    {
        printf("s2 is less than s1");
    }
    else if(ret < 0)
    {
        printf("s1 is less than s2");
    }
    else
    {
        printf("s1 is equal to s2");
    }
    return 0;
}
*/
