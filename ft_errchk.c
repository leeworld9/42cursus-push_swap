/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errchk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 01:46:11 by dohelee           #+#    #+#             */
/*   Updated: 2021/05/20 22:08:04 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	chk_double(char **argv)
{
	int	i;
	int	j;
	int	cnt;

	i = 1;
	while (argv[i] != NULL)
	{
		cnt = 0;
		j = 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				cnt++;
			j++;
		}
		if (cnt != 1)
		{
			ft_putstr_fd("Error\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	chk_digit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd("Error\n", 2);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	chk_type(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(str) == 0 || ft_atoi(str) == -1)
	{
		if (*str == '-')
			i++;
		if (ft_strlen(str + i) > 1 || *(str + i) == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			return (false);
		}
	}
	return (true);
}
