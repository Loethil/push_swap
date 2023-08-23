/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:11:21 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/22 15:11:22 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_a(t_data *try)
{
	go_down(try, try->pile_a);
	if (try->pile_a[0] == 0)
	{
		try->pile_a[0] = try->pile_b[0];
		try->pile_b[0] = 0;
	}
	go_up(try, try->pile_b);
}

void	push_b(t_data *try)
{
	go_down(try, try->pile_b);
	if (try->pile_b[0] == 0)
	{
		try->pile_b[0] = try->pile_a[0];
		try->pile_a[0] = 0;
	}
	go_up(try, try->pile_a);
}

void	go_down(t_data *try, int *pile)
{
	int	i;

	i = 0;
	while (i < try->pilelen)
		i++;
	if (i > try->pilelen)
		return ;
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[0] = 0;
}

void	go_up(t_data *try, int	*pile)
{
	int	i;

	i = 0;
	while (i < try->pilelen - 1)
		i++;
	if (i > try->pilelen)
		return ;
	i = 0;
	while (i < try->pilelen - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i] = 0;
}