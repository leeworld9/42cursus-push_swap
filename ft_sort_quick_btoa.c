/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick_btoa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:08:45 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/21 02:32:17 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_btoa(t_s *a, t_s *b, int len, int depth)
{
	t_q	q;

	if (len <= 1)
	{
		if (len == 1)
			push_a(a, b);
		return ;
	}
	if (len == 2)
	{
		if ((b->top)->data < ((b->top)->next)->data)
			swap_b(b);
		push_a(a, b);
		push_a(a, b);
		return ;
	}
	quick_btoa_pivotchk(a, b, len, &q);
	quick_btoa_rollback(a, b, &q);
	quick_atob(a, b, q.pa_cnt, depth + 1);
	if (q.pa_cnt != 0)
		quick_btoa(a, b, len - q.pa_cnt, depth + 1);
	if (q.pa_cnt == 0)
		quick_btoa_last(a, b, len);
}

void	quick_btoa_last(t_s *a, t_s *b, int len)
{
	int i;

	i = 0;
	if (!sort_check_asc(b, len))
		sort_3_b(b);
	while (i < len)
	{
		reverse_rotate_b(b);
		push_a(a, b);
		i++;
	}
}

void	quick_btoa_pivotchk(t_s *a, t_s *b, int len, t_q *q)
{
	int i;

	i = 0;
	q->rb_cnt = 0;
	q->pa_cnt = 0;
	q->pa_offset = 0;
	if (!isempty(b))
		q->pivot = get_pivot(b, len, 'b');
	q->pa_offset = lastpush_get_b(b, len, q->pivot);
	while (i < q->pa_offset)
	{
		if ((b->top)->data <= q->pivot)
		{
			rotate_b(b);
			q->rb_cnt++;
		}
		else
		{
			push_a(a, b);
			q->pa_cnt++;
		}
		i++;
	}
}

void	quick_btoa_rollback(t_s *a, t_s *b, t_q *q)
{
	int i;

	i = 0;
	while (i < q->rb_cnt)
	{
		reverse_rotate_b(b);
		if ((q->pa_cnt == 0) && (b->top)->data == q->pivot)
		{
			push_a(a, b);
			q->pa_cnt++;
			q->rb_cnt--;
		}
		i++;
	}
}
