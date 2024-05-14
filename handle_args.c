/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:20:03 by candrese          #+#    #+#             */
/*   Updated: 2024/05/14 21:21:56 by candrese         ###   ########.fr       */
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

t_stack_node *args (char **argv)
{
	t_stack_node 	*a;
	char			**values;
	int				i;
	
	i = 0;
	argv++;
	a = NULL;
	while(*argv)
	{
		values = ft_split(*argv, ' ');
		if (!values)
			free_and_exit(NULL, a, 1);
		while (values[i])
		{
			add_node(&a, my_atolong(values[i]));
			i++;
		}
		free_2d_string(values);
		argv++;
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
