/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 22:07:50 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/06 22:25:11 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_swap(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack);
	(*stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->next->prev = (*stack);
	if ((*stack)->next->next)
		(*stack)->next->next->prev = (*stack)->next;
	(*stack)->prev = NULL;
}

void	ft_sa(t_node **a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_node **b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_node **a, t_node **b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
