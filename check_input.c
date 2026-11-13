/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 13:26:46 by habretag          #+#    #+#             */
/*   Updated: 2026/11/13 14:47:19 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int_limit(char *str)
{
	long long	nb;
	int			sign;
	int			i;

	nb = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		nb = nb * 10 + (str[i] - '0');
		if (sign == 1 && nb > 2147483647)
			return (0);
		if (sign == -1 && nb > 2147483648LL)
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate(int i, char **argv)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (atoi(argv[j]) == atoi(argv[i]))
			return (1);
		j++;
	}
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]) || !check_int_limit(argv[i]))
			return (0);
		if (is_duplicate(i, argv))
			return (0);
		i++;
	}
	return (1);
}