/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteo <eteo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:22:49 by elizabethte       #+#    #+#             */
/*   Updated: 2024/05/24 14:13:26 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	if_digit(char *str)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		if ((str[i] == '+' || str[i] == '-') && flag == 0)
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			flag = 1;
		else if ((str[i] < '0' || str[i] > '9') && flag == 1)
		{
			flag = 0;
			return (flag);
		}
		else
			return (flag);
	}
	return (flag);
}

int	check_dup(t_node **a, int num)
{
	t_node	*tmp;

	tmp = *a;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if ((tmp)->num == num)
			return (1);
		(tmp) = (tmp)->next;
	}
	return (0);
}

void	add_node(t_node **a, int num)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = malloc(sizeof(t_node));
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
		if (!if_digit(argv[i]))
			return (1);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		if (check_dup(a, (int)num))
			return (1);
		add_node(a, (int)num);
	}
	return (0);
}
