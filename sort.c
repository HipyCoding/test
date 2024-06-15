/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 04:39:03 by candrese          #+#    #+#             */
/*   Updated: 2024/06/15 20:49:34 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack_b(t_stack_node *a, t_stack_node *b, int size)
{
	while (size > 3)
	{
		pb(&a, &b, 0);
		size--;
	}
	sort_3(a);
	get_positions(a);
	get_positions(b);
}

void	big_sort(t_stack_node *a, t_stack_node *b, int size)
{
	check_above_median(a, size);
	assign_index(a, size);
	fill_stack_b(a, b, size);
	
}
