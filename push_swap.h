/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:39:31 by candrese          #+#    #+#             */
/*   Updated: 2024/10/10 02:23:24 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int						value;
	int						index;
	int						position;
	int						target_position;
	int						cost_a;
	int						cost_b;
	int						cost_total;
	bool					above_median;
	bool					cheapest;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}	t_stack_node;

//parse_args
t_stack_node	*read_args(int argc, char **argv);
void			add_node(t_stack_node **stack, int nb);
void			assign_index(t_stack_node **stack, int size);

//stack operators
void			sa(t_stack_node **stack_a, int print);
void			sb(t_stack_node **stack_a, int print);
void			ss(t_stack_node **stack_a, t_stack_node **stack_b, int print);
void			pa(t_stack_node **stack_b, t_stack_node **stack_a, int print);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b, int print);
void			ra(t_stack_node **stack_a, int print);
void			rb(t_stack_node **stack_b, int print);
void			rr(t_stack_node **stack_b, t_stack_node **stack_a, int print);
void			rra(t_stack_node **stack_a, int print);
void			rrb(t_stack_node **stack_b, int print);
void			rrr(t_stack_node **stack_a, t_stack_node **stack_b, int print);

//main
void			sort_3(t_stack_node **a);
void			big_sort(t_stack_node **a, t_stack_node **b, int size);

//utils
void			putstr_fd(char *s, int fd);
long long		my_atolong(const char *s, int *error);
char			**ft_split(char const *s, char c);
int				absolute(int nb);
void			*ft_calloc(size_t count, size_t size);
int	ft_strncmp	(const char *s1, const char *s2, size_t n);

//free and exit
void			error_fd(int fd);
void			free_2d_string(char **ptr);
void			free_stack(t_stack_node **stack);
void			free_and_exit(char **ptr, t_stack_node **stack, int i);

//sort
void			fill_stack_b(t_stack_node **a, t_stack_node **b, int size);
void			push_element_to_a(t_stack_node **a, t_stack_node **b);
void			rotate_until_sorted(t_stack_node **a, int size);

//sorting utils
void			get_positions(t_stack_node *stack);
void			get_target_positions(t_stack_node **a, t_stack_node **b);
void			get_costs(t_stack_node **a, int size_a, int size_b);
void			find_cheapest(t_stack_node **stack);

//checks
int				check_if_sorted(t_stack_node *stack);
int				check_size(t_stack_node *stack);
t_stack_node	*check_max(t_stack_node *stack);
int				next_bigger(t_stack_node *stack, long int nb);
void			check_above_median(t_stack_node **stack, int size);

#endif
