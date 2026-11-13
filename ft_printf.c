/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:06:40 by habretag          #+#    #+#             */
/*   Updated: 2026/11/11 10:06:41 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	tag_print(char c, va_list *args)
{
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	else if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	else if (c == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), 0));
	else if (c == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), 1));
	else if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		tot;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	tot = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			tot += tag_print(str[i], &args);
		}
		else if (str[i] != '%')
			tot += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (tot);
}
