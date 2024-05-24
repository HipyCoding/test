/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:20:03 by candrese          #+#    #+#             */
/*   Updated: 2024/05/24 17:11:16 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dup_check(t_stack_node *stack)
{
	t_stack_node	*check;
	t_stack_node	*node;

	if (!stack)
		free_and_exit(NULL, stack, 1);
	check = NULL;
	node = stack;
	while (node != NULL)
	{
		check = node->next;
		while (check != NULL)
		{
			if (node->value == check->value)
				free_and_exit(NULL, stack, 1);
			check = check->next;
		}
		node = node->next;
	}
}

t_stack_node *read_args (int argc, char **argv)
{
	t_stack_node 	*a;
	int				i;
	
	i = 0;
	a = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			free_and_exit(NULL, a, 1);
		while (argv[i])
			add_node(&a, my_atolong(argv[i++]));
		free_2d_string(argv);
	}
	else if (argc > 2)
	{
		argv++;
		while (*argv)
			add_node(&a, my_atolong(*(argv++)));
	}
	dup_check(a);
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
