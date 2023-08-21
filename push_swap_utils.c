/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:57:34 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/21 15:57:36 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	o;
	int	res;
	int	s;

	o = 0;
	res = 0;
	s = 0;
	while (str[o] == ' ' || (str[o] >= '\t' && str[o] <= '\r'))
		o++;
	if (str[o] == '-' || str[o] == '+')
	{
		if (str[o] == '-')
			s++;
		o++;
	}
	while (str[o] && (ft_isdigit(str[o]) == 1))
		res = res * 10 + str[o++] - '0';
	if (s > 1)
		return (0);
	else if (s == 1)
		return (-res);
	else
		return (res);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
