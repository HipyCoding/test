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

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!*stack || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->next = NULL;
	temp->next->prev = temp;
}	

void	ra(t_stack_node **a, int print)
{
	rotate(a);
	if (print)
		putstr_fd("ra\n",1);
}

void	rb(t_stack_node **b, int print)
{
	rotate(b);
	if (print)
		putstr_fd("rb\n",1);
}

void	rr(t_stack_node **a, t_stack_node **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		putstr_fd("rr\n",1);
}
