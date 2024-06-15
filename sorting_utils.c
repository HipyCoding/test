/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:55:10 by candrese          #+#    #+#             */
/*   Updated: 2024/06/15 20:46:03 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void assign_index(t_stack_node *stack, int size)
{
	int				i;
	int				min;
	t_stack_node	*temp;

	if (!stack)
		return;
	i = 0;
	min = INT_MIN;
	while (i < size)
	{
		min = next_bigger(stack, min);
		temp = stack;
		while (temp)
		{
			if (temp->value == min)
			{
				temp->index = i;
				i++;
				break ;
			}
			temp = temp->next;
		}
	}
}

void	get_positions(t_stack_node *stack)
{
	t_stack_node	*node;
	int				position;

	node = stack;
	position = 1;

	while (node)
	{
		node->position = position;
		node = node->next;
		position++;
	}
}

// TODO: 
	// cheapest target function,
	// 	function which finds the target position in stack a
	// 	from elements in stack b 
// 	cheapest node function,
		// calculate which node needs the least amount of moves
		// to go into target position in stack a
		// eventually find out if possible ,if we can rr/rrr
		// instead of rb + ra/rrb + rra
