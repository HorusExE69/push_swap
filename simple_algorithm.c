/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:47:06 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/18 17:57:25 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	loop(t_stack *a, t_stack *b, t_result *res)
{
	int	i;
	int	j;

	j = 0;
	while (a->size > 1)
	{
		i = 0;
		while (i < a->size - 1)
		{
			if (a->stack[0] > a->stack[1])
			{
				ft_operator(a, b, SA);
				ft_incr(res, &j, SA);
			}
			ft_operator(a, b, RA);
			ft_incr(res, &j, RA);
			i++;
		}
		ft_operator(a, b, PB);
		ft_incr(res, &j, PB);
	}
	return (j);
}

static t_result	*bubble_sort(t_stack *a)
{
	t_stack		*b;
	t_result	*res;
	int			j;

	b = init_stack_b(a->size);
	res = init_result();
	if (!b || !res)
		return (clean_exit(NULL, b, res, NULL));
	j = loop(a, b, res);
	while (b->size > 0)
	{
		ft_operator(a, b, PA);
		ft_incr(res, &j, PA);
		ft_operator(a, b, RA);
		ft_incr(res, &j, RA);
	}
	if (res->operation_count < 0)
		return (clean_exit(NULL, b, res, NULL));
	return (clean_exit(NULL, b, res, res));
}

t_result	*simple_algo(t_stack *a)
{
	if (!a || !a->stack)
		return (NULL);
	if (is_sorted(a))
		return (NULL);
	return (bubble_sort(a));
}
