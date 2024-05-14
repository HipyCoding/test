/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:32:10 by candrese          #+#    #+#             */
/*   Updated: 2024/05/14 21:29:03 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **stack_a, int print)
{
	t_stack_node  *temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	temp = *stack_a;
	(*stack_a)->next->prev = NULL;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp->prev = *stack_a;
	temp->next = NULL;
	if (print)
		putstr_fd("rra\n", STDERR_FILENO);
}

void	rrb(t_stack_node **stack_b, int print)
{
	t_stack_node  *temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	temp = *stack_b;
	(*stack_b)->next->prev = NULL;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = temp;
	temp->prev = *stack_b;
	temp->next = NULL;
	if (print)
		putstr_fd("rrb\n", STDERR_FILENO);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	putstr_fd("rrr\n", STDERR_FILENO);
}
