/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_rr_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaillan <esaillan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:30:31 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/13 13:22:45 by esaillan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_op_code	ft_rr_(t_stack *stack)
{
	int	changed;

	if (!stack || stack->size <= 1)
		return (ERROR);
	changed = stack->stack[stack->size - 1];
	ft_pushfront(stack, changed);
	stack->size--;
	return (GOOD);
}

t_op_code	ft_rra(t_stack *a)
{
	return (ft_rr_(a));
}

t_op_code	ft_rrb(t_stack *b)
{
	return (ft_rr_(b));
}

t_op_code	ft_rrr(t_stack *a, t_stack *b)
{
	t_op_code	res_a;
	t_op_code	res_b;

	res_a = ft_rra(a);
	res_b = ft_rrb(b);
	return (res_a == GOOD || res_b == GOOD);
}
