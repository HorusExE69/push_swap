/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habretag <habretag@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:06:37 by habretag          #+#    #+#             */
/*   Updated: 2026/11/11 10:06:39 by habretag         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *p)
{
	if (!p)
		return (ft_print_str("(nil)"));
	return (ft_print_str("0x") + ft_print_hex((unsigned long)p, 0));
}
