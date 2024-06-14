/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 06:04:06 by candrese          #+#    #+#             */
/*   Updated: 2024/06/14 20:29:05 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(t_stack_node *stack)
{
	if (!stack)
		return;
	while (stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			stack = stack->next;
		else
			return;
	}
	free_stack (stack);
	exit(EXIT_SUCCESS);
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
