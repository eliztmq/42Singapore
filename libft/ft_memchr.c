/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:22:50 by eteo              #+#    #+#             */
/*   Updated: 2023/09/09 16:40:16 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chk;
	size_t			i;

	i = 0;
	chk = (unsigned char *)s;
	while (i < n && *chk)
	{
		if (*chk == (unsigned char)c)
			return (chk);
		chk++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char s[] = "Aticleworld";
    	char *ptr = ft_memchr(s,'c',sizeof(s));
    	if (ptr != NULL)
    	{
        	printf ("'c' found at position %ld.\n", ptr-s+1);
        	printf ("search character found:  %s\n", ptr);
    	}
    	else
    	{
        	printf ("search character not found\n");
    	}	
    	return (0);
}
*/
