/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaillan <esaillan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:47:06 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/13 11:58:33 by esaillan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	first_loop(t_stack *a, t_stack *b, t_result *res)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
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

static t_result	*parse_and_sort(t_stack *a)
{
	t_stack		*b;
	t_result	*res;
	int			j;

	b = init_stack_b(a->size);
	if (!b)
		return (NULL);
	res = init_result(a->size);
	if (!res)
		return (free(b->stack), free(b), NULL);
	j = first_loop(a, b, res);
	while (b->size > 0)
	{
		ft_operator(a, b, PA);
		ft_incr(res, &j, PA);
		ft_operator(a, b, RA);
		ft_incr(res, &j, RA);
	}
	res->nb = j;
	return (free(b->stack), free(b), res);
}

t_result	*simple_algo(t_stack *a)
{
	if (!a || !a->stack)
		return (NULL);
	if (is_sorted(a))
		return (NULL);
	return (parse_and_sort(a));
}
