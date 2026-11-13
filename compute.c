/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaillan <esaillan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:13:26 by habretag          #+#    #+#             */
/*   Updated: 2026/11/13 14:16:13 by esaillan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float	compute_disorder(t_stack a)
{
	int	mis;
	int	tot_pairs;
	int	i;
	int	j;

	mis = 0;
	tot_pairs = 0;
	i = 0;
	while (i < a.size - 1)
	{
		j = i + 1;
		while (j < a.size)
		{
			tot_pairs++;
			if (a.stack[i] > a.stack[j])
				mis++;
			j++;
		}
		i++;
	}
	return ((float)mis / (float)tot_pairs);
}

t_result	*compute_algo(t_stack *a)
{
	float	dis;

	dis = compute_disorder(*a);
	if (dis < 0.2)
		return (simple_algo(a));
	else if (dis >= 0.5)
		return (complex_algo(a));
	else
		return (medium_algo(a));
}
