/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cooi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 21:30:46 by cooi              #+#    #+#             */
/*   Updated: 2023/09/14 21:30:53 by cooi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			return (1);
		i++;
		s++;
	}
	if (*s == (char)c)
		return (1);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	math(unsigned int start, size_t len, size_t i)
{
	if (i == 0)
		return (0);
	if (start + len > i)
		return (i - start);
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (start > i)
		i = 0;
	len = math(start, len, i);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret || !s)
		return (NULL);
	ret[0] = '\0';
	s += start;
	i = 0;
	while (i < len && s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
