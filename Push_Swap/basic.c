/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:18:52 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/24 14:18:28 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	max_stack(t_node *a)
{
	int	max;

	if (!a)
		return (-1);
	max = INT_MIN;
	while (a)
	{
		if (a->num >= max)
			max = a->num;
		a = a->next;
	}
	return (max);
}

int	min_stack(t_node *a)
{
	int	min;

	if (!a)
		return (-1);
	min = INT_MAX;
	while (a)
	{
		if (a->num <= min)
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
		if (lstlast(*a)->num == min_stack(*a))
			ft_rra(a);
		else
			ft_sa(a);
	}
}
