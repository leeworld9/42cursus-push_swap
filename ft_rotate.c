/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:10:34 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/14 22:55:07 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rotate(t_stack *stack)
{
	t_node *node;
	t_node *tmp;

	if ((stack->top) == NULL || (stack->top)->next == NULL)
		return ;
	tmp = stack->top;
	node = tmp->next;
	stack->top = node;
	while (node->next != NULL)
		node = node->next;
	node->next = tmp;
	tmp->next = NULL;
}
	
void rotate_a(t_stack *a)
{
	ft_rotate(a);
	printf("ra\n");
}

void rotate_b(t_stack *b)
{
	ft_rotate(b);
	printf("rb\n");
}

void rotate_ab(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	printf("rr\n");
}