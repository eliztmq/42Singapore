/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:32:45 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/06 22:36:28 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_rotate(t_node **stack)
{
	t_node	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_node = lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ft_ra(t_node **a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rb(t_node **b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_rr(t_node **a, t_node **b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
