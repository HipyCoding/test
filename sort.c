/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 04:39:03 by candrese          #+#    #+#             */
/*   Updated: 2024/06/16 10:49:55 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void fill_stack_b(t_stack_node **a, t_stack_node **b, int size)
{
	while (size > 3)
	{
		pb(a, b, 1);
		size--;
	}
	sort_3(a);
}

void	move_positive(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *node;

	node = *b;
	while (node && node->cheapest == false)
		node = node->next;
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		node->cost_a--;
		node->cost_b--;
		rr(a, b, 1);
	}
	while (node->cost_a > 0)
	{
		node->cost_a--;
		ra(a, 1);
	}
	while (node->cost_b > 0)
	{
		node->cost_b--;
		rb(b, 1);
	}
}


void	move_negative(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *node;

	node = *b;
	while (node && node->cheapest == false)
		node = node->next;
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		node->cost_a++;
		node->cost_b++;
		rrr(a, b, 1);
	}
	while (node->cost_a < 0)
	{
		node->cost_a++;
		rra(a, 1);
	}
	while (node->cost_b < 0)
	{
		node->cost_b++;
		rrb(b, 1);
	}
}

void	push_element_to_a(t_stack_node **a, t_stack_node **b)
{
	move_positive(a, b);
	move_negative(a, b);
	pa(b, a, 1);
}

void rotate(t_stack_node **a, int size)
{
	int i = 0;
	get_positions(*a);
	if (check_max(*a)->position > size / 2)
	{
		while (!check_if_sorted(*a) && i < 10)
		{
			i++;
			rra(a, 1);
		}
	}
	else 
	{
		while (!check_if_sorted(*a) && i < 10)
		{
			i++;
			ra(a, 1);
		}
	}
}

void	big_sort(t_stack_node **a, t_stack_node **b, int size)
{
	assign_index(*a, size);
	check_above_median(*a, size);
	fill_stack_b(a, b, size);
	while (*b)
	{
	get_positions(*a);
	get_positions(*b);
	get_target_positions(a, b);
	get_costs(b, check_size(*a), check_size(*b));
	find_cheapest(b);
	push_element_to_a(a, b);
	}
	rotate(a, size);
}
