/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:51:19 by candrese          #+#    #+#             */
/*   Updated: 2024/05/12 22:12:12 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atolong(const char *s)
{
	int			i;
	long int	nb;
	int			pm;

	i = 0;
	nb = 0;
	pm = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			pm = pm * (-1);
		i++;
	}
	while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
	{
		nb = (nb * 10) + s[i] - '0';
		i++;
	}
	if (nb * pm > INT_MAX || nb * pm < INT_MIN || s[i] < '0' || s[i] > '9')
		error_fd(STDERR_FILENO);
	return (nb * pm);
}

void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

void	error_fd(int fd)
{
	write(fd, "Error\n", 6);
	exit(1);
}

