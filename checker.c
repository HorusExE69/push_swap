/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:26:50 by habretag          #+#    #+#             */
/*   Updated: 2026/11/16 16:15:00 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static int	checker_exit(t_stack *a, t_stack *b, int error)
{
	if (a)
	{
		free(a->stack);
		free(a);
	}
	if (b)
	{
		free(b->stack);
		free(b);
	}
	if (error)
		write(2, "Error\n", 6);
	return (error);
}

static int	read_line(char *line, int size)
{
	char	c;
	int		i;
	int		res;

	i = 0;
	res = 1;
	while (i < size - 1 && res > 0)
	{
		res = read(0, &c, 1);
		if (res <= 0 || c == '\n')
			break ;
		line[i++] = c;
	}
	line[i] = '\0';
	if (res < 0)
		return (-1);
	if (res == 0 && i == 0)
		return (0);
	return (1);
}

static int	parse_operator(char *line)
{
	static char	*names[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	int			i;

	i = 0;
	while (i < 11)
	{
		if (ft_strcmp(line, names[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static int	read_operations(t_stack *a, t_stack *b)
{
	char	line[8];
	int		res;
	int		op;

	res = 1;
	while (res > 0)
	{
		res = read_line(line, sizeof(line));
		if (res > 0)
		{
			op = parse_operator(line);
			if (op < 0)
				return (-1);
			ft_operator(a, b, (t_operators)op);
		}
	}
	return (res);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	if (!check_input(argc - 1, argv + 1))
		return (checker_exit(NULL, NULL, 1));
	a = check_no_flags(argc - 1, argv + 1);
	if (!a || !a->stack)
		return (checker_exit(a, NULL, 1));
	b = init_stack_b(a->size);
	if (!b)
		return (checker_exit(a, NULL, 1));
	if (read_operations(a, b) < 0)
		return (checker_exit(a, b, 1));
	if (is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (checker_exit(a, b, 0));
}
