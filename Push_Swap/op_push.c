/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:13:44 by elizabethte       #+#    #+#             */
/*   Updated: 2024/04/08 22:51:52 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	ft_push(t_node **pusher, t_node **receiver)
{
	t_node	*push;

	if (!(*pusher) || !pusher)
		return ;
	push = (*pusher);
	(*pusher) = (*pusher)->next;
	(*pusher)->prev = NULL;
	if (!(*receiver))
	{
		(*receiver) = push;
		(*receiver)->next = NULL;
	}
	else
	{
		push->next = (*receiver);
		(*receiver)->prev = push;
		(*receiver) = push;
	}
}

void	ft_pa(t_node **b, t_node **a)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_node **a, t_node **b)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
}
