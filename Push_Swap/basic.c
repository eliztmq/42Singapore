/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:18:52 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/06 21:58:51 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	max_stack(t_node *a)
{
	int	max;

	if (!a)
		return (NULL);
	max = INT_MIN;
	while (a)
	{
		if (a->num > max)
			max = a->num;
		a = a->next;
	}
	return (max);
}

int	min_stack(t_node *a)
{
	int	min;

	if (!a)
		return (NULL);
	min = INT_MAX;
	while (a)
	{
		if (a->num < min)
			min = a->num;
		a = a->next;
	}
	return (min);
}

void	basic_op(t_node **a)
{
	if (max_stack(*a) == (*a)->num)
	{
		ft_ra(a);
		if (!check_order(a))
			ft_sa(a);
	}
	else if (min_stack(*a) == (*a)->num)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else
	{
		if (ft_lstlast((*a)->num) == min_stack(*a))
			ft_rra(a);
		else
			ft_sa(a);
	}
}
