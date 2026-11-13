/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:47:06 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/11 14:04:42 by habretag         ###   ########lyon.fr   */
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
				ft_sa(a);
				res->ope[j++] = SA;
			}
			ft_ra(a);
			res->ope[j++] = RA;
			i++;
		}
		ft_pb(a, b, res, &j);
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
		ft_pa(a, b, res, &j);
		ft_ra(a);
		res->ope[j++] = RA;
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
