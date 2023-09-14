/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:44:05 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/14 23:35:49 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*dlst;
	t_list	*tmp;

	if(!lst)
		return ;
	dlst = *lst;
	while(dlst)
	{
		tmp = dlst -> next;
		ft_lstdelone(dlst, del);
		dlst = tmp;
	}
	*lst = NULL;
}