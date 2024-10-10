/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 01:58:29 by candrese          #+#    #+#             */
/*   Updated: 2024/10/10 02:17:23 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
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
		printf("%s",input);
		input = get_next_line(0);
	}
	
	return (0);
}
