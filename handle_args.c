/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:20:03 by candrese          #+#    #+#             */
/*   Updated: 2024/05/25 05:47:27 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dup_check(t_stack_node *stack, int *error)
{
	t_stack_node	*check;
	t_stack_node	*node;

	if (!stack)
	{
		*error = 1;
		return;
	}
	check = NULL;
	node = stack;
	while (node != NULL)
	{
		check = node->next;
		while (check != NULL)
		{
			if (node->value == check->value)
			{
				*error = 1;
				return;
			}
			check = check->next;
		}
		node = node->next;
	}
}

t_stack_node	*read_args(int argc, char **argv)
{
	t_stack_node	*a;
	int				i;
	int				error;

	error = 0;
	i = 1;
	a = NULL;
	if (argc == 2)
	{
		i = 0;
		argv = ft_split(argv[1], ' ');
		if (!argv)
			free_and_exit(NULL, a, 1);
	}
	while (argv[i])
		add_node(&a, my_atolong(argv[i++], &error));
	if (argc == 2)
		free_2d_string(argv);
	dup_check(a, &error);
	if (error == 1)
		free_and_exit(NULL, a, 1);
	return (a);
}

//initializes b stack for testing
// t_stack_node *argsb ()
// {
// 	t_stack_node 	*b;
// 	int	i = 10;

// 	b = NULL;
// 	while(i<15)
// 	{
// 		add_node(&b, i++);
// 	}
// 	dup_check(b);
// 	return (b);
// }
