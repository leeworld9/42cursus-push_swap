/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_optimize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 08:09:21 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/20 22:07:48 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lastpush_get_a(t_s *stack, int len, int pivot)
{
	t_n	*tmp;
	int	i;
	int	offset;

	i = 1;
	offset = 0;
	tmp = stack->top;
	while (i <= len)
	{
		if (tmp->data <= pivot)
			offset = i;
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (offset);
}

int		lastpush_get_b(t_s *stack, int len, int pivot)
{
	t_n	*tmp;
	int	i;
	int	offset;

	i = 1;
	offset = 0;
	tmp = stack->top;
	while (i <= len)
	{
		if (tmp->data > pivot)
			offset = i;
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (offset);
}

bool	sort_check_asc(t_s *stack, int len)
{
	t_n	*tmp;
	int	res;
	int	i;

	i = 0;
	res = true;
	tmp = stack->top;
	while (i < len)
	{
		if (tmp->next != NULL)
		{
			if (tmp->data < (tmp->next)->data)
				tmp = tmp->next;
			else
				break ;
		}
		i++;
	}
	if (i == len)
		res = true;
	else
		res = false;
	return (res);
}

bool	sort_check_desc(t_s *stack, int len)
{
	t_n	*tmp;
	int	res;
	int	i;

	i = 0;
	res = true;
	tmp = stack->top;
	while (i < len)
	{
		if (tmp->next != NULL)
		{
			if (tmp->data < (tmp->next)->data)
				tmp = tmp->next;
			else
				break ;
		}
		i++;
	}
	if (i == len)
		res = true;
	else
		res = false;
	return (res);
}
