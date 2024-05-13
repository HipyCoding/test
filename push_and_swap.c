/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:32:19 by candrese          #+#    #+#             */
/*   Updated: 2024/05/13 17:51:29 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a)
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
	putstr_fd("sa\n", STDERR_FILENO);
}

void	sb(t_stack_node **stack_b)
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
	putstr_fd("sa\n", STDERR_FILENO);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	putstr_fd("ss\n", STDERR_FILENO);
}
