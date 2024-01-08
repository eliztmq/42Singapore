/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:16:58 by elizabethte       #+#    #+#             */
/*   Updated: 2023/12/15 17:32:06 by elizabethte      ###   ########.fr       */
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
	if (!ptr)
		return (new_ptr);
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (size < osize)
		ft_memmove(new_ptr, ptr, size);
	else
		ft_memmove(new_ptr, ptr, osize);
	free(ptr);
	return (new_ptr);
}
