/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaillan <esaillan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:17:20 by habretag          #+#    #+#             */
/*   Updated: 2026/11/13 15:31:15 by esaillan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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
		return (free(a), NULL);
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]))
			return (free(a->stack), free(a), NULL);
		a->stack[i] = ft_atoi(argv[i]);
		i++;
	}
	return (a);
}

static t_stack	*check_flags(int argc, char **argv, int *flag)
{
	if (ft_strcmp(argv[1], "--simple") == 0)
		*flag = 0;
	else if (ft_strcmp(argv[1], "--medium") == 0)
		*flag = 1;
	else if (ft_strcmp(argv[1], "--complex") == 0)
		*flag = 2;
	else if (ft_strcmp(argv[1], "--adaptative") == 0)
		*flag = 3;
	if (!argv[2])
		return (NULL);
	return (check_no_flags(argc - 2, argv + 2));
}

static t_result	*choose_algo(t_stack *a, int flag)
{
	if (flag == 0)
		return (simple_algo(a));
	if (flag == 1)
		return (medium_algo(a));
	if (flag == 2)
		return (complex_algo(a));
	if (flag == 3)
		return (compute_algo(a));
	return (NULL);
}

int	main(int argc, char **argv)
{
	int			flag;
	t_stack		*a;
	t_result	*res;

	flag = 3;
	if (argc < 2)
		return (1);
	if (argv[1][0] == '-' && argv[1][1] == '-')
		a = check_flags(argc, argv, &flag);
	else
		a = check_no_flags(argc - 1, argv + 1);
	if (!a)
		return (1);
	if (!a->stack)
		return (free(a), 1);
	res = choose_algo(a, flag);
	if (!res)
		return (free(a->stack), free(a), 1);
	print_t_stack(res);
	return (free(res->ope), free(res), free(a->stack), free(a), 0);
}
