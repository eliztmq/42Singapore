/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:32:23 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/20 14:11:38 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_node	*min_pos(t_node *a, int min)
{
	t_node	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->num == min)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	rot_a(t_node **a)
{
	t_node	*min_a;
	int		rot_freq;

	fill_index(a);
	min_a = min_pos(*a, min_stack(*a));
	rot_freq = min_a->for_ind;
	if (min_a->back_ind < min_a->for_ind)
		rot_freq = min_a->back_ind;
	while (rot_freq)
	{
		if (min_a->back_ind < min_a->for_ind)
			ft_rra(a);
		else
			ft_ra(a);
		rot_freq--;
	}
}

void	ft_pushback(t_node **a, t_node **b)
{
	t_node	*r_a;
	t_node	*p_b;

	while (*b)
	{
		ft_cost(b, a);
		p_b = lowest_cost(b);
		r_a = comp_stack(p_b, a);
		if (r_a->for_ind <= r_a->back_ind && p_b->for_ind <= p_b->back_ind)
			ab_for(a, b, r_a->for_ind, p_b->for_ind);
		else if (r_a->for_ind > r_a->back_ind && p_b->for_ind > p_b->back_ind)
			ab_back(a, b, r_a->back_ind, p_b->back_ind);
		stack_exec(b, p_b, 'b');
		stack_exec(a, r_a, 'a');
		ft_pa(b, a);
	}
	rot_a(a);
}
