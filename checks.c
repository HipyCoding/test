/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 06:04:06 by candrese          #+#    #+#             */
/*   Updated: 2024/06/15 22:56:56 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_if_sorted(t_stack_node *stack)
{
	if (!stack)
		error_fd(STDERR_FILENO);
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int		check_size(t_stack_node *stack)
{
	int	size;

	size = 1;
	if (!stack)
		return (0);
	while (stack->next)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack_node *check_max(t_stack_node *stack)
{
	t_stack_node *max;
	t_stack_node *node;

	max = stack;
	node = stack;

	while (node->next)
	{
		node = node->next;
		if (node->value > max->value)
			max = node;
	}
	return (max);
}

void check_above_median(t_stack_node *stack, int size)
{
	t_stack_node *node;
	int median_index;

	median_index = size / 2;
	node = stack;
	while (node)
	{
		if (node->index > median_index)
			node->above_median = true;
		else
			node->above_median = false;
		node = node->next;
	}
}

int 	next_bigger(t_stack_node *stack, int nb)
{
	int				min;
	bool			new;
	t_stack_node	*node;

	min = INT_MAX;
	new = false;
	node = stack;
	while (node)
	{
		if (node->value > nb && node->value < min)
		{
			min = node->value;
			new = true;
		}
		node = node->next;
	}
	if (new)
		return (min);
	else
		return (INT_MAX);
}
