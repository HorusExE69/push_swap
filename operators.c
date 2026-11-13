/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:32:49 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/11 10:58:35 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_code	ft_operator(t_stack *a, t_stack *b, t_operators operator, t_result *res, int *j)
{
	if (operator == SA)
		return (ft_sa(a));
	else if (operator == SB)
		return (ft_sb(b));
	else if (operator == SS)
		return (ft_ss(a, b));
	else if (operator == PA)
		return (ft_pa(a, b, res, j));
	else if (operator == PB)
		return (ft_pb(a, b, res, j));
	else if (operator == RA)
		return (ft_ra(a));
	else if (operator == RB)
		return (ft_rb(b));
	else if (operator == RR)
		return (ft_rr(a, b));
	else if (operator == RRA)
		return (ft_rra(a));
	else if (operator == RRB)
		return (ft_rrb(b));
	else if (operator == RRR)
		return (ft_rrr(a, b));
	return (ERROR);
}
