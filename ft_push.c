/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:52:02 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/21 00:44:12 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_push(t_s *stack1, t_s *stack2)
{
	int	tmp;

	if ((stack2->top) == NULL)
		return (false);
	else
	{
		tmp = pop(stack2);
		push(stack1, tmp);
	}
	return (true);
}

void	push_a(t_s *a, t_s *b)
{
	if (ft_push(a, b) == true)
		printf("pa\n");
}

void	push_b(t_s *a, t_s *b)
{
	if (ft_push(b, a) == true)
		printf("pb\n");
}
