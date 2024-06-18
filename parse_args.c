/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:20:03 by candrese          #+#    #+#             */
/*   Updated: 2024/06/18 06:04:45 by candrese         ###   ########.fr       */
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

void	add_node (t_stack_node **stack, int value)
{
	t_stack_node *new;
	t_stack_node *prev;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return;
	new->next = NULL;
	new->value = value;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		prev = *stack;
		while (prev->next != NULL)
			prev = prev ->next;
		prev->next = new;
		new->prev = prev;
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
			free_and_exit(NULL, &a, 1);
	}
	while (argv[i])
		add_node(&a, my_atolong(argv[i++], &error));
	if (argc == 2)
		free_2d_string(argv);
	dup_check(a, &error);
	if (error == 1)
		free_and_exit(NULL, &a, 11);
	return (a);
}
