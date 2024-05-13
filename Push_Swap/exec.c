/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:49:20 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/13 15:10:02 by eteo             ###   ########.fr       */
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
	t_node	*tmp;

	check = INT_MIN;
	flag = 0;
	tmp = *a;
	while (tmp)
	{
		if ((tmp)->num >= check)
		{
			check = (tmp)->num;
			(tmp) = (tmp)->next;
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
		ft_pb(a, b);
	exec_loop(a, b);
}
