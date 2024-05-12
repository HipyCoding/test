/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:20:03 by candrese          #+#    #+#             */
/*   Updated: 2024/05/12 20:51:31 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *args (char **argv)
{
	int				i;
	t_stack_node 	*a;
	char			**values;
	
	i = 0;
	a = NULL;
	values = ft_split(argv[1], ' ');
	while (values[i])
	{
		add_node(&a, my_atolong(values[i]));
		i++;
	}
	return (a);
}
