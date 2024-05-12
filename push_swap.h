/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:39:31 by candrese          #+#    #+#             */
/*   Updated: 2024/05/12 20:50:44 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int						value;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

//stack handling
t_stack_node 	*args (char **argv);
void			add_node (t_stack_node **stack, int nb);

//utils
void		putstr_fd(char *s, int fd);
void		error_fd(int fd);
long		my_atolong(const char *s);
char		**ft_split(char const *s, char c);

#endif
