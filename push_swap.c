/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 04:17:47 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/17 03:06:09 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_atob(t_stack *a, t_stack *b, int len);
void	quick_btoa(t_stack *a, t_stack *b, int len);

void	print_stack(t_stack *a)
{
	t_node *tmp;
	
	tmp = a->top;
	printf("stack : (TOP)");
	while (!isEmpty(a))
	{
		printf(" %d ", tmp->data);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	printf("(BOTTOM)\n");
}

int		stack_len(t_stack *stack)
{
	int len;
	t_node *tmp;

	len = 0;
	tmp = stack->top;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

t_node *get_bottom(t_stack *stack)
{
	t_node *tmp;

	if (isEmpty(stack))
		return (NULL);
	else
	{
		tmp = stack->top;
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
	}
	return (tmp);
	
}

void	quick_atob(t_stack *a, t_stack *b, int len)
{
	int pivot;
	int i;
	int	ra_cnt;
	int	pb_cnt;
	
	i = 0;
	ra_cnt = 0;
	pb_cnt = 0;
	//printf("---atob : start---\n");
	if (len == 1)
	{
		//printf("---atob : end---\n");
		return ;
	}
	if (!isEmpty(a))
	{
		//pivot = get_bottom(a)->data;
		pivot = (a->top)->data;
	}
	while (i < len)
	{
		if ((a->top)->data > pivot)
		{
			//printf("> %d : ", a->top->data);
			rotate_a(a);
			ra_cnt++;
		}
		else
		{
			//printf("> %d : ", a->top->data);
			push_b(a, b);
			pb_cnt++;
		}
		i++;
	}
	i = 0;
	while (i < ra_cnt)
	{
		reverse_rotate_a(a);
		i++;
	}
	//print_stack(a);
	//print_stack(b);
	//printf("ra_cnt : %d, pb_cnt : %d\n", ra_cnt, pb_cnt);

	if (ra_cnt != 0)
		quick_atob(a, b, ra_cnt);
	if (pb_cnt != 0)
		quick_btoa(a, b, pb_cnt);
	
}

void	quick_btoa(t_stack *a, t_stack *b, int len)
{
	int pivot;
	int i;
	int	rb_cnt;
	int	pa_cnt;
	
	i = 0;
	rb_cnt = 0;
	pa_cnt = 0;
	printf("---btoa : start---\n");
	if (len == 1)
	{
		printf("---btoa : end---\n");
		push_a(a, b);
		return ;
	}
	if (!isEmpty(b))
	{
		//pivot = get_bottom(b)->data;
		pivot = (b->top)->data;
	}
	while (i < len)
	{
		if ((b->top)->data <= pivot)
		{
			printf("> %d : ", b->top->data);
			rotate_b(b);
			rb_cnt++;
		}
		else
		{
			printf("> %d : ", b->top->data);
			push_a(a, b);
			pa_cnt++;
		}
		i++;
	}
	i = 0;
	while (i < rb_cnt)
	{
		reverse_rotate_b(b);
		i++;
	}
	print_stack(a);
	print_stack(b);
	printf("len : %d, pa_cnt : %d, rb_cnt : %d\n",len, pa_cnt, rb_cnt);
	if (pa_cnt != 0)
		quick_atob(a, b, pa_cnt);
	if (pa_cnt == 0 && rb_cnt == len) // 이분은 제거 가능할꺼 같은데... (bottom으로 바꾸면 무한 루프 ㅅㅂ)
	{
		push_a(a, b);
		quick_btoa(a, b, rb_cnt - 1);
	}
	else if (rb_cnt != 0)
		quick_btoa(a, b, rb_cnt);
}

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	t_node *tmp;
	int i;
	int len;

	init_stack(&a);
	init_stack(&b);
	len = 1;
	while (argv[len] != NULL)
		len++;
	
	i = len - 1;
	while (i > 0)
	{
		push(&a, atoi(argv[i]));
		i--;
	}
	quick_atob(&a, &b, len - 1);
	//quick_btoa(&a, &b, len - 1);

	printf("=========a===========\n");
	tmp = a.top;
	while (!isEmpty(&a))
	{
		printf("%d\n", tmp->data);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	tmp = b.top;
	printf("=========b===========\n");
	while (!isEmpty(&b))
	{
		printf("%d\n", tmp->data);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
}