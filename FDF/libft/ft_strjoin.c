/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:57:23 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/11 23:44:57 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*jstr;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	jstr = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (jstr == NULL)
		return (NULL);
	ft_strlcpy(jstr, s1, s1len + 1);
	ft_strlcat(jstr, s2, s1len + s2len + 1);
	return (jstr);
}
