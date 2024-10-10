/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:58:29 by candrese          #+#    #+#             */
/*   Updated: 2024/10/10 02:36:37 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	do_operation(t_stack_node **a, t_stack_node **b, char *command)
{
	if (!ft_strncmp(command, "pb\n", 3))
		pb(a, b, 0);
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
		//printf ("b: %d", b->value);
		input = get_next_line(0);
	}
	
	return (0);
}
