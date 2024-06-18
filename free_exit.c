/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:14:28 by candrese          #+#    #+#             */
/*   Updated: 2024/06/18 08:26:16 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_fd(int fd)
{
	write(fd, "Error\n", 6);
	exit(1);
}

void	free_and_exit(char **ptr, t_stack_node **stack, int i)
{
	if (i == 0 || i == 10 || i == 20)
		free_2d_string(ptr);
	else if (i == 1 || i == 11 || i == 21)
		free_stack(stack);
	else if (i == 2 || i == 12 || i == 22)
	{
		free_2d_string(ptr);
		free_stack(stack);
	}
	if (i >= 10 && i <= 12)
		error_fd(STDERR_FILENO);
	else if (i >= 20 && i <= 22)
		exit(0);
}

void	free_2d_string(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*node;
	t_stack_node	*to_free;

	if (!stack)
		return ;
	to_free = *stack;
	while (to_free)
	{
		node = to_free->next;
		free (to_free);
		to_free = node;
	}
	*stack = NULL;
}
