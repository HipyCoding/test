/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:45:39 by candrese          #+#    #+#             */
/*   Updated: 2024/05/10 12:50:07 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//declare pointers to two data structs, stack a and b

//handle input count errors. argument count must be 2 or more, and the second input must not be empty

//handle inpus as variable number of command line arguments or as a string (split)

//initialize stack a by appending each input number as a node to stack a
//	handle integer overflow, dublicates and syntax errors (only digits, + -)
//	check input if long integer
//		if the input is a string, convert to long integer
//	append the nodes to stack a

//check if stack a is sorted
//	if not , implement sorting algorithm
//		check for 2 numbers
//			if so simply swap the numbers
//		check for 3 numbers
//			if so implement our simple sort three algorithm
//		check for more than 3 numbers
//			if so, implement sorting algorithm

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split (argv[1], ' ');
// init stack
	
	free_stack(&a);
	return (0);
}
