/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:45:39 by candrese          #+#    #+#             */
/*   Updated: 2024/06/16 01:44:18 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdbool.h>

// void	memory_leaks(void)
// {
// 	system("leaks push_swap");
// }

void	sort_3(t_stack_node **a)
{
	t_stack_node	*node;

	if (!*a)
		return;
	node = *a;
	if (check_max(*a)->value == node->value)
		ra(a,1);
	else if (check_max(*a)->value == node->next->value)
		rra(a,1);
	if (!check_if_sorted(*a))
		sa(a,1);
	while ((*a)->prev)
		*a = (*a)->prev;
}

void	sort_stack(t_stack_node **a, t_stack_node **b, int size)
{
	if (size == 2)
		sa(a , 1);
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

	// atexit(memory_leaks);
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = read_args(argc, argv);
	// b = argsb(b);
	if (check_if_sorted(a))
		free_and_exit(NULL, a, 1);
	size = check_size(a);
	sort_stack(&a, &b, size);
	//sa(&a, 1);

// for testing and debugging

	// // stack a
	// while (a->prev)
	// 	a=a->prev;
	// while (a->next)
	// {
	// 	printf("%d[%d](%d)|%d| ", a->value, a->index, a->position, a->above_median);
	// 	a = a->next;
	// }
	// printf("%d[%d](%d)|%d| \n", a->value, a->index, a->position, a->above_median);

	// // stack b
	// // while (b->prev)
	// // 	b=b->prev;
	// while (b->next)
	// {
	// 	printf("%d[%d](%d)|%d| ", b->value, b->index, b->position, b->above_median);
	// 	b = b->next;
	// }
	// printf("%d[%d](%d)|%d| \n", b->value, b->index, b->position, b->above_median);
	free_stack(a);
	free_stack(b);
	return (0);
}
