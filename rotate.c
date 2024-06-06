 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:08:59 by candrese          #+#    #+#             */
/*   Updated: 2024/05/14 21:29:11 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack_node **stack_a, int print)
{
	t_stack_node  *temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	temp = *stack_a;
	(*stack_a)->next->prev = NULL;
	*stack_a = (*stack_a)->next;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp->prev = *stack_a;
	temp->next = NULL;
	while ((*stack_a)->prev != NULL )
		*stack_a = (*stack_a)->prev;
	if (print)
		putstr_fd("ra\n", STDERR_FILENO);
}

void	rb(t_stack_node **stack_b, int print)
{
	t_stack_node  *temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	temp = *stack_b;
	(*stack_b)->next->prev = NULL;
	*stack_b = (*stack_b)->next;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = temp;
	temp->prev = *stack_b;
	temp->next = NULL;
	while ((*stack_b)->prev != NULL )
		*stack_b = (*stack_b)->prev;
	if (print)
		putstr_fd("rb\n", STDERR_FILENO);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	putstr_fd("rr\n", STDERR_FILENO);
}
