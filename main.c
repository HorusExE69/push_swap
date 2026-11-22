/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:17:20 by habretag          #+#    #+#             */
/*   Updated: 2026/11/22 11:09:57 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>

static t_stack	*check_flags(int argc, char **argv, int *flag, int *bench)
{
	int	start;

	start = 1;
	while (argv[start] && argv[start][0] == '-' && argv[start][1] == '-')
	{
		if (ft_strcmp(argv[start], "--bench") == 0)
			*bench = 1;
		else if (*flag != -1)
			return (NULL);
		else if (ft_strcmp(argv[start], "--simple") == 0)
			*flag = 0;
		else if (ft_strcmp(argv[start], "--medium") == 0)
			*flag = 1;
		else if (ft_strcmp(argv[start], "--complex") == 0)
			*flag = 2;
		else if (ft_strcmp(argv[start], "--adaptive") == 0)
			*flag = 3;
		else
			return (NULL);
		start++;
	}
	if (!argv[start])
		return (NULL);
	return (build_stack(argc - start, argv + start));
}

static t_result	*choose_algo(t_stack *a, int flag)
{
	if (flag == 0)
		return (simple_algo(a));
	if (flag == 1)
		return (medium_algo(a));
	if (flag == 2)
		return (complex_algo(a));
	return (compute_algo(a));
}

static int	run(t_stack *a, int flag, int bench)
{
	t_result	*res;
	float		disorder;

	disorder = 0.0f;
	if (bench)
		disorder = compute_disorder(*a);
	if (is_sorted(a))
	{
		if (bench)
			bench_report(NULL, disorder, flag);
		return (0);
	}
	res = choose_algo(a, flag);
	if (!res)
		return (1);
	print_t_stack(res);
	if (bench)
		bench_report(res, disorder, flag);
	free_result(res);
	return (0);
}

static int	error_exit(t_stack *a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	int			flag;
	int			bench;
	t_stack		*a;

	flag = -1;
	bench = 0;
	a = NULL;
	if (argc < 2)
		return (0);
	if (argv[1][0] == '-' && argv[1][1] == '-')
		a = check_flags(argc, argv, &flag, &bench);
	else
		a = build_stack(argc - 1, argv + 1);
	if (!a || !a->stack || run(a, flag, bench))
		return (error_exit(a));
	free_stack(a);
	return (0);
}
