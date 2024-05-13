/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:51:19 by candrese          #+#    #+#             */
/*   Updated: 2024/05/13 02:09:14 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	my_atolong(const char *s)
{
	long int	nb;
	int			pm;
	
	nb = 0;
	pm = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			pm = pm * (-1);
		s++;
	}
	while (*s != '\0' && *s >= '0' && *s <= '9')
	{
		nb = (nb * 10) + *s - '0';
		s++;
	}
	if (nb * pm > INT_MAX || nb * pm < INT_MIN || *(s - 1) < '0' || *(s - 1) > '9')
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

