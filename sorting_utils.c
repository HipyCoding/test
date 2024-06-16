/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:55:10 by candrese          #+#    #+#             */
/*   Updated: 2024/06/16 04:56:38 by candrese         ###   ########.fr       */
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
	i = 1;
	min = INT_MIN;
	while (i <= size)
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

void	get_target_positions(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node_a;
	t_stack_node	*node_b;
	int				prev_value;
	
	node_a = *a;
	node_b = *b;
	while (node_b)
	{
		prev_value = INT_MIN;
		while(node_a)
		{
			if (node_b->value > node_a->value && node_a->value > prev_value)
			{
				node_b->target_position = node_a->position + 1;
				prev_value = node_a->value;
			}
			node_a = node_a->next;
		}
		if(prev_value == INT_MIN)
			node_b->target_position = 1;
		node_a = *a;
		node_b = node_b->next;
	}
}

void	get_costs(t_stack_node **a, t_stack_node **b, int size_a, int size_b)
{
	t_stack_node	*node_a;
	t_stack_node	*node_b;

	node_a = *a;
	node_b = *b;
	while(node_b)
	{
		if (node_b->position > size_b / 2)
			node_b->cost_b = (size_b - node_b->position) * (-1);
		else
			node_b->cost_b = node_b->position;
		if (node_b->target_position > size_a / 2)
			node_b->cost_a = (size_a - node_b->target_position) * (-1);
		else
			node_b->cost_a = node_b->target_position;
		node_b = node_b->next;
	}
}


// TODO: 
// 	cheapest node function,
		// calculate which node needs the least amount of moves
		// to go into target position in stack a
		// eventually find out if possible ,if we can rr/rrr
		// instead of rb + ra/rrb + rra
// 	sorting function which does the actual moves
