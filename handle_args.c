/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:20:03 by candrese          #+#    #+#             */
/*   Updated: 2024/05/13 01:26:12 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (a);
}
