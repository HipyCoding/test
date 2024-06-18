/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 05:38:39 by candrese          #+#    #+#             */
/*   Updated: 2024/06/18 09:13:11 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*node;
	t_stack_node	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	node = *stack;
	temp = node->next;
	temp->prev = NULL;
	node->next = temp->next;
	temp->next = node;
	node->prev = temp;
	*stack = temp;
	if (node->next)
		node->next->prev = node;
}

void	sa(t_stack_node **a, int print)
{
	swap(a);
	if (print)
		putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **b, int print)
{
	swap(b);
	if (print)
		putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **a, t_stack_node **b, int print)
{
	swap(a);
	swap(b);
	if (print)
		putstr_fd("ss\n", 1);
}
