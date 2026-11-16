/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaillan <esaillan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 11:19:12 by habretag          #+#    #+#             */
/*   Updated: 2026/11/16 14:02:50 by esaillan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "stack.h"
# include "operators.h"
# include "result.h"
# include "bucket.h"

// Main functions
t_result	*compute_algo(t_stack *a);
t_result	*simple_algo(t_stack *a);
t_result	*medium_algo(t_stack *a);
t_result	*complex_algo(t_stack *a);
void		collect_stack(t_stack *a, t_stack *b, t_result *res);
int			get_max_index(t_stack *b);
int			check_input(int argc, char **argv);

// Test
void		print_t_stack(t_result *result);

// Utils functions
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int			ft_strcmp(char *s1, char *s2);
void		ft_bzero(void *s, size_t n); // UTILISER DANS CALLOC
void		*ft_calloc(size_t nmemb, size_t size); // PAS UTILISER
void		*ft_memset(void *s, int c, size_t n); // UTILISER DANS BZERO/CALLOC
int			ft_isnumber(char *str);
int			ft_atoi(const char *nptr);
void		ft_incr(t_result *res, int *j, t_operators operator);

// Bucket functions
int			get_bucket_count(int size);
int			get_bucket_size(int size, int bucket_count);
int			is_in_bucket(t_stack *a, t_bucket bucket);
int			count_bucket(t_stack *a, t_bucket bucket);
void		push_bucket(t_stack *a, t_stack *b, t_result *res, t_bucket bucket);

// Init functions
t_stack		*init_rank_stack(int *normalized, int size);
t_stack		*init_stack_b(int capacity);
t_result	*init_result(void);

// Stack Utils
int			*normalize_stack(t_stack *a);
int			get_max_index(t_stack *b);
void		collect_stack(t_stack *a, t_stack *b, t_result *res);
int			is_sorted(t_stack *a);

// Operators utils
void		ft_swap(int *a, int *b);
int			ft_pop(t_stack *stack);
void		ft_push(t_stack *stack, int new);
int			ft_popfront(t_stack *stack);
void		ft_pushfront(t_stack *stack, int new);

// Operators
t_op_code	ft_operator(t_stack *a, t_stack *b, t_operators operator);
t_op_code	ft_sa(t_stack *a);
t_op_code	ft_sb(t_stack *b);
t_op_code	ft_ss(t_stack *a, t_stack *b);
t_op_code	ft_pa(t_stack *a, t_stack *b);
t_op_code	ft_pb(t_stack *a, t_stack *b);
t_op_code	ft_ra(t_stack *a);
t_op_code	ft_rb(t_stack *b);
t_op_code	ft_rr(t_stack *a, t_stack *b);
t_op_code	ft_rra(t_stack *a);
t_op_code	ft_rrb(t_stack *b);
t_op_code	ft_rrr(t_stack *a, t_stack *b);

#endif
