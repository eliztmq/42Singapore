/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:49:20 by elizabethte       #+#    #+#             */
/*   Updated: 2024/04/25 22:58:07 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	check_order(t_node **a)
{
	int	check;
	int	flag;

	check = INT_MIN;
	flag = 0;
	while (*a)
	{
		if ((*a)->num >= check)
		{
			check = (*a)->num;
			(*a) = (*a)->next;
			flag = 1;
		}
		else
		{
			flag = 0;
			break ;
		}
	}
	return (flag);
}

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

void	least_cost(t_node **a, t_node **b)
{
	t_node	*sel_a;
	t_node	*sel_b;

	sel_a = lowest_cost(a);
	sel_b = comp_stk(sel_a, b);
}

void	exec_loop(t_node **a, t_node **b)
{
	if (ft_lstsize(*a) <= 3)
	{
		basic_op(a);
		ft_pushback(a, b);
		return ;
	}
	ft_cost(a, b);
	least_cost(a, b);
	exec_loop(a, b);
}

void	ft_execute(t_node **a, t_node **b)
{
	int	count;

	count = 3;
	if (check_order(a))
	{
		free_stack(a);
		write(1, "Arguments are in order\n", 24);
		exit(EXIT_SUCCESS);
	}
	if (ft_lstsize(*a) <= 3)
	{
		basic_op(a);
		return ;
	}
	while (--count)
		ft_pa(a, b);
	exec_loop(a, b);
}
