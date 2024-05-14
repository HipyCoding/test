/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:51:19 by candrese          #+#    #+#             */
/*   Updated: 2024/05/14 21:13:36 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atolong(const char *s)
{
	long int	nb;
	int			pm;
	
	nb = 0;
	pm = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			pm = pm * (-1);
		s++;
	}
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		nb = (nb * 10) + *s - '0';
		s++;
	}
	if (nb * pm > INT_MAX || nb * pm < INT_MIN || *(s - 1) < '0' || *(s - 1) > '9')
		error_fd(STDERR_FILENO);
	return (nb * pm);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

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
	while (stack)
	{
		temp = stack->next;
		free (stack);
		stack = temp;
	}
}
