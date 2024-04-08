/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:16:58 by elizabethte       #+#    #+#             */
/*   Updated: 2024/03/06 09:11:39 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

//have to include osize so that won't move unnecessary elements
void	*ft_realloc(void *ptr, size_t size, size_t osize)
{
	void	*new_ptr;

	new_ptr = ft_calloc(1, size);
	if (!new_ptr)
		return (NULL);
	if (!ptr || osize == 0)
	{
		free(ptr);
		return (new_ptr);
	}
	if (size < osize)
		ft_memmove(new_ptr, ptr, size);
	else
		ft_memmove(new_ptr, ptr, osize);
	free(ptr);
	return (new_ptr);
}
