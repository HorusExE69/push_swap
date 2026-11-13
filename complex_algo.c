/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaillan <esaillan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 00:00:00 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/13 15:33:02 by esaillan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_bit(t_stack *a, t_stack *b, t_result *res, int bit)
{
	int	i;
	int	count;
	int	index;

	count = a->size;
	i = 0;
	index = res->nb;
	while (i++ < count)
	{
		if ((a->stack[0] >> bit) & 1)
		{
			ft_operator(a, b, RA);
			ft_incr(res, &index, RA);
		}
		else
		{
			ft_operator(a, b, PB);
			ft_incr(res, &index, PB);
		}
	}
	while (b->size > 0)
	{
		ft_operator(a, b, PA);
		ft_incr(res, &index, PA);
	}
}

static t_result	*radix_sort(t_stack *a)
{
	t_stack		*rank_a;
	t_stack		*b;
	t_result	*res;
	int			*normalized;
	int			bit;

	normalized = normalize_stack(a);
	if (!normalized)
		return (NULL);
	rank_a = init_rank_stack(normalized, a->size);
	if (!rank_a)
		return (free(normalized), NULL);
	b = init_stack_b(a->size);
	if (!b)
		return (free(rank_a->stack), free(rank_a), NULL);
	res = init_result(a->size);
	if (!res)
		return (free(b->stack), free(b), free(rank_a->stack),
			free(rank_a), NULL);
	bit = 0;
	while ((a->size - 1) >> bit)
		sort_bit(rank_a, b, res, bit++);
	return (free(b->stack), free(b), free(rank_a->stack),
		free(rank_a), res);
}

t_result	*complex_algo(t_stack *a)
{
	if (!a || !a->stack)
		return (NULL);
	if (is_sorted(a))
		return (NULL);
	return (radix_sort(a));
}
