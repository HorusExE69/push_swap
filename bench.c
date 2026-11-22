/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:28:49 by habretag          #+#    #+#             */
/*   Updated: 2026/11/22 11:34:42 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	put_str_fd(int fd, char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

static void	put_nbr_fd(int fd, int nb)
{
	char	digit;

	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		put_nbr_fd(fd, nb / 10);
	digit = nb % 10 + '0';
	write(fd, &digit, 1);
}

static void	print_header(float disorder, int flag)
{
	int	cent;

	cent = (int)(disorder * 10000.0f + 0.5f);
	put_str_fd(2, "[bench] disorder:  ");
	put_nbr_fd(2, cent / 100);
	put_str_fd(2, ".");
	if (cent % 100 < 10)
		put_str_fd(2, "0");
	put_nbr_fd(2, cent % 100);
	put_str_fd(2, "%\n[bench] strategy:  ");
	if (flag == 0)
		put_str_fd(2, "Simple / O(n^2)\n");
	else if (flag == 1)
		put_str_fd(2, "Medium / O(n sqrt(n))\n");
	else if (flag == 2)
		put_str_fd(2, "Complex / O(n log n)\n");
	else if (disorder < 0.2f)
		put_str_fd(2, "Adaptive / O(n^2)\n");
	else if (disorder < 0.5f)
		put_str_fd(2, "Adaptive / O(n sqrt(n))\n");
	else
		put_str_fd(2, "Adaptive / O(n log n)\n");
}

static void	print_counts(t_result *res)
{
	static char	*names[11] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};
	int			counts[11];
	int			i;

	ft_bzero(counts, sizeof(counts));
	i = -1;
	while (res && res->operation_count > 0 && ++i < res->operation_count)
		if (res->operations[i] >= SA && res->operations[i] <= RRR)
			counts[res->operations[i]]++;
	i = -1;
	while (++i < 11)
	{
		if (i == 0 || i == 5)
			put_str_fd(2, "[bench] ");
		put_str_fd(2, names[i]);
		put_str_fd(2, ": ");
		put_nbr_fd(2, counts[i]);
		if (i == 4 || i == 10)
			put_str_fd(2, "\n");
		else
			put_str_fd(2, " ");
	}
}

void	bench_report(t_result *res, float disorder, int flag)
{
	print_header(disorder, flag);
	put_str_fd(2, "[bench] total_ops: ");
	if (res && res->operation_count > 0)
		put_nbr_fd(2, res->operation_count);
	else
		put_nbr_fd(2, 0);
	put_str_fd(2, "\n");
	print_counts(res);
}
