/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_s_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:50:37 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/10 15:17:48 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_op_code	ft_s_(t_stack *stack)
{
	if (!stack || stack->size <= 1)
		return (ERROR);
	ft_swap(&(stack->stack[0]), &(stack->stack[1]));
	return (GOOD);
}

t_op_code	ft_sa(t_stack *a)
{
	return (ft_s_(a));
}

t_op_code	ft_sb(t_stack *b)
{
	return (ft_s_(b));
}

t_op_code	ft_ss(t_stack *a, t_stack *b)
{
	if (ft_sa(a) == GOOD)
	{
		if (ft_sb(b) == GOOD)
			return (GOOD);
		return (A_GOOD);
	}
	if (ft_sb(b) == GOOD)
		return (B_GOOD);
	return (ERROR);
}
