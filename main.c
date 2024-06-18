/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:45:39 by candrese          #+#    #+#             */
/*   Updated: 2024/06/18 09:12:40 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdbool.h>

// for leak checking in github codespace:
// valgrind --leak-check=full --show-reachable=yes 
// --track-origins=yes -s ./push_swap

// void	memory_leaks(void)
// {
// 	system("leaks push_swap");
// }

// atexit(memory_leaks);

void	big_sort(t_stack_node **a, t_stack_node **b, int size)
{
	assign_index(a, size);
	check_above_median(a, size);
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
	rotate_until_sorted(a, size);
}

void	sort_3(t_stack_node **a)
{
	if (!*a)
		return ;
	if (!check_if_sorted(*a))
	{
		if (check_max(*a)->value == (*a)->value)
			ra(a, 1);
		else if (check_max(*a)->value == (*a)->next->value)
			rra(a, 1);
		if (!check_if_sorted(*a))
			sa(a, 1);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b, int size)
{
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_3(a);
	else
		big_sort(a, b, size);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				size;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = read_args(argc, argv);
	if (check_if_sorted(a))
		free_and_exit(NULL, &a, 21);
	size = check_size(a);
	sort_stack(&a, &b, size);
	free_stack(&a);
	free_stack(&b);
	return (0);
}

	// while (a->prev)
	// 	a=a->prev;
	// while (a->next)
	// {
	// 	printf("%d ", a->value);
	// 	a = a->next;
	// }
	// printf("%d\n", a->value);
