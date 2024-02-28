/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:29:33 by elizabethte       #+#    #+#             */
/*   Updated: 2024/02/28 15:06:20 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	checkstr(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
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
	jstr = ft_calloc((s1len + s2len + 1), sizeof(char));
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
