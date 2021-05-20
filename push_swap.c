/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 04:17:47 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/21 00:22:04 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		list_free(t_s *stack)
{
	t_n *tmp;

	tmp = stack->top;
	while (!isempty(stack))
		pop(stack);
	return (-1);
}

int		stack_len(t_s *stack)
{
	int	len;
	t_n	*tmp;

	len = 0;
	tmp = stack->top;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int		errchk(char **argv)
{
	int i;

	i = 0;
	while (argv[i + 1] != NULL)
	{
		if (!chk_digit(argv[i + 1]))
			return (-1);
		if (!chk_type(argv[i + 1]))
			return (-1);
		i++;
	}
	if (!chk_double(argv))
		return (-1);
	return (1);
}

void	sort(t_s *a, t_s *b, int len)
{
	if (!sort_check_asc(a, len + 1))
	{
		if (len == 3)
			sort_3(a);
		else if (len == 5)
			sort_5(a, b);
		else
			quick_atob(a, b, len, 0);
	}
}

int		main(int argc, char **argv)
{
	t_s	a;
	t_s	b;
	int	i;
	int	len;

	i = 0;
	if (argc > 1)
	{
		while (argv[i + 1] != NULL)
			i++;
		if (errchk(argv) == -1)
			return (-1);
		init_stack(&a);
		init_stack(&b);
		len = i;
		while (i > 0)
		{
			if (push(&a, ft_atoi(argv[i--])) == NULL)
				return (list_free(&a));
		}
		sort(&a, &b, len);
		list_free(&a);
		list_free(&b);
	}
	return (0);
}
