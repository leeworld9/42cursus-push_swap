/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:15:46 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/20 22:04:36 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_s *a)
{
	t_n	*bottom;

	while (!sort_check_asc(a, 3))
	{
		bottom = (a->top)->next->next;
		if ((a->top)->data > ((a->top)->next)->data)
		{
			if (((a->top)->next)->data > bottom->data)
				swap_a(a);
			else
			{
				if ((a->top)->data > bottom->data)
					rotate_a(a);
				else
					swap_a(a);
			}
		}
		else
		{
			if ((a->top)->data > bottom->data)
				reverse_rotate_a(a);
			else
				swap_a(a);
		}
	}
}

void	sort_5(t_s *a, t_s *b)
{
	t_n	*b_top;
	t_n	*b_bottom;
	t_u	u;

	if (sort_check_asc(a, 5))
		return ;
	get_utils(&u, a, 5);
	while (!isempty(a))
	{
		if (stack_len(b) == 2)
			break ;
		if ((a->top)->data == u.min || (a->top)->data == u.max)
			push_b(a, b);
		else
			rotate_a(a);
	}
	b_top = b->top;
	b_bottom = b_top->next;
	if (b_bottom->data < b_top->data)
		swap_b(b);
	sort_3(a);
	push_a(a, b);
	push_a(a, b);
	rotate_a(a);
}