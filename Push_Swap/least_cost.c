/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   least_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:16:41 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/06 22:50:59 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_node	*lowest_cost(t_node **a)
{
	t_node	*output;
	int		min;

	min = INT_MAX;
	while (*a)
	{
		if ((*a)->cost == 0)
			return (*a);
		if ((*a)->cost < min)
		{
			min = (*a)->cost;
			output = *a;
		}
		(*a) = (*a)->next;
	}
	return (output);
}

void	ab_for(t_node **a, t_node **b, int a_idx, int b_idx)
{
	int	ab_loop;

	ab_loop = a_idx;
	if (a_idx > b_idx)
		ab_loop = b_idx;
	while (ab_loop)
	{
		ft_rr(a, b);
		ab_loop--;
	}
	fill_index(a);
	fill_index(b);
}

void	ab_back(t_node **a, t_node **b, int a_idx, int b_idx)
{
	int	ab_loop;

	ab_loop = a_idx;
	if (a_idx > b_idx)
		ab_loop = b_idx;
	while (ab_loop)
	{
		ft_rrr(a, b);
		ab_loop--;
	}
	fill_index(a);
	fill_index(b);
}

void	stack_exec(t_node **stack, t_node *target, char stack_name)
{
	while (*stack != target)
	{
		if (stack_name == 'a')
		{
			if (target->for_ind <= target->back_ind)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (target->for_ind <= target->back_ind)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

void	ft_least(t_node **a, t_node **b)
{
	t_node	*s_a;
	t_node	*s_b;

	s_a = lowest_cost(a);
	s_b = comp_stack(s_a, b);
	if (s_a->for_ind <= s_a->back_ind && s_b->for_ind <= s_b->back_ind)
		ab_for(a, b, s_a->for_ind, s_b->for_ind);
	else if (s_a->for_ind > s_a->back_ind && s_b->for_ind > s_b->back_ind)
		ab_back(a, b, s_a->back_ind, s_b->back_ind);
	stack_exec(a, s_a, 'a');
	stack_exec(b, s_b, 'b');
	ft_pb(a, b);
}
