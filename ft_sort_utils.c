/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:08:55 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/20 22:08:55 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_utils(t_u *u, t_s *stack, int len)
{
	t_n	*tmp;
	int	i;

	i = 0;
	u->sum = 0;
	tmp = stack->top;
	u->min = tmp->data;
	u->max = tmp->data;
	while (i < len)
	{
		u->sum += tmp->data;
		if (u->min > tmp->data)
			u->min = tmp->data;
		if (u->max < tmp->data)
			u->max = tmp->data;
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
		i++;
	}
	u->avg = (u->sum) / len;
}

int		get_half(t_u *u, t_s *stack, int len)
{
	t_n	*tmp;
	int	i;
	int	avg_under;
	int	avg_below;

	i = 0;
	tmp = stack->top;
	avg_under = u->min;
	avg_below = u->max;
	while (i < len && tmp->next != NULL)
	{
		if (tmp->data < u->max && tmp->data > u->min)
		{
			if (tmp->data == u->avg)
				return (tmp->data);
			else if (tmp->data < u->avg)
				avg_under = (tmp->data > avg_under) ? tmp->data : avg_under;
			else if (tmp->data > u->avg)
				avg_below = (tmp->data < avg_below) ? tmp->data : avg_below;
		}
		tmp = tmp->next;
	}
	return ((avg_under == u->min) ? avg_below : avg_under);
}

int		get_pivot(t_s *stack, int len, char type)
{
	t_n	*tmp;
	t_u	u;
	int	i;
	int	pivot;

	get_utils(&u, stack, len);
	i = 0;
	if (len == 2)
	{
		if (type == 'a')
			return (u.max);
		else
			return (u.min);
	}
	pivot = get_half(&u, stack, len);
	return (pivot);
}
