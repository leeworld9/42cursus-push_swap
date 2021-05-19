/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 04:17:47 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/19 21:03:39 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_atob(t_stack *a, t_stack *b, int len);
void	quick_btoa(t_stack *a, t_stack *b, int len);
void	sort_3(t_stack *a);
void	sort_5(t_stack *a, t_stack *b);

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

void get_utils(t_utils *u, t_stack *stack, int len)
{
	t_node *tmp;
	int i;
	
	i = 0;
	u->sum = 0;
	tmp = stack->top;
	u->min = tmp->data;
	u->max = tmp->data;
	while (i < len)
	{
		u->sum += tmp->data;
		if (u->min > tmp->data)
			u->min = tmp->data;
		if (u->max < tmp->data)
			u->max = tmp->data;
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
		i++;
	}
	u->avg = (u->sum)/len;
}

int get_half(t_utils *u, t_stack *stack, int len)
{
	t_node *tmp;
	int i;
	int avg_under;
	int avg_below;
	int pivot;

	i = 0;
	tmp = stack->top;
	avg_under = u->min;
	avg_below = u->max;
	while (i < len)
	{
		if (tmp->data < u->max && tmp->data > u->min)
		{
			if (tmp->data == u->avg)
			{
				pivot = tmp->data;
				return (pivot);
			}
			else if (tmp->data < u->avg)
			{
				if (tmp->data > avg_under)
					avg_under = tmp->data;
			}
			else if (tmp->data > u->avg)
			{
				if (tmp->data < avg_below)
					avg_below = tmp->data;
			}
		}
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	if (avg_under == u->min)
		pivot = avg_below;
	else if (avg_below == u->max)
		pivot = avg_under;
	return (pivot);
}

int	get_pivot(t_stack *stack, int len, char type)
{
	t_node *tmp;
	t_utils u;
	int i;
	int pivot;
	get_utils(&u, stack, len);
	i = 0;
	if (len == 2) // 확인하고 수정 필요...?
	{
		if (type == 'a')
			return (u.max);
		else
			return (u.min);
	}
	//printf("min :%d, max : %d, avg : %d\n", u.min, u.max, u.avg);
	pivot = get_half(&u, stack, len);
	//printf("pivot: %d\n", pivot);
	return (pivot);
}

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

bool 	sort_check_a(t_stack *stack, int len)
{
	t_node *tmp;
	int res;
	int i;

	i = 0;
	res = true;
	tmp = stack->top;
	while (i < len)
	{
		if (tmp->next != NULL)
		{
			if (tmp->data < (tmp->next)->data)
				tmp = tmp->next;
			else
				break;
		}
		i++;
	}
	if (i == len)
		res = true;
	else
		res = false;
	//printf("len :%d, sort_result_a: %d\n", len, res);
	return (res);
}

bool 	sort_check_b(t_stack *stack, int len)
{
	t_node *tmp;
	int res;
	int i;

	i = 0;
	res = true;
	tmp = stack->top;
	while (i < len)
	{
		if (tmp->next != NULL)
		{
			if (tmp->data > (tmp->next)->data)
				tmp = tmp->next;
			else
				break;
		}
		i++;
	}
	if (i == len)
		res = true;
	else
		res = false;
	//printf("len :%d, sort_result_b: %d\n", len, res);
	return (res);
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
	if (len <= 1)
	{
		//printf("---atob : end---\n");
		return ;
	}
	if (len == 2)
	{
		if ((a->top)->data > ((a->top)->next)->data)
			swap_a(a);
		return ;
	}
	if (sort_check_a(a, len))
		return ;
	if (!isEmpty(a))
	{
		pivot = get_pivot(a, len, 'a');
		//printf("pivot a : %d\n", pivot);
	}
	while (i < len)
	{
		if ((a->top)->data > pivot)
		{
			//printf("> %d : ", (a->top)->data);
			rotate_a(a);
			ra_cnt++;
		}
		else
		{
			//printf("> %d : ", (a->top)->data);
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
	//if (ra_cnt != 0)
		quick_atob(a, b, ra_cnt);
	//if (pb_cnt != 0)
		quick_btoa(a, b, pb_cnt);
}

void	quick_btoa(t_stack *a, t_stack *b, int len)
{
	int pivot;
	int i;
	int	rb_cnt;
	int	pa_cnt;
	int tmp;
	
	i = 0;
	rb_cnt = 0;
	pa_cnt = 0;
	//printf("---btoa : start---\n");
	if (len <= 1)
	{
		//printf("---btoa : end---\n");
		if (len == 1)
			push_a(a, b);
		return ;
	}
	if (sort_check_b(b, len))
	{
		int i = 0;
		while(i < len)
		{
			push_a(a, b);
			i++;
		}
		return ;
	}
	if (!isEmpty(b))
	{
		pivot = get_pivot(b, len, 'b');
		//printf("pivot b : %d\n", pivot);
	}
	//printf("orgin : len : %d, pa_cnt : %d, rb_cnt : %d\n", len, pa_cnt, rb_cnt);
	//print_stack(a);
	//print_stack(b);
	while (i < len)
	{
		if ((b->top)->data <= pivot)
		{
			//printf("> %d : ", (b->top)->data);
			rotate_b(b);
			rb_cnt++;
		}
		else
		{
			//printf("> %d : ", (b->top)->data);
			push_a(a, b);
			pa_cnt++;
		}
		i++;
	}
	//printf("before : len : %d, pa_cnt : %d, rb_cnt : %d\n", len, pa_cnt, rb_cnt);
	//print_stack(a);
	//print_stack(b);
	i = 0;
	tmp = rb_cnt;
	while(i < tmp)
	{
		reverse_rotate_b(b);
		if ((pa_cnt == 0) && (b->top)->data == pivot)
		{
			push_a(a, b);
			pa_cnt++;
			rb_cnt--;
		}
		i++;
	}
	//printf("after : len : %d, pa_cnt : %d, rb_cnt : %d\n", len, pa_cnt, rb_cnt);
	//print_stack(a);
	//print_stack(b);
	//if (pa_cnt != 0)
		quick_atob(a, b, pa_cnt);
	//if (rb_cnt != 0)
		quick_btoa(a, b, rb_cnt);
}

void	sort_3(t_stack *a)
{
	t_node *top;
	t_node *middle;
	t_node *bottom;

	while(!sort_check_a(a, 3))
	{
		top = a->top;
		middle = top->next;
		bottom = middle->next;
		if (top->data > middle->data) // 2 1 3 , 3 2 1, 3 1 2
		{
			if (middle->data > bottom->data) // 3 2 1
				swap_a(a);
			else // 2 1 3 , 3 1 2
			{
				if (top->data > bottom->data) // 3 1 2
					rotate_a(a);
				else // 2 1 3
					swap_a(a);
			}
		}
		else // 1 3 2, 2 3 1 
		{
			if (top->data > bottom->data) // 2 3 1
				reverse_rotate_a(a);
			else // 1 3 2
				swap_a(a);
		}
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	t_node *a_top;
	t_node *b_top;
	t_node *b_bottom;
	t_utils u;

	if (sort_check_a(a, 5))
		return ;
	get_utils(&u, a, 5);
	while (!isEmpty(a))
	{
		a_top = a->top;
		//printf("stack_len(b) : %d\n", stack_len(b));
		//printf("a_top:%d, min:%d, max:%d\n", a_top->data, u.min, u.max);
		if (stack_len(b) == 2)
			break ;
		if ((a->top)->data == u.min || (a->top)->data == u.max)
			push_b(a, b);
		else
			rotate_a(a);
	}
	b_top = b->top;
	b_bottom = a_top->next;

	if (b_bottom->data < b_top->data)
		swap_b(b);
	sort_3(a);
	//printf("min:%d, max:%d\n", u.min, u.max);
	push_a(a, b);
	push_a(a, b);
	rotate_a(a);
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
	len = 0;
	//인자타입, 오버플로우 처리, 안들어온 경우 처리등 해줘야함. 
	while (argv[len + 1] != NULL)
		len++;
	
	i = len;
	while (i > 0)
	{
		push(&a, atoi(argv[i]));
		i--;
	}
	if (len == 3)
		sort_3(&a);
	else if (len == 5)
		sort_5(&a, &b);
	else
		quick_atob(&a, &b, len);

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

	//malloc 한거 프리해주기.
}