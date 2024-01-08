/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:39:55 by cooi              #+#    #+#             */
/*   Updated: 2023/09/15 17:05:20 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_create_mapped_node(
	t_list *lst_node, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*new_node;

	content = f(lst_node->content);
	if (!content)
		return (NULL);
	new_node = ft_lstnew(content);
	if (!new_node)
	{
		del(content);
		return (NULL);
	}
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*nnode;

	if (!lst || !f || !del)
		return (NULL);
	nlist = NULL;
	while (lst != NULL)
	{
		nnode = ft_create_mapped_node(lst, f, del);
		if (!nnode)
		{
			ft_lstclear(&nlist, del);
			return (NULL);
		}
		ft_lstadd_back(&nlist, nnode);
		lst = lst->next;
	}
	return (nlist);
}
