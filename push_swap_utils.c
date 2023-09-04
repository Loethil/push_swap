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
	if (str[o] == '-')
	{
		s++;
		o++;
	}
	while (str[o] && (ft_isdigit(str[o]) == 0))
		res = res * 10 + str[o++] - '0';
	if (s > 1)
		return (0);
	else if (s == 1)
		return (-res);
	else
		return (res);
}

int	taille(t_liste *pile_a)
{
	int	i;

	i = 0;
	while (pile_a[i].place != 0)
		i++;
	return (i);
}

int	diff(int a, int b)
{
	int	res;

	res = a - b;
	return (res);
}

int	oppenheimer(t_liste *pile_a, t_liste *pile_b)
{
	free (pile_a);
	free (pile_b);
	exit (0);
}

int	verif_argv(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '-')
			i++;
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
	}
	return (0);
}	

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}
