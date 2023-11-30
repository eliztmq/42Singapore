/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:29:55 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/12 23:43:07 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static int	ft_count(char const *s, char c)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*s)
	{
		if (*s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int	ft_len(char *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s != c && *s)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		cnt;
	int		i;

	cnt = ft_count(s, c);
	i = 0;
	str = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (str == NULL)
		return (NULL);
	str[cnt] = NULL;
	while (i < cnt)
	{
		while (*s == c && *s)
			s++;
		str[i] = ft_substr((char *)s, 0, ft_len((char *)s, c));
		if (str[i] == NULL)
			return (ft_free(str, i));
		s = s + ft_len((char *)s, c);
		i++;
	}
	return (str);
}
