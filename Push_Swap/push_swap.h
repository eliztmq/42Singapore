/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:48:55 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/16 07:35:19 by eteo             ###   ########.fr       */
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

//push_back.c
t_node	*min_pos(t_node *a, int min);
void	rot_a(t_node **a);
void	ft_pushback(t_node **a, t_node **b);

//least_cost.c
t_node	*lowest_cost(t_node **a);
void	ab_for(t_node **a, t_node **b, int a_idx, int b_idx);
void	ab_back(t_node **a, t_node **b, int a_idx, int b_idx);
void	stack_exec(t_node **stack, t_node *target, char stack_name);
void	ft_least(t_node **a, t_node **b);

//init.c
int		if_alpha(char *str);
int		check_dup(t_node **a, int num);
void	add_node(t_node **a, int num);
int		ft_process(char **argv, t_node **a);

//exec.c
int		lstsize(t_node *lst);
int		check_order(t_node **a);
void	exec_loop(t_node **a, t_node **b);
void	ft_execute(t_node **a, t_node **b);

//cost.c
int		fill_index(t_node **stack);
t_node	*comp_stack(t_node *inc_node, t_node **stack);
void	fill_cost(t_node *p_stack, t_node *r_stack);
void	ft_cost(t_node **p_stack, t_node **r_stack);

//basic.c
int		max_stack(t_node *a);
int		min_stack(t_node *a);
void	basic_op(t_node **a);

//op_push.c
void	ft_push(t_node **pusher, t_node **receiver);
void	ft_pa(t_node **b, t_node **a);
void	ft_pb(t_node **a, t_node **b);

//op_revrotate.c
t_node	*lstlast(t_node *lst);
void	ft_rev_rotate(t_node **stack);
void	ft_rra(t_node **a);
void	ft_rrb(t_node **b);
void	ft_rrr(t_node **a, t_node **b);

//op_rotate.c
void	ft_rotate(t_node **stack);
void	ft_ra(t_node **a);
void	ft_rb(t_node **b);
void	ft_rr(t_node **a, t_node **b);

//op_swap.c
void	ft_swap(t_node **stack);
void	ft_sa(t_node **a);
void	ft_sb(t_node **b);
void	ft_ss(t_node **a, t_node **b);

#endif