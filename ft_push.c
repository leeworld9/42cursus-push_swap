/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:52:02 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/08 04:17:09 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_push(t_stack *stack1, t_stack *stack2)
{
	int tmp;

	if ((stack2->top) == NULL)
		return ;
	else
	{
		tmp = pop(stack2);
		push(stack1, tmp);
	}
}

void push_a(t_stack *a, t_stack *b)
{
	ft_push(a, b);
	printf("pa\n");
}

void push_b(t_stack *a, t_stack *b)
{
	ft_push(b, a);
	printf("pb\n");
}
