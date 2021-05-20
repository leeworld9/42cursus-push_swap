/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:32:43 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/20 21:58:18 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_swap(t_s *stack)
{
	t_n	*node1;
	t_n	*node2;
	t_n	*tmp;

	if ((stack->top)->next == NULL)
		return (false);
	node1 = stack->top;
	node2 = node1->next;
	tmp = node2->next;
	node2->next = node1;
	node1->next = tmp;
	stack->top = node2;
	return (true);
}

void	swap_a(t_s *a)
{
	if (ft_swap(a) == true)
		printf("sa\n");
}

void	swap_b(t_s *b)
{
	if (ft_swap(b) == true)
		printf("sb\n");
}

void	swap_ab(t_s *a, t_s *b)
{
	bool as;
	bool bs;

	as = ft_swap(a);
	bs = ft_swap(b);
	if (as == true && bs == true)
		printf("ss\n");
	else if (as == false && bs == true)
		printf("sb\n");
	else if (as == true && bs == false)
		printf("sa\n");
}
