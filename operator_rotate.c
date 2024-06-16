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
	t_stack_node	*end;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	temp = *stack_a;
	end = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	while (end->next != NULL)
		end = end->next;
	end->next = temp;
	temp->prev = end;
	temp->next = NULL;
	if (print)
		putstr_fd("ra\n", STDERR_FILENO);
}

void	rb(t_stack_node **stack_b, int print)
{
	t_stack_node  *temp;
	t_stack_node	*end;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	temp = *stack_b;
	end = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	while (end->next != NULL)
		end = end->next;
	end->next = temp;
	temp->prev = end;
	temp->next = NULL;
	if (print)
		putstr_fd("rb\n", STDERR_FILENO);
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print)
		putstr_fd("rr\n", STDERR_FILENO);
}
