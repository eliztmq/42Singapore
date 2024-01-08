/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:26:22 by eteo              #+#    #+#             */
/*   Updated: 2023/09/12 22:29:25 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, char const *set)
{
	int	cnt;

	cnt = 0;
	while (set[cnt])
	{
		if (c == set[cnt])
			return (1);
		cnt++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		strlen;
	char	*str;

	while (*s1)
	{
		if (!ft_check(*s1, set))
			break ;
		s1++;
	}
	strlen = ft_strlen(s1);
	while (strlen != 0)
	{
		if (!ft_check(s1[strlen - 1], set))
			break ;
		strlen--;
	}
	str = ft_substr((char *)s1, 0, strlen);
	return (str);
}
