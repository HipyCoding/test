/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:45:39 by candrese          #+#    #+#             */
/*   Updated: 2024/06/10 18:28:06 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	memory_leaks(void)
{
	system("leaks push_swap");
}

void	sort_3(t_stack_node *a)
{
	t_stack_node	*node;

	if (!a)
		return;
	node = a;
	if (check_max(a)->value == node->value)
		ra(&a,1);
	else if (check_max(a)->value == node->next->value)
		rra(&a,1);
	check_if_sorted(a);
	sa(&a,1);
}

void	sort_stack(t_stack_node *a)
{
	if (check_size(a) == 2)
		sa(&a , 1);
	else if (check_size(a) == 3)
		sort_3(a);
	// else
	// 	sorting_algorithm
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	atexit(memory_leaks);
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = read_args(argc, argv);
	// b = argsb(b);
	// check_if_sorted(a);
	// sort_stack(a);
	// printf("%i\n",check_max(a)->value);
	//sa(&a, 1);

// for testing and debugging

	// // stack a
	// while (a->prev != NULL)
	// 	a=a->prev;
	// while (a->next != NULL)
	// {
	// 	printf("%d ", a->value);
	// 	a = a->next;
	// }
	// printf("%d\n", a->value);

	// stack b
	while (b->prev != NULL)
		b=b->prev;
	while (b->next != NULL)
	{
		printf("%d ", b->value);
		b = b->next;
	}
	printf("%d\n", b->value);
	free_stack(a);
	free_stack(b);
	return (0);
}
