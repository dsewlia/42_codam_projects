/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:55:31 by dsewlia           #+#    #+#             */
/*   Updated: 2025/01/02 14:58:17 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define N 0
# define A_MIN 1
# define A_MAX 2
# define A_COUNT 3
# define B_MIN 4
# define B_MAX 5
# define B_COUNT 6
# define MAX_FLAG 7
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void		fn_pa(int *a, int *b, int *data);
void		fn_pb(int *a, int *b, int *data);
void		fn_sa(int *a);
void		fn_ra(int *a, int *data);
void		fn_rb(int *b, int *data);
void		fn_rr(int *a, int *b, int *data);
void		fn_rra(int *a, int *data);
void		fn_rrb(int *b, int *data);
void		fn_rrr(int *a, int *b, int *data);
void		fn_reverse_sorted(int n);
void		fn_sort_three(int *a, int *data, int median);
void		fn_last_handle(int *a, int *b, int *data, int median);
int			fn_get_steps_a(int *a, int *b, int *data, int x);
void		fn_final_phase(int *a, int *data);
void		fn_rotate_a(int *a, int *data, int *final_index);
void		fn_rotate_b(int *b, int *data, int *final_index);
int			fn_get_steps(int index_a, int *data, int i);
void		fn_rotate_both(int *a, int *b, int *data, int *final_index);
void		fn_rev_rotate_both(int *a, int *b, int *data, int *final_index);
void		fn_set_stacks_utils(int *a, int *b, int *data, int *final_index);
void		fn_set_stacks(int *a, int *b, int *data, int *final_index);
void		fn_push_left(int *a, int *b, int *data, int i);
void		fn_push_right(int *a, int *b, int *data);
void		fn_push_swap(int *a, int *b, int *data, int i);
void		fn_check_max(int *a, int *b, int *data);
void		fn_initial_sort(int *a, int *b, int *data, int i);
char		**get_split_array(char **a, char const *s, char c);
char		**get_array_mem(char **a, char const *s, char c, int x);
char		**ft_split(char const *s, char c);
int			fn_check_dup(int *a, int *data, int i, int j);
long int	custom_atoi_2(char *c, long int th, long int num, int i);
int			custom_atoi(int *a, char **x, int *data);
int			fn_initiate(char **x, int *data, int i, int status);
char		*fn_argv_copy(char *a);
char		**fn_input_parse_2(char **x, int status, int i);
char		**fn_input_parse(char **x, char **argv, int n);
int			main(int argc, char **argv);

#endif
