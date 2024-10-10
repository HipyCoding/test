/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:58:29 by candrese          #+#    #+#             */
/*   Updated: 2024/10/10 02:50:19 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	do_operation(t_stack_node **a, t_stack_node **b, char *command)
{
	if (!ft_strncmp(command, "pb\n", 3))
		pb(a, b, 0);
	else if (!ft_strncmp(command, "pa\n", 3))
		pa(b, a, 0);
	else if (!ft_strncmp(command, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(command, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(command, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(command, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(command, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rrr(a, b, 0);
	else
		error_fd(1);
}

int		main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*input;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = read_args(argc, argv);
	input = get_next_line(0);
	while (input)
	{
		do_operation(&a, &b, input);
	// while (a->prev)
	// 	a=a->prev;
	// while (a->next)
	// {
	// 	printf("%d\n", a->value);
	// 	a = a->next;
	// }
	// printf("%d\n", a->value);
		//printf ("b: %d", b->value);
		input = get_next_line(0);
	}
	
	return (0);
}
