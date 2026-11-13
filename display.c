/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:39:45 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/11 10:10:45 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

static char	*ft_t_operators_to_str(t_operators operator)
{
	static char *const	ops[] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"
	};

	if (operator >= SA && operator <= RRR)
		return (ops[operator]);
	return (NULL);
}

void	print_t_stack(t_result *res)
{
	int	i;

	if (!res)
		return ;
	i = 0;
	while (i < res->nb)
	{
		ft_printf("%s\n", ft_t_operators_to_str(res->ope[i]));
		i++;
	}
}
