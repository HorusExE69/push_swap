/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:46:36 by habretag          #+#    #+#             */
/*   Updated: 2026/11/12 17:18:26 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_rank(t_stack *a, int index)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (i < a->size)
	{
		if (a->stack[i] < a->stack[index])
			rank++;
		i++;
	}
	return (rank);
}

int	*normalize_stack(t_stack *a)
{
	int	*normalized;
	int	i;

	normalized = malloc(sizeof(int) * a->size);
	if (!normalized)
		return (NULL);
	i = 0;
	while (i < a->size)
	{
		normalized[i] = get_rank(a, i);
		i++;
	}
	return (normalized);
}

int	get_max_index(t_stack *b)
{
	int	i;
	int	max_index;

	max_index = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->stack[i] > b->stack[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

static void	rotate_max_to_top(t_stack *b, t_result *res, int *j)
{
	int	max_index;

	max_index = get_max_index(b);
	if (max_index <= b->size / 2)
	{
		while (max_index > 0)
		{
			ft_rb(b);
			res->ope[(*j)++] = RB;
			res->nb++;
			max_index--;
		}
	}
	else
	{
		while (max_index < b->size)
		{
			ft_rrb(b);
			res->ope[(*j)++] = RRB;
			res->nb++;
			max_index++;
		}
	}
}

void	collect_stack(t_stack *a, t_stack *b, t_result *res)
{
	int	j;

	j = res->nb;
	while (b->size > 0)
	{
		rotate_max_to_top(b, res, &j);
		ft_pa(a, b, res, &j);
	}
}
