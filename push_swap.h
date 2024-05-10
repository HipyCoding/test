/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:39:31 by candrese          #+#    #+#             */
/*   Updated: 2024/05/10 12:50:55 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>

typedef struct s_stack_node
{
	int						nbr;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;


#endif
