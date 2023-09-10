/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 23:52:44 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/10 21:06:37 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ifspace(const char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == " ")
			i++;
		if (str[i] == "\t")
			i++;
		if (str[i] == "\n")
			i++;
		if (str[i] == "\v")
			i++;
		if (str[i] == "\f")
			i++;
		if (str[i] == "\r")
			i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int					i;
    int					sign;
    unsigned long int	result;
	
	sign = 1;
	result = 0;
	i = ifspace(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;    
	}
	while (ft_isdigit(str[i]))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}