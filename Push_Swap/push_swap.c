/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 22:21:42 by elizabethte       #+#    #+#             */
/*   Updated: 2024/04/11 23:13:16 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	
	if (argc == 1)
		exit(0);
	a = (t_node *)malloc(sizeof(t_node));
	b = (t_node *)malloc(sizeof(t_node));
	if (!a || !b)
		exit (1);
	if (ft_process(argv, &a))
		free(b);
	ft_execute(a, b);
	ft_stack_free(a, b);
}