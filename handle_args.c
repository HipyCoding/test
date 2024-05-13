/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:20:03 by candrese          #+#    #+#             */
/*   Updated: 2024/05/13 18:49:45 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	dup_check(t_stack_node *stack)
{
	t_stack_node	*check;
	t_stack_node	*node;

	check = NULL;
	node = stack;
	while (node != NULL)
	{
		check = node->next;
		while (check != NULL)
		{
			if (node->value == check->value)
				error_fd(STDERR_FILENO);
			check = check->next;
		}
		node = node->next;
	}
}

t_stack_node *args (char **argv)
{
	t_stack_node 	*a;
	char			**values;
	
	argv++;
	a = NULL;
	values = ft_split(*argv, ' ');
	while(*argv)
	{
		values = ft_split(*argv, ' ');
		while (*values)
		{
			add_node(&a, my_atolong(*values));
			values++;
		}
		argv++;
	}
	dup_check(a);
	return (a);
}

//initializes b stack for testing
t_stack_node *argsb ()
{
	t_stack_node 	*b;
	int	i = 10;
	
	b = NULL;
	while(i<15)
	{
		add_node(&b, i++);
	}
	dup_check(b);
	return (b);
}
