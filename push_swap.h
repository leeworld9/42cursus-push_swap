/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 02:28:10 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/21 02:31:44 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct	s_n
{
	int			data;
	struct s_n	*next;
}				t_n;

typedef struct	s_s
{
	struct s_n	*top;
}				t_s;

typedef struct	s_u
{
	int			min;
	int			max;
	int			sum;
	int			avg;
}				t_u;

typedef struct	s_q
{
	int			pivot;
	int			ra_cnt;
	int			rb_cnt;
	int			pa_cnt;
	int			pb_cnt;
	int			pb_offset;
	int			pa_offset;
}				t_q;

void			init_stack(t_s *stack);
int				isempty(t_s *stack);
t_n				*push(t_s *stack, int data);
int				pop(t_s *stack);

bool			ft_swap(t_s *stack);
void			swap_a(t_s *a);
void			swap_b(t_s *b);
void			swap_ab(t_s *a, t_s *b);

bool			ft_push(t_s *stack1, t_s *stack2);
void			push_a(t_s *a, t_s *b);
void			push_b(t_s *a, t_s *b);

bool			ft_rotate(t_s *stack);
void			rotate_a(t_s *a);
void			rotate_b(t_s *b);
void			rotate_ab(t_s *a, t_s *b);

bool			ft_reverse_rotate(t_s *stack);
void			reverse_rotate_a(t_s *a);
void			reverse_rotate_b(t_s *b);
void			reverse_rotate_ab(t_s *a, t_s *b);

bool			chk_double(char **argv);
bool			chk_digit(char *str);
bool			chk_type(char *str);

void			quick_atob(t_s *a, t_s *b, int len, int depth);
void			quick_atob_pivotchk(t_s *a, t_s *b, int len, t_q *q);
void			quick_atob_rollback(t_s *a, t_q *q, int depth);

void			quick_btoa(t_s *a, t_s *b, int len, int depth);
void			quick_btoa_pivotchk(t_s *a, t_s *b, int len, t_q *q);
void			quick_btoa_rollback(t_s *a, t_s *b, t_q *q);
void			quick_btoa_last(t_s *a, t_s *b, int len);

void			sort_3_a(t_s *a);
void			sort_3_b(t_s *b);
void			sort_5(t_s *a, t_s *b);

void			get_utils(t_u *u, t_s *stack, int len);
int				get_half(t_u *u, t_s *stack, int len);
int				get_pivot(t_s *stack, int len, char type);

int				lastpush_get_a(t_s *stack, int len, int pivot);
int				lastpush_get_b(t_s *stack, int len, int pivot);
bool			sort_check_asc(t_s *stack, int len);
bool			sort_check_desc(t_s *stack, int len);

int				stack_len(t_s *stack);
void			sort(t_s *a, t_s *b, int len);
int				list_free(t_s *stack);
int				errchk(char **argv);

#endif
