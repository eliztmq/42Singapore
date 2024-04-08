/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:48:55 by elizabethte       #+#    #+#             */
/*   Updated: 2024/04/07 22:18:31 by elizabethte      ###   ########.fr       */
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
	char	*op;
	int		min_cost;
	int		min_num;
	int		max_num;
}	t_node;

#endif