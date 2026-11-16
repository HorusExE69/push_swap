/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 14:09:15 by habretag          #+#    #+#             */
/*   Updated: 2026/11/12 17:18:47 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_rank_stack(int *normalized, int size)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->stack = normalized;
	a->size = size;
	return (a);
}

t_stack	*init_stack_b(int capacity)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
		return (NULL);
	b->stack = malloc(sizeof(int) * capacity);
	if (!b->stack)
		return (free(b), NULL);
	b->size = 0;
	return (b);
}

t_result	*init_result(void)
{
	t_result	*res;

	res = malloc(sizeof(t_result));
	if (!res)
		return (NULL);
	res->ope = NULL;
	res->nb = 0;
	return (res);
}
