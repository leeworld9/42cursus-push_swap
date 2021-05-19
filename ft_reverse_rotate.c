/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 03:04:16 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/17 17:38:43 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse_rotate(t_stack *stack)
{
	t_node *node;
	t_node *tmp;
	
	// 이부분은 연산을 하지 않았으니까 출력은 안해야하는거 아닌가... 나중에 수정해보자.
	if ((stack->top) == NULL || (stack->top)->next == NULL)
		return ;
	node = stack->top;
	while (node->next != NULL)
	{
		tmp = node->next;
		if (tmp->next == NULL)
			break;
		else
			node = node->next;
	}
	tmp = node->next;
	node->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
}

void reverse_rotate_a(t_stack *a)
{
	ft_reverse_rotate(a);
	printf("rra\n");
}

void reverse_rotate_b(t_stack *b)
{
	ft_reverse_rotate(b);
	printf("rrb\n");
}

void reverse_rotate_ab(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	printf("rrr\n");
}