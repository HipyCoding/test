/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:55:10 by candrese          #+#    #+#             */
/*   Updated: 2024/06/18 09:11:16 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_of_biggest(t_stack_node **a, t_stack_node *b)
{
	t_stack_node	*node;

	node = b;
	node->target_position = check_max(*a)->position + 1;
	if (check_max(*a)->position == check_size(*a) - 1)
		node->target_position = 0;
}

void	get_positions(t_stack_node *stack)
{
	t_stack_node	*node;
	int				position;

	node = stack;
	position = 0;
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
		prev_value = INT_MAX;
		while (node_a)
		{
			if (node_b->value < node_a->value && node_a->value < prev_value)
			{
				node_b->target_position = node_a->position;
				prev_value = node_a->value;
			}
			node_a = node_a->next;
		}
		if (prev_value == INT_MAX)
			target_of_biggest(a, node_b);
		node_a = *a;
		node_b = node_b->next;
	}
}

void	get_costs(t_stack_node **b, int size_a, int size_b)
{
	t_stack_node	*node_b;

	node_b = *b;
	while (node_b)
	{
		if (node_b->position > size_b / 2)
			node_b->cost_b = (size_b - node_b->position) * (-1);
		else
			node_b->cost_b = node_b->position;
		if (node_b->target_position > size_a / 2)
			node_b->cost_a = (size_a - node_b->target_position) * (-1);
		else
			node_b->cost_a = node_b->target_position;
		if ((node_b->cost_a > 0 && node_b->cost_b > 0)
			|| (node_b->cost_a < 0 && node_b->cost_b < 0))
			if (absolute(node_b->cost_a) >= absolute(node_b->cost_b))
				node_b->cost_total = absolute(node_b->cost_a);
		else
			node_b->cost_total = absolute(node_b->cost_b);
		else
			node_b->cost_total = absolute(node_b->cost_a)
				+ absolute(node_b->cost_b);
		node_b = node_b->next;
	}
}

void	find_cheapest(t_stack_node **b)
{
	t_stack_node	*node;
	t_stack_node	*cheapest;
	int				cost;

	cost = INT_MAX;
	node = *b;
	cheapest = *b;
	while (node)
	{
		if (node->cost_total < cost)
		{
			cost = node->cost_total;
			cheapest = node;
		}
		node = node->next;
	}
	cheapest->cheapest = true;
}
