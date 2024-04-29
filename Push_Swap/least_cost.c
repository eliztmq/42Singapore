/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   least_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:16:41 by elizabethte       #+#    #+#             */
/*   Updated: 2024/04/29 23:11:19 by elizabethte      ###   ########.fr       */
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

void	for_exec(t_node **a, t_node **b, int a_idx, int b_idx)
{
	int	ab_loop;
	int	ind_loop;

	ab_loop = a_idx;
	ind_loop = ft_abs(a_idx - b_idx);
	if (a_idx > b_idx)
		ab_loop = b_idx;
	while (ab_loop)
	{
		ft_rr(a, b);
		ab_loop--;
	}
	while (ind_loop)
	{
		if (a_idx > b_idx)
			ft_ra(a);
		else
			ft_rb(b);
		ind_loop--;
	}
}

void	back_exec(t_node **a, t_node **b, int a_idx, int b_idx)
{
	int	ab_loop;
	int	ind_loop;

	ab_loop = a_idx;
	ind_loop = ft_abs(a_idx - b_idx);
	if (a_idx > b_idx)
		ab_loop = b_idx;
	while (ab_loop)
	{
		ft_rrr(a, b);
		ab_loop--;
	}
	while (ind_loop)
	{
		if (a_idx > b_idx)
			ft_rra(a);
		else
			ft_rrb(b);
		ind_loop--;
	}
}

void	sep_exec(t_node *a, t_node **b, t_node *sel_a, t_node *sel_b)
{
	int	r_loop;
	int	rr_loop;

	if (sel_a->for_ind + sel_b->back_ind < sel_a->back_ind + sel_b->for_ind)
	{
		r_loop = sel_a->for_ind + 1;
		rr_loop = sel_b->back_ind + 1;
		while (--r_loop)
			ft_ra(a);
		while (--rr_loop)
			ft_rrb(b);
	}
	else
	{
		r_loop = sel_b->for_ind + 1;
		rr_loop = sel_a->back_ind + 1;
		while (--r_loop)
			ft_rb(b);
		while (--rr_loop)
			ft_rra(a);
	}
}

void	ft_least(t_node **a, t_node **b)
{
	t_node	*s_a;
	t_node	*s_b;

	s_a = lowest_cost(a);
	s_b = comp_stk(s_a, b);
	if (s_a->for_ind <= s_a->back_ind && s_b->for_ind <= s_b->back_ind)
		for_exec(a, b, s_a->for_ind, s_b->for_ind);
	else if (s_a->for_ind > s_a->back_ind && s_b->for_ind > s_b->back_ind)
		back_exec(a, b, s_a->back_ind, s_b->back_ind);
	else
		sep_exec(a, b, s_a, s_b);
	ft_pa(a);
}
