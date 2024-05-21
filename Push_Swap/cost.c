/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:14:54 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/21 08:10:39 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	fill_index(t_node **stack)
{
	int		for_ind;
	int		back_ind;
	t_node	*tmp;

	if (!(*stack))
		return (0);
	for_ind = 0;
	back_ind = lstsize(*stack);
	tmp = *stack;
	while (*stack)
	{
		(*stack)->for_ind = for_ind;
		(*stack)->back_ind = back_ind;
		for_ind++;
		back_ind--;
		(*stack) = (*stack)->next;
	}
	*stack = tmp;
	return (1);
}

t_node	*comp_stack(t_node *inc_node, t_node **stack)
{
	t_node	*output;
	t_node	*tmp;
	t_node	*biggest;
	int		diff;

	output = NULL;
	biggest = NULL;
	tmp = *stack;
	diff = INT_MAX;
	while (tmp)
	{
		if ((tmp)->num < inc_node->num
			&& inc_node->num - (tmp)->num <= diff)
		{
			output = tmp;
			diff = inc_node->num - (tmp)->num;
		}
		if (tmp->num == max_stack(*stack))
			biggest = tmp;
		tmp = (tmp)->next;
	}
	if (diff == INT_MAX)
		output = biggest;
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
	t_node	*tmp_p;

	fill_index(p_stack);
	fill_index(r_stack);
	tmp_p = *p_stack;
	while (*p_stack)
	{
		r_in = comp_stack(*p_stack, r_stack);
		fill_cost(*p_stack, r_in);
		(*p_stack) = (*p_stack)->next;
	}
	*p_stack = tmp_p;
}
