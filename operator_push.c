/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 07:32:19 by candrese          #+#    #+#             */
/*   Updated: 2024/06/18 06:02:36 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*node;

	if (!*src)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->next = *dst;
	if (*dst)
		(*dst)->prev = node;
	*dst = node;
}

void	pb(t_stack_node **a, t_stack_node **b, int print)
{
	push(a, b);
	if (print)
		putstr_fd("pb\n",1);
}

void	pa(t_stack_node **b, t_stack_node **a, int print)
{
	push(b, a);
	if (print)
		putstr_fd("pa\n",1);
}
