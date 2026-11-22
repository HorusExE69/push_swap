/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_for_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 11:03:57 by habretag          #+#    #+#             */
/*   Updated: 2026/11/22 11:05:49 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**free_strs(char **strs)
{
	int	i;

	if (!strs)
		return (NULL);
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

void	free_stack(t_stack *s)
{
	if (!s)
		return ;
	free(s->stack);
	free(s);
}

void	free_result(t_result *res)
{
	if (!res)
		return ;
	free(res->operations);
	free(res);
}

t_result	*clean_exit(t_stack *a, t_stack *b, t_result *res, t_result *ret)
{
	free_stack(a);
	free_stack(b);
	if (res != ret)
		free_result(res);
	return (ret);
}
