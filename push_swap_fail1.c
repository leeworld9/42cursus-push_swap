// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap_fail1.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/05/08 04:17:47 by dohelee           #+#    #+#             */
// /*   Updated: 2021/05/17 18:37:22 by dohelee          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// static t_node *min(t_stack *a)
// {
// 	t_node *tmp;
// 	t_node *min_node;
// 	int distance;

// 	tmp = a->top;
// 	min_node = tmp;
// 	distance = 0;
// 	while (!isEmpty(a))
// 	{	
// 		distance++;
// 		if (min_node->data > tmp->data)
// 		{
// 			min_node = tmp;
// 			min_node->distance = distance;
// 		}
// 		if (tmp->next == NULL)
// 			break ;
// 		tmp = tmp->next;
// 	}
// 	return (min_node);
// }

// void	push_swap(t_stack *a, t_stack *b, int len)
// {
// 	t_node *a_tmp;
// 	t_node *b_tmp;
// 	t_node *min_node;

// 	while (!isEmpty(a))
// 	{	
// 		min_node = min(a);
// 		while (a->top != min_node)
// 		{
// 			if ((len / 2) < min_node->distance)
// 			{
// 				reverse_rotate_a(a);
// 			}
// 			else
// 				rotate_a(a);
// 		}
// 		push_b(a, b);
// 		len--;
// 	}
	
// 	b_tmp = b->top;
// 	while (!isEmpty(b))
// 	{
// 		push_a(a, b);
// 		if (b_tmp->next != NULL)
// 			b_tmp = b_tmp->next;
// 	}
	
// }

// int main(int argc, char **argv)
// {
// 	t_stack a;
// 	t_stack b;
// 	t_node *tmp;
// 	int i;
// 	int len;

// 	init_stack(&a);
// 	init_stack(&b);

// 	len = 1;
// 	while (argv[len] != NULL)
// 		len++;
	
// 	i = len - 1;
// 	while (i > 0)
// 	{
// 		push(&a, atoi(argv[i]));
// 		i--;
// 	}
	
// 	push_swap(&a, &b, len - 1);

// 	printf("=========a===========\n");
// 	tmp = a.top;
// 	while (!isEmpty(&a))
// 	{
// 		printf("%d\n", tmp->data);
// 		if (tmp->next == NULL)
// 			break ;
// 		tmp = tmp->next;
// 	}
// 	tmp = b.top;
// 		printf("=========b===========\n");
// 	while (!isEmpty(&b))
// 	{
// 		printf("%d\n", tmp->data);
// 		if (tmp->next == NULL)
// 			break ;
// 		tmp = tmp->next;
// 	}
// }