/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:06:35 by habretag          #+#    #+#             */
/*   Updated: 2026/11/11 10:06:36 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	write(1, &ch, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	int	len;

	if (!s)
		return (ft_print_str("(null)"));
	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_print_char('-');
		nb = -nb;
	}
	if (nb >= 10)
		count += ft_print_nbr((int)(nb / 10));
	count += ft_print_char((int)(nb % 10) + '0');
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_unsigned(n / 10);
	count += ft_print_char((int)(n % 10) + '0');
	return (count);
}

int	ft_print_hex(unsigned long long n, int upper)
{
	char	*base;
	int		count;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_print_hex(n / 16, upper);
	count += ft_print_char(base[n % 16]);
	return (count);
}
