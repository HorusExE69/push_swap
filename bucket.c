/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:18:59 by habretag          #+#    #+#             */
/*   Updated: 2026/11/12 17:18:56 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bucket_count(int size)
{
	int	count;

	count = 0;
	while (count * count < size)
		count++;
	return (count);
}

int	get_bucket_size(int size, int bucket_count)
{
	return ((size + bucket_count - 1) / bucket_count);
}

int	is_in_bucket(t_stack *a, t_bucket bucket)
{
	return (a->stack[0] >= bucket.min
		&& a->stack[0] <= bucket.max);
}

int	count_bucket(t_stack *a, t_bucket bucket)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < a->size)
	{
		if (a->stack[i] >= bucket.min && a->stack[i] <= bucket.max)
			count++;
		i++;
	}
	return (count);
}

void	push_bucket(t_stack *a, t_stack *b, t_result *res,
	t_bucket bucket)
{
	int	j;
	int	count;
	int	pushed;

	j = res->nb;
	count = count_bucket(a, bucket);
	pushed = 0;
	while (pushed < count)
	{
		if (is_in_bucket(a, bucket))
		{
			ft_pb(a, b, res, &j);
			pushed++;
		}
		else
		{
			ft_ra(a);
			res->ope[j++] = RA;
			res->nb++;
		}
	}
}
