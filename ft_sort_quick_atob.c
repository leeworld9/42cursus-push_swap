/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_quick_atob.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:08:38 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/20 22:08:39 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_atob(t_s *a, t_s *b, int len, int depth)
{
	t_q	q;
	int	i;

	if (len <= 1)
		return ;
	if (len == 2)
	{
		if ((a->top)->data > ((a->top)->next)->data)
			swap_a(a);
		return ;
	}
	if (sort_check_asc(a, len))
		return ;
	quick_atob_pivotchk(a, b, len, &q);
	quick_atob_rollback(a, b, &q, depth);
	quick_atob(a, b, len - q.pb_cnt, depth + 1);
	quick_btoa(a, b, q.pb_cnt, depth + 1);
}

void	quick_atob_pivotchk(t_s *a, t_s *b, int len, t_q *q)
{
	int i;

	i = 0;
	q->ra_cnt = 0;
	q->pb_cnt = 0;
	if (!isempty(a))
		q->pivot = get_pivot(a, len, 'a');
	q->pb_offset = lastpush_get_a(a, len, q->pivot);
	while (i < q->pb_offset)
	{
		if ((a->top)->data > q->pivot)
		{
			rotate_a(a);
			q->ra_cnt++;
		}
		else
		{
			push_b(a, b);
			q->pb_cnt++;
		}
		i++;
	}
}

void	quick_atob_rollback(t_s *a, t_s *b, t_q *q, int depth)
{
	int i;

	i = 0;
	while (i < q->ra_cnt && depth != 0)
	{
		reverse_rotate_a(a);
		i++;
	}
}
