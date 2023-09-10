/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:27:33 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/10 21:36:40 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pt;
	int		i;

	i = 0;
	pt = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (pt == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		pt[i] = s1[i];
		i++;
	}
	return (pt);
}