/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:06:32 by habretag          #+#    #+#             */
/*   Updated: 2026/11/12 17:18:40 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	distribute_buckets(t_stack *a, t_stack *b, t_result *res)
{
	t_bucket	bucket;
	int			count;
	int			size;
	int			total_size;
	int			i;

	total_size = a->size;
	count = get_bucket_count(total_size);
	size = get_bucket_size(total_size, count);
	i = 0;
	while (i < count)
	{
		bucket.min = i * size;
		bucket.max = bucket.min + size - 1;
		if (bucket.max >= total_size)
			bucket.max = total_size - 1;
		push_bucket(a, b, res, bucket);
		i++;
	}
}

t_result	*medium_algo(t_stack *a)
{
	t_stack		*rank_a;
	t_stack		*b;
	t_result	*res;
	int			*normalized;

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
		return (free(rank_a->stack), free(rank_a),
			free(b->stack), free(b), NULL);
	distribute_buckets(rank_a, b, res);
	collect_stack(rank_a, b, res);
	free(rank_a->stack);
	free(rank_a);
	free(b->stack);
	free(b);
	return (res);
}
