/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_r_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaillan <esaillan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:30:03 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/13 11:40:22 by esaillan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_code	ft_r_(t_stack *stack)
{
	int	changed;

	if (stack->size == 0)
		return (ERROR);
	changed = ft_popfront(stack);
	ft_push(stack, changed);
	return (GOOD);
}

t_op_code	ft_ra(t_stack *a)
{
	return (ft_r_(a));
}

t_op_code	ft_rb(t_stack *b)
{
	return (ft_r_(b));
}

t_op_code	ft_rr(t_stack *a, t_stack *b)
{
	return (ft_ra(a) == GOOD || ft_rb(b) == GOOD);
}
