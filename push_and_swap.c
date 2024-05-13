/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:32:19 by candrese          #+#    #+#             */
/*   Updated: 2024/05/13 08:07:49 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a)
{
	int temp;

	temp = 0;
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return;
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	temp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->prev->value;
	(*stack_a)->prev->value = temp;
	putstr_fd("sa\n", STDERR_FILENO);
}

void	sb(t_stack_node **stack_b)
{
	int temp;

	temp = 0;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return;
	while ((*stack_b)->next != NULL)
		*stack_b = (*stack_b)->next;
	temp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->prev->value;
	(*stack_b)->prev->value = temp;
	putstr_fd("sb\n", STDERR_FILENO);
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	putstr_fd("ss\n", STDERR_FILENO);
}
