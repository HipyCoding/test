/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:32:19 by candrese          #+#    #+#             */
/*   Updated: 2024/06/10 18:23:39 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a, int print)
{
	t_stack_node  *temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	temp->next  = (*stack_a)->next;
	temp->prev = *stack_a;
	(*stack_a)->next = temp;
	if (print == 1)
		putstr_fd("sa\n", STDERR_FILENO);
}

void	sb(t_stack_node **stack_b, int print)
{
	t_stack_node  *temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	temp->next  = (*stack_b)->next;
	temp->prev = *stack_b;
	(*stack_b)->next = temp;
	if (print == 1)
		putstr_fd("sb\n", STDERR_FILENO);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print)
		putstr_fd("ss\n", STDERR_FILENO);
}

// (src	-> dest);

void	pa(t_stack_node **stack_b, t_stack_node **stack_a, int print)
{
	t_stack_node *temp;

	if (!*stack_b)
		return;
	temp = *stack_b;
	if ((*stack_b)->next != NULL)
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
	}
	else
		*stack_b = NULL;
	if (*stack_a)
	{
		temp->next = *stack_a;
		(*stack_a)->prev = temp;
	}
	else
		temp->next = NULL;
	temp->prev = NULL;
	*stack_a = temp;
	if (print)
		putstr_fd("pa\n", STDERR_FILENO);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b, int print)
{
	t_stack_node *temp;

	if (!*stack_a)
		return;
	temp = *stack_a;
	if ((*stack_a)->next != NULL)
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
	}
	else
		*stack_a = NULL;
	if (*stack_b)
	{
		temp->next = *stack_b;
		(*stack_b)->prev = temp;
	}
	else
		temp->next = NULL;
	temp->prev = NULL;
	(*stack_b) = temp;
	if (print)
		putstr_fd("pb\n", STDERR_FILENO);
}
