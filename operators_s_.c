/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_s_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaillan <esaillan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:50:37 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/13 11:41:07 by esaillan         ###   ########lyon.fr   */
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
	t_op_code	res_a;
	t_op_code	res_b;

	res_a = ft_sa(a);
	res_b = ft_sb(b);
	return (res_a == GOOD || res_b == GOOD);
}
