/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:14:54 by elizabethte       #+#    #+#             */
/*   Updated: 2024/04/22 23:15:53 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	fill_index(t_node **stack)
{
	int	for_ind;
	int	back_ind;

	if (!(*stack))
		return (0);
	for_ind = 0;
	back_ind = ft_lstsize(*stack);
	while(*stack)
	{
		(*stack)->for_ind = for_ind;
		(*stack)->back_ind = back_ind;
		for_ind++;
		back_ind--;
		(*stack) = (*stack)->next;
	}
	return(1);
}

t_node	comp_stk(t_node *inc_node, t_node **stack)
{
	t_node	**tmp;
}

void	ft_cost(t_node **a, t_node **b)
{
	t_node	b_ins;

	if (!fill_index(a) && !fill_index(b))
		return ;
	while (*a)
	{
		b_ins = comp_stk(*a, b);
	}
}
