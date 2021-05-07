/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 13:32:43 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/08 04:17:05 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_node *node1;
	t_node *node2;
	t_node *tmp;

	node1 = stack->top; // top
	node2 = node1->next; // top-1

	tmp = node2->next;
	node2->next = node1;
	node1->next = tmp;
	
	stack->top = node2;
}

void	swap_a(t_stack *a)
{
	ft_swap(a);
	printf("sa\n");
}

void	swap_b(t_stack *b)
{
	ft_swap(b);
	printf("sb\n");
}

void	swap_ab(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	printf("ss\n");
}