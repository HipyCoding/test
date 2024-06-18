/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_rev_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:32:10 by candrese          #+#    #+#             */
/*   Updated: 2024/06/18 08:30:00 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	t_stack_node	*temp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	*stack = temp;
	temp->next->prev = temp;
}

void	rra(t_stack_node **a, int print)
{
	rev_rotate(a);
	if (print)
		putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **b, int print)
{
	rev_rotate(b);
	if (print)
		putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		putstr_fd("rrr\n", 1);
}
