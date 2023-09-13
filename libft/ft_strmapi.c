/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:05:31 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/13 15:41:46 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mods;
	int				strlen;
	unsigned int	i;

	strlen = ft_strlen(s);
	i = 0;
	mods = (char *)malloc(sizeof(char) * (strlen + 1));
	if (!mods)
		return (NULL);
	while (s[i])
	{
		mods[i] = f(i, s[i]);
		i++;
	}
	mods[i] = '\0';
	return (mods);
}
