/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:14:54 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/06 22:47:28 by elizabethte      ###   ########.fr       */
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
	back_ind = lstsize(*stack);
	while (*stack)
	{
		(*stack)->for_ind = for_ind;
		(*stack)->back_ind = back_ind;
		for_ind++;
		back_ind--;
		(*stack) = (*stack)->next;
	}
	return (1);
}

t_node	*comp_stack(t_node *inc_node, t_node **stack)
{
	t_node	*output;
	t_node	**tmp;

	output = NULL;
	tmp = stack;
	while (*tmp)
	{
		if (!(*tmp)->next)
		{
			if ((*tmp)->num < inc_node->num && (*stack)->num > inc_node->num)
				output = *tmp;
		}
		else if ((*tmp)->num < inc_node->num
			&& (*tmp)->next->num > inc_node->num)
			output = *tmp;
		*tmp = (*tmp)->next;
	}
	return (output);
}

void	fill_cost(t_node *p_stack, t_node *r_stack)
{
	if (p_stack->for_ind <= p_stack->back_ind
		&& r_stack->for_ind <= r_stack->back_ind)
	{
		if (p_stack->for_ind >= r_stack->for_ind)
			p_stack->cost = p_stack->for_ind;
		else
			p_stack->cost = r_stack->for_ind;
	}
	else if (p_stack->for_ind > p_stack->back_ind
		&& r_stack->for_ind > r_stack->back_ind)
	{
		if (p_stack->back_ind >= r_stack->back_ind)
			p_stack->cost = p_stack->back_ind;
		else
			p_stack->cost = r_stack->back_ind;
	}
	else
	{
		if (p_stack->for_ind + r_stack->back_ind
			< p_stack->back_ind + r_stack->for_ind)
			p_stack->cost = p_stack->for_ind + r_stack->back_ind;
		else
			p_stack->cost = p_stack->back_ind + r_stack->for_ind;
	}
}

void	ft_cost(t_node **p_stack, t_node **r_stack)
{
	t_node	*r_in;

	if (!fill_index(p_stack) && !fill_index(r_stack))
		return ;
	while (*p_stack)
	{
		r_in = comp_stack(*p_stack, r_stack);
		fill_cost(*p_stack, r_in);
		(*p_stack) = (*p_stack)->next;
	}
}
