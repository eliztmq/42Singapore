/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:22:49 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/10 16:39:30 by elizabethte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	if_alpha(char *str)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (ft_isalpha((int)str[i]))
			flag = 1;
	}
	return (flag);
}

int	check_dup(t_node **a, int num)
{
	t_node	**tmp;

	if (!*a)
		return (0);
	tmp = a;
	while (*tmp)
	{
		if ((*tmp)->num == num)
			return (1);
		(*tmp) = (*tmp)->next;
	}
	return (0);
}

void	add_node(t_node **a, int num)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->num = num;
	new_node->next = NULL;
	if (*a == NULL)
	{
		*a = new_node;
		new_node->prev = NULL;
		return ;
	}
	last_node = lstlast(*a);
	new_node->prev = last_node;
	last_node->next = new_node;
}

int	ft_process(char **argv, t_node **a)
{
	int		i;
	long	num;

	i = 0;
	while (argv[++i])
	{
		if (if_alpha(argv[i]))
			return (1);
		num = ft_atoi(argv[i]);
		if (num >= INT_MAX || num <= INT_MIN)
			return (1);
		if (check_dup(a, (int)num))
			return (1);
		add_node(a, (int)num);
	}
	return (0);
}
