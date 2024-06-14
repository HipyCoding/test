/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 02:55:10 by candrese          #+#    #+#             */
/*   Updated: 2024/06/14 20:39:16 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void assign_index(t_stack_node *stack, int size)
{
	int				i;
	int				min;
	t_stack_node	*temp;

	if (!stack)
		return;
	i = 0;
	min = INT_MIN;
	while (i < size)
	{
		min = next_bigger(stack, min);
		temp = stack;
		while (temp)
		{
			if (temp->value == min)
			{
				temp->index = i;
				i++;
				break ;
			}
			temp = temp->next;
		}
	}
}
