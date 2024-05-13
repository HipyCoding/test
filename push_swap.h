/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:39:31 by candrese          #+#    #+#             */
/*   Updated: 2024/05/13 20:41:26 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
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
t_stack_node	*args (char **argv);
t_stack_node	*argsb ();//for testing
void			add_node (t_stack_node **stack, int nb);

//stack commands
void			sa(t_stack_node **stack_a, int print);
void			sb(t_stack_node **stack_a, int print);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b);
void			pa(t_stack_node **stack_b, t_stack_node **stack_a);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);
void			ra(t_stack_node **stack_a, int print);
void			rb(t_stack_node **stack_b, int print);
void			rr(t_stack_node **stack_b, t_stack_node **stack_a);
void			rra(t_stack_node **stack_a, int print);
void			rrb(t_stack_node **stack_b, int print);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b);


//utils
void		putstr_fd(char *s, int fd);
void		error_fd(int fd);
long		my_atolong(const char *s);
char		**ft_split(char const *s, char c);

#endif
