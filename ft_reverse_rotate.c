/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 03:04:16 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/20 22:00:06 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_reverse_rotate(t_s *stack)
{
	t_n	*node;
	t_n	*tmp;

	if ((stack->top) == NULL || (stack->top)->next == NULL)
		return (false);
	node = stack->top;
	while (node->next != NULL)
	{
		tmp = node->next;
		if (tmp->next == NULL)
			break ;
		else
			node = node->next;
	}
	tmp = node->next;
	node->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
	return (true);
}

void	reverse_rotate_a(t_s *a)
{
	if (ft_reverse_rotate(a) == true)
		printf("rra\n");
}

void	reverse_rotate_b(t_s *b)
{
	if (ft_reverse_rotate(b) == true)
		printf("rrb\n");
}

void	reverse_rotate_ab(t_s *a, t_s *b)
{
	bool	as;
	bool	bs;

	as = ft_reverse_rotate(a);
	bs = ft_reverse_rotate(b);
	if (as == true && bs == true)
		printf("rrr\n");
	else if (as == false && bs == true)
		printf("rrb\n");
	else if (as == true && bs == false)
		printf("rra\n");
}
