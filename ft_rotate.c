/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:10:34 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/20 22:07:54 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_rotate(t_s *stack)
{
	t_n	*node;
	t_n	*tmp;

	if ((stack->top) == NULL || (stack->top)->next == NULL)
		return (false);
	tmp = stack->top;
	node = tmp->next;
	stack->top = node;
	while (node->next != NULL)
		node = node->next;
	node->next = tmp;
	tmp->next = NULL;
	return (true);
}

void	rotate_a(t_s *a)
{
	if (ft_rotate(a) == true)
		printf("ra\n");
}

void	rotate_b(t_s *b)
{
	if (ft_rotate(b) == true)
		printf("rb\n");
}

void	rotate_ab(t_s *a, t_s *b)
{
	bool	as;
	bool	bs;

	as = ft_rotate(a);
	bs = ft_rotate(b);
	if (as == true && bs == true)
		printf("rr\n");
	else if (as == false && bs == true)
		printf("rb\n");
	else if (as == true && bs == false)
		printf("ra\n");
}
