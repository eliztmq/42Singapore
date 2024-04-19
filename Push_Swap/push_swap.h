/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:48:55 by elizabethte       #+#    #+#             */
/*   Updated: 2024/04/19 14:01:13 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int		num;
	struct s_node	*prev;
	struct s_node	*next;
	int		for_ind;
	int		back_ind;
	int		cost;
}	t_node;

//push_swap.c
void	free_stack(t_node **stack);

//init.c
int		if_alpha(char *str);
int		check_dup(t_node **a, int num);
void	add_node(t_node **a, int num);
int		ft_process(char **argv, t_node **a);

//exec.c
int		check_order(t_node **a);
void	exec_loop(t_node **a, t_node **b);
void	least_cost(t_node **a, t_node **b);
void	ft_execute(t_node **a, t_node **b);

//basic.c
int		max_stack(t_node *a);
int		min_stack(t_node *a);
void	basic_op(t_node **a);

#endif