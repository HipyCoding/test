/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:32:19 by candrese          #+#    #+#             */
/*   Updated: 2024/05/13 20:28:46 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a, int print)
{
	t_stack_node  *temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	temp = *stack_a;
	*stack_a = (*stack_a)->prev;
	(*stack_a)->prev->next = temp;
	temp->prev = (*stack_a)->prev;
	(*stack_a)->prev = temp;
	(*stack_a)->next = NULL;
	temp->next = (*stack_a);
	if (print)
		putstr_fd("rb\n", STDERR_FILENO);
}

void	sb(t_stack_node **stack_b, int print)
{
	t_stack_node  *temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	temp = *stack_b;
	*stack_b = (*stack_b)->prev;
	(*stack_b)->prev->next = temp;
	temp->prev = (*stack_b)->prev;
	(*stack_b)->prev = temp;
	(*stack_b)->next = NULL;
	temp->next = (*stack_b);
	if (print)
		putstr_fd("rb\n", STDERR_FILENO);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	putstr_fd("ss\n", STDERR_FILENO);
}

void	pa(t_stack_node **stack_b, t_stack_node **stack_a)
{
	t_stack_node *temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	temp = *stack_b;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_b)->prev->next = NULL;
	(*stack_b)->prev = *stack_a;
	(*stack_a)->next = *stack_b;
	*stack_b = temp;
	putstr_fd("pa\n", STDERR_FILENO);
}

void	pb(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node *temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	temp = *stack_a;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->prev->next = NULL;
	(*stack_a)->prev = *stack_b;
	(*stack_b)->next = (*stack_a);
	*stack_a = temp;
	putstr_fd("pb\n", STDERR_FILENO);
}
