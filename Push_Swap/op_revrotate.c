/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:45:40 by elizabethte       #+#    #+#             */
/*   Updated: 2024/04/08 22:59:20 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	ft_rev_rotate(t_node **stack)
{
	t_node	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = *stack;
	(*stack)->prev = last_node;
	*stack = last_node;
}

void	ft_rra(t_node **a)
{
	ft_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_node **b)
{
	ft_rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_node **a, t_node **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	write(1, "rrr\n", 4);
}
