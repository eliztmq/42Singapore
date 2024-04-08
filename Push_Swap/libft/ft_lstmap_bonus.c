/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:00:24 by elizabethte       #+#    #+#             */
/*   Updated: 2023/09/15 18:10:21 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_addmappednode(
	t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*nn;

	content = f(lst ->content);
	if (!content)
		return (NULL);
	nn = ft_lstnew(content);
	if (!nn)
	{
		del(content);
		return (NULL);
	}
	return (nn);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mlst;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	mlst = NULL;
	while (lst)
	{
		tmp = ft_addmappednode(lst, f, del);
		if (!tmp)
		{
			ft_lstclear(&mlst, del);
			return (NULL);
		}
		ft_lstadd_back(&mlst, tmp);
		lst = lst -> next;
	}
	return (mlst);
}
