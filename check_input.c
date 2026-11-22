/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 13:26:46 by habretag          #+#    #+#             */
/*   Updated: 2026/11/22 10:49:34 by habretag         ###   ########lyon.fr   */
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
		if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
			return (1);
		j++;
	}
	return (0);
}

static int	check_input(int argc, char **argv)
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

static t_stack	*check_no_flags(int argc, char **argv)
{
	int		i;
	t_stack	*a;

	i = 0;
	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->size = argc;
	a->stack = malloc(sizeof(int) * argc);
	if (!a->stack)
	{
		free(a);
		return (NULL);
	}
	while (i < argc)
	{
		a->stack[i] = ft_atoi(argv[i]);
		i++;
	}
	return (a);
}

t_stack	*build_stack(int argc, char **argv)
{
	char	**args;
	int		count;
	t_stack	*a;

	args = parse_args(argc, argv, &count);
	if (!args)
		return (NULL);
	a = NULL;
	if (check_input(count, args))
		a = check_no_flags(count, args);
	free_strs(args);
	return (a);
}
