/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_to_winit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:28:09 by candrese          #+#    #+#             */
/*   Updated: 2024/05/10 12:51:11 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi(const char *s)
{
	int	i;
	int	nb;
	int	pm;

	i = 0;
	nb = 0;
	pm = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pm = pm * (-1);
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - 48;
		i++;
	}
	return (nb * pm);
}

static void append_node(t_stack_node **)
