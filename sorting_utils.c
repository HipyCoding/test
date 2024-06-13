/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:55:10 by candrese          #+#    #+#             */
/*   Updated: 2024/06/13 05:23:04 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void assign_index(t_stack_node *stack)
{
	int				i;
	int				min;
	int				s_size;

	i = 0;
	s_size = check_size(stack);
	while (i < s_size)
	{
		min = next_bigger(stack, min);
		while (stack->prev)
			stack = stack->prev;
		while (stack->next)
		{
			if (stack->value == min)
			{
				stack->index = i;
				i++;
				break ;
			}
			stack = stack->next;
		}
	}
	while (stack->prev)
		stack = stack->prev;
}
