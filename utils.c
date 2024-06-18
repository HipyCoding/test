/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candrese <candrese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:51:19 by candrese          #+#    #+#             */
/*   Updated: 2024/06/18 07:10:39 by candrese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	my_atolong(const char *s, int *error)
{
	long long int	nb;
	int				pm;

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
	if (nb * pm > INT_MAX || nb * pm < INT_MIN || *s != '\0')
		*error = 1;
	return (nb * pm);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int		absolute (int nb)
{
	if (nb < 0)
		nb = nb * (-1);
	return (nb);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	str = (void *)malloc(count * size);
	if (str)
	{
		while (i < count * size)
		{
			*(char *)(str + i) = 0;
			i++;
		}
	}
	return (str);
}
