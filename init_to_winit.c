/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_winit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:55:02 by candrese          #+#    #+#             */
/*   Updated: 2024/05/14 22:49:52 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node (t_stack_node **stack, int value)
{
	t_stack_node *new;
	t_stack_node *prev;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return;
	new->next = NULL;
	new->value = value;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		prev = *stack;
		while (prev->next != NULL)
			prev = prev ->next;
		prev->next = new;
		new->prev = prev;
	}
}

