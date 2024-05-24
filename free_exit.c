/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:14:28 by candrese          #+#    #+#             */
/*   Updated: 2024/05/16 17:12:48 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_fd(int fd)
{
	write(fd, "Error\n", 6);
	exit(1);
}

void	free_and_exit(char **ptr, t_stack_node *stack, int	i)
{
	if (i == 0)
		free_2d_string(ptr);
	else if (i == 1)
		free_stack(stack);
	error_fd(STDERR_FILENO);
}

void	free_2d_string(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*temp;

	if (!stack)
		return;
	while (stack->prev != NULL)
		stack = stack->prev;
		temp = stack->next;
		free (stack);
		stack = temp;
	
}
