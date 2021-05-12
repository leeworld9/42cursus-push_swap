/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 21:34:34 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/12 17:27:44 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void init_stack(t_stack *stack)
{
    stack->top = NULL;
}
 
int isEmpty(t_stack *stack)
{
    if (stack->top == NULL)
        return (1); //top이 NULL이면 빈 상태
    else
        return (0);
}

t_node *push(t_stack *stack, int data)
{
    t_node *now;
    
    now = (t_node *)malloc(sizeof(t_node)); //노드 생성
    if (now == NULL)
    {
        //push malloc 에러
        return (NULL);
    }
    now->data = data;
    now->next = stack->top; //now의 next링크를 현재 top으로 설정   
    stack->top = now;   //스택의 맨 앞은 now로 설정
    return (stack->top);
}

int pop(t_stack *stack)
{
    t_node *now;
    int ret;
	
    if (isEmpty(stack))
        return (0);
    now = stack->top;//now를 top으로 설정
    ret = now->data;//꺼낼 값은 now의 data로 설정
 
    stack->top = now->next;//top을 now의 next로 설정
    free(now);//필요없으니 메모리 해제
    return (ret);
}
