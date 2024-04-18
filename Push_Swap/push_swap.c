/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 22:21:42 by elizabethte       #+#    #+#             */
/*   Updated: 2024/04/18 23:26:00 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	
	if (argc == 1)
		exit(EXIT_FAILURE);
	a = NULL;
	b = NULL;
	if (ft_process(argv, &a))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	ft_execute(&a, &b);
	free_stack(&a);
}