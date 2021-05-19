// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap_fail2.c                                  :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/05/08 04:17:47 by dohelee           #+#    #+#             */
// /*   Updated: 2021/05/17 18:41:59 by dohelee          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"

// void	quick_atob(t_stack *a, t_stack *b, int len);
// void	quick_btoa(t_stack *a, t_stack *b, int len);

// int	get_pivot(t_stack *a, int len)
// {
// 	t_node *tmp;
// 	int i;
// 	int half;

// 	i = 0;
// 	tmp = a->top;
// 	while (!isEmpty(a) && i < len/2)
// 	{
// 		if (tmp->next == NULL)
// 			break ;
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	half = tmp->data;
// 	return (half);
// }

// void	print_stack(t_stack *a)
// {
// 	t_node *tmp;
	
// 	tmp = a->top;
// 	printf("stack : (TOP)");
// 	while (!isEmpty(a))
// 	{
// 		printf(" %d ", tmp->data);
// 		if (tmp->next == NULL)
// 			break ;
// 		tmp = tmp->next;
// 	}
// 	printf("(BOTTOM)\n");
// }

// int		stack_len(t_stack *stack)
// {
// 	int len;
// 	t_node *tmp;

// 	len = 0;
// 	tmp = stack->top;
// 	while (tmp != NULL)
// 	{
// 		len++;
// 		tmp = tmp->next;
// 	}
// 	return (len);
// }

// t_node *get_bottom(t_stack *stack)
// {
// 	t_node *tmp;

// 	if (isEmpty(stack))
// 		return (NULL);
// 	else
// 	{
// 		tmp = stack->top;
// 		while(tmp->next != NULL)
// 		{
// 			tmp = tmp->next;
// 		}
// 	}
// 	return (tmp);
	
// }

// void	quick_atob(t_stack *a, t_stack *b, int len)
// {
// 	int pivot;
// 	int i;
// 	int	ra_cnt;
// 	int	pb_cnt;
	
// 	i = 0;
// 	ra_cnt = 0;
// 	pb_cnt = 0;
// 	//printf("---atob : start---\n");
// 	if (len == 1)
// 	{
// 		//printf("---atob : end---\n");
// 		return ;
// 	}
// 	if (!isEmpty(a))
// 	{
// 		pivot = get_bottom(a)->data;
// 		pivot = (a->top)->data;
// 		pivot = get_pivot(a, len);
// 		//printf("pivot a : %d\n", pivot);
// 	}
// 	while (i < len)
// 	{
// 		if ((a->top)->data > pivot)
// 		{
// 			//printf("> %d : ", (a->top)->data);
// 			rotate_a(a);
// 			ra_cnt++;
// 		}
// 		else
// 		{
// 			//printf("> %d : ", (a->top)->data);
// 			push_b(a, b);
// 			pb_cnt++;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (i < ra_cnt)
// 	{
// 		reverse_rotate_a(a);
// 		i++;
// 	}
// 	//print_stack(a);
// 	//print_stack(b);
// 	//printf("ra_cnt : %d, pb_cnt : %d\n", ra_cnt, pb_cnt);
// 	if (ra_cnt != 0)
// 		quick_atob(a, b, ra_cnt);
// 	if (pb_cnt != 0)
// 		quick_btoa(a, b, pb_cnt);
	
// }

// void	quick_btoa(t_stack *a, t_stack *b, int len)
// {
// 	int pivot;
// 	int i;
// 	int	rb_cnt;
// 	int	pa_cnt;
// 	int tmp;
	
// 	i = 0;
// 	rb_cnt = 0;
// 	pa_cnt = 0;
// 	//printf("---btoa : start---\n");
// 	if (len == 1)
// 	{
// 		//printf("---btoa : end---\n");
// 		push_a(a, b);
// 		return ;
// 	}
// 	if (!isEmpty(b))
// 	{
// 		pivot = get_pivot(b, len);
// 		//printf("pivot b : %d\n", pivot);
// 	}
// 	//printf("orgin : len : %d, pa_cnt : %d, rb_cnt : %d\n", len, pa_cnt, rb_cnt);
// 	//print_stack(a);
// 	//print_stack(b);
// 	while (i < len)
// 	{
// 		if ((b->top)->data <= pivot)
// 		{
// 			//printf("> %d : ", (b->top)->data);
// 			rotate_b(b);
// 			rb_cnt++;
// 		}
// 		else
// 		{
// 			//printf("> %d : ", (b->top)->data);
// 			push_a(a, b);
// 			pa_cnt++;
// 		}
// 		i++;
// 	}
// 	//printf("before : len : %d, pa_cnt : %d, rb_cnt : %d\n", len, pa_cnt, rb_cnt);
// 	//print_stack(a);
// 	//print_stack(b);
// 	i = 0;
// 	tmp = rb_cnt;
// 	while(i < tmp)
// 	{
// 		reverse_rotate_b(b);
// 		if ((pa_cnt == 0) && (b->top)->data == pivot)
// 		{
// 			push_a(a, b);
// 			pa_cnt++;
// 			rb_cnt--;
// 		}
// 		i++;
// 	}
// 	//printf("after : len : %d, pa_cnt : %d, rb_cnt : %d\n", len, pa_cnt, rb_cnt);
// 	//print_stack(a);
// 	//print_stack(b);
// 	if (pa_cnt != 0)
// 		quick_atob(a, b, pa_cnt);
// 	if (rb_cnt != 0)
// 		quick_btoa(a, b, rb_cnt);
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
// 	quick_atob(&a, &b, len - 1);
// 	//quick_btoa(&a, &b, len - 1);

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
// 	printf("=========b===========\n");
// 	while (!isEmpty(&b))
// 	{
// 		printf("%d\n", tmp->data);
// 		if (tmp->next == NULL)
// 			break ;
// 		tmp = tmp->next;
// 	}

// 	//malloc 한거 프리해주기.
// }