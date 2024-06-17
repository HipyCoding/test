/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:32:10 by candrese          #+#    #+#             */
/*   Updated: 2024/06/17 00:30:53 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **stack_a, int print)
{
	t_stack_node  *temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	temp = *stack_a;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = temp;
	(*stack_a)->prev->next = NULL;
	temp->prev = *stack_a;
	(*stack_a)->prev = NULL;
	if (print)
		putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **stack_b, int print)
{
	t_stack_node  *temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	temp = *stack_b;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = temp;
	(*stack_b)->prev->next = NULL;
	temp->prev = *stack_b;
	(*stack_b)->prev = NULL;
	if (print)
		putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print)
		putstr_fd("rrr\n", 1);
}
