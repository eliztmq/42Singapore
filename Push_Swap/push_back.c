/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:32:23 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/13 15:10:25 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_pushback(t_node **a, t_node **b)
{
	t_node	*r_a;
	t_node	*p_b;

	while (!(*b))
	{
		ft_cost(b, a);
		p_b = lowest_cost(b);
		r_a = comp_stack(p_b, a);
		if (r_a->for_ind <= r_a->back_ind && p_b->for_ind <= p_b->back_ind)
			ab_for(a, b, r_a->for_ind, p_b->for_ind);
		else if (r_a->for_ind > r_a->back_ind && p_b->for_ind > p_b->back_ind)
			ab_back(a, b, r_a->back_ind, p_b->back_ind);
		stack_exec(a, r_a, 'a');
		stack_exec(b, p_b, 'b');
		ft_pa(b, a);
	}
}
