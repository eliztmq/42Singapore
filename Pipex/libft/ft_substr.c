/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:32:25 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/12 17:22:43 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;

	strlen = ft_strlen(s);
	if (start + len > strlen && start < strlen)
		len = strlen - start;
	if (start > strlen)
		len = 0;
	else if (!s[start])
		len = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	if (!(*s) || start > strlen)
	{
		ft_strlcpy(substr, "", 1);
		return (substr);
	}
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
