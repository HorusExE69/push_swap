/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:13:02 by esaillan          #+#    #+#             */
/*   Updated: 2026/11/10 15:17:18 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_pop(t_stack *stack)
{
	int	final;
	int	*temp;
	int	i;

	if (stack->size < 1)
		return (0);
	final = stack->stack[stack->size - 1];
	temp = NULL;
	if (stack->size > 1)
	{
		temp = malloc(sizeof(int) * (stack->size - 1));
		if (!temp)
			return (0);
		i = -1;
		while (++i < stack->size - 1)
			temp[i] = stack->stack[i];
	}
	stack->size--;
	free(stack->stack);
	stack->stack = temp;
	return (final);
}

void	ft_push(t_stack *stack, int new)
{
	int	*temp;
	int	i;

	temp = malloc(sizeof(int) * (stack->size + 1));
	if (!temp)
		return ;
	temp[stack->size] = new;
	i = -1;
	while (++i < stack->size)
		temp[i] = stack->stack[i];
	stack->size++;
	free(stack->stack);
	stack->stack = temp;
}

int	ft_popfront(t_stack *stack)
{
	int	final;
	int	*temp;
	int	i;

	if (stack->size < 1)
		return (0);
	final = stack->stack[0];
	temp = NULL;
	if (stack->size > 1)
	{
		temp = malloc(sizeof(int) * (stack->size - 1));
		if (!temp)
			return (0);
		i = 0;
		while (++i < stack->size)
			temp[i - 1] = stack->stack[i];
	}
	stack->size--;
	free(stack->stack);
	stack->stack = temp;
	return (final);
}

void	ft_pushfront(t_stack *stack, int new)
{
	int	*temp;
	int	i;

	temp = malloc(sizeof(int) * (stack->size + 1));
	if (!temp)
		return ;
	temp[0] = new;
	i = -1;
	while (++i < stack->size)
		temp[i + 1] = stack->stack[i];
	stack->size++;
	free(stack->stack);
	stack->stack = temp;
}
