/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:29:33 by elizabethte       #+#    #+#             */
/*   Updated: 2023/10/14 21:27:39 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			cnt;

	cnt = 0;
	str = s;
	while (cnt < n)
	{
		str[cnt] = 0;
		cnt++;
	}
}

char	*ft_join(char *s1, char *s2)
{
	char	*jstr;
	int		s1len;
	int		s2len;
	int		cnt;

	s1len = 0;
	s2len = 0;
	cnt = 0;
	while (s1 && s1[s1len])
		s1len++;
	while (s2 && s2[s2len] && s2len < BUFFER_SIZE + 1)
		s2len++;
	jstr = (char *)calloc((s1len + s2len + 1), sizeof(char));
	if (jstr == NULL)
		return (NULL);
	while (cnt < s1len && ++cnt)
		jstr[cnt - 1] = s1[cnt - 1];
	s1len = 0;
	while (cnt + s1len < cnt + s2len && ++s1len)
		jstr[cnt + s1len - 1] = s2[s1len - 1];
	jstr[cnt + s1len] = '\0';
	return (jstr);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	cnt;
	int		i;

	i = 0;
	cnt = 0;
	while (src[i])
		i++;
	if (size != 0)
	{
		while (src[cnt] != '\0' && cnt < (size - 1))
		{
			dest[cnt] = src[cnt];
			cnt++;
		}
		dest[cnt] = '\0';
	}
	return (i);
}

void	ft_modsplit(char *srcstr, char *str)
{
	int		i;
	int		cnt;
	void	*temp;

	i = 0;
	cnt = 0;
	while (srcstr && srcstr[i] && srcstr[i] != '\n')
		i++;
	i++;
	while (srcstr[i + cnt])
	{
		str[cnt] = srcstr[i + cnt];
		cnt++;
	}
	srcstr[i] = '\0';
	temp = realloc(srcstr, i);
	if (temp == NULL)
	{
		free(srcstr);
		srcstr = NULL;
	}
	else
		srcstr = temp;
}
