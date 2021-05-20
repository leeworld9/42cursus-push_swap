/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 22:08:26 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/20 22:09:29 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_s *stack)
{
	stack->top = NULL;
}

int		isempty(t_s *stack)
{
	if (stack->top == NULL)
		return (1);
	else
		return (0);
}

t_n		*push(t_s *stack, int data)
{
	t_n	*now;

	now = (t_n *)malloc(sizeof(t_n));
	if (now == NULL)
		return (NULL);
	now->data = data;
	now->next = stack->top;
	stack->top = now;
	return (stack->top);
}

int		pop(t_s *stack)
{
	t_n		*now;
	int		ret;

	if (isempty(stack))
		return (0);
	now = stack->top;
	ret = now->data;
	stack->top = now->next;
	free(now);
	return (ret);
}
