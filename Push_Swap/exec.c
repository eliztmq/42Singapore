/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:49:20 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/06 22:38:38 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	lstsize(t_node *lst)
{
	int		i;
	t_node	*n;

	i = 0;
	n = lst;
	while (n)
	{
		n = n->next;
		i++;
	}
	return (i);
}

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

void	exec_loop(t_node **a, t_node **b)
{
	if (lstsize(*a) <= 3)
	{
		basic_op(a);
		ft_pushback(a, b);
		return ;
	}
	ft_cost(a, b);
	ft_least(a, b);
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
	if (lstsize(*a) <= 3)
	{
		basic_op(a);
		return ;
	}
	while (--count)
		ft_pa(a, b);
	exec_loop(a, b);
}
