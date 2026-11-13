/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_rr_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:30:31 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/11 10:49:01 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_op_code	ft_reverse_rotate(t_stack *stack)
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
	return (ft_reverse_rotate(a));
}

t_op_code	ft_rrb(t_stack *b)
{
	return (ft_reverse_rotate(b));
}

t_op_code	ft_rrr(t_stack *a, t_stack *b)
{
	if (ft_rra(a) == GOOD)
	{
		if (ft_rrb(b) == GOOD)
			return (GOOD);
		return (A_GOOD);
	}
	if (ft_rrb(b) == GOOD)
		return (B_GOOD);
	return (ERROR);
}
