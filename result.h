/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaillan <esaillan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 14:30:53 by habretag          #+#    #+#             */
/*   Updated: 2026/11/13 11:33:45 by esaillan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESULT_H
# define RESULT_H

# include "operators.h"

typedef struct s_result
{
	int			nb;
	t_operators	*ope;
}	t_result;

#endif