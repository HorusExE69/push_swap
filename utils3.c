/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaillan <esaillan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:25:20 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/16 14:02:11 by esaillan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	s;
	int	res;
	int	i;

	s = 1;
	res = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * s);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	grow_result(t_result *res)
{
	t_operators	*new_ope;
	int			new_capacity;

	new_capacity = 16;
	if (res->nb > 0)
	{
		if (res->nb > INT_MAX / 2)
			return (0);
		new_capacity = res->nb * 2;
	}
	if ((size_t)new_capacity > (size_t)-1 / sizeof(t_operators))
		return (0);
	new_ope = ft_realloc(res->ope,
			(size_t)res->nb * sizeof(t_operators),
			(size_t)new_capacity * sizeof(t_operators));
	if (!new_ope)
		return (0);
	res->ope = new_ope;
	return (1);
}

void	ft_incr(t_result *res, int *j, t_operators operator)
{
	if (res->nb < 0)
		return ;
	if ((res->nb == 0 || (res->nb >= 16
				&& (res->nb & (res->nb - 1)) == 0)) && !grow_result(res))
	{
		res->nb = -1;
		return ;
	}
	res->ope[(*j)++] = operator;
	res->nb++;
}
