/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:14:54 by elizabethte       #+#    #+#             */
/*   Updated: 2024/04/25 22:50:11 by elizabethte      ###   ########.fr       */
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

t_node	*comp_stk(t_node *inc_node, t_node **stack)
{
	t_node	*output;
	t_node	**tmp;

	output = NULL;
	tmp = stack;
	while (*tmp)
	{
		if (!(*tmp)->next)
			if ((*tmp)->num < inc_node->num && (*stack)->num > inc_node->num)
				output = tmp;
		else if ((*tmp)->num < inc_node->num && (*tmp)->next->num > inc_node->num)
			output = *tmp;
		*tmp = (*tmp)->next;
	}
	return (output);
}

void	fill_cost(t_node *a, t_node *b_in)
{
	if (a->for_ind <= a->back_ind && b_in->for_ind <= b_in->back_ind)
	{
		if (a->for_ind >= b_in->for_ind)
			a->cost = a->for_ind;
		else
			a->cost = b_in->for_ind;
	}
	else if (a->for_ind > a->back_ind && b_in->for_ind > b_in->back_ind)
	{
		if (a->back_ind >= b_in->back_ind)
			a->cost = a->back_ind;
		else
			a->cost = b_in->back_ind;
	}
	else
	{
		if (a->for_ind + b_in->back_ind < a->back_ind + b_in->for_ind)
			a->cost = a->for_ind + b_in->back_ind;
		else
			a->cost = a->back_ind + b_in->for_ind;
	}
}

void	ft_cost(t_node **a, t_node **b)
{
	t_node	*b_in;

	if (!fill_index(a) && !fill_index(b))
		return ;
	while (*a)
	{
		b_in = comp_stk(*a, b);
		fill_cost(*a, b_in);
		(*a) = (*a)->next;
	}
}
