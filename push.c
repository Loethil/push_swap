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

void	push_a(t_liste *pile_a, t_liste *pile_b, int count)
{
	go_down(pile_a, count);
	if (pile_a[0].value == 0)
	{
		pile_a[0].value = pile_b[0].value;
		pile_b[0].value = 0;
	}
	go_up(pile_b, count);
}

void	push_b(t_liste *pile_a, t_liste *pile_b, int count)
{
	go_down(pile_b, count);
	if (pile_b[0].value == 0)
	{
		pile_b[0].value = pile_a[0].value;
		pile_a[0].value = 0;
	}
	go_up(pile_a, count);
}

void	go_down(t_liste *pile, int count)
{
	int	i;

	i = 0;
	while (i < count)
		i++;
	if (i > count)
		return ;
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[0].value = 0;
}

void	go_up(t_liste *pile, int count)
{
	int	i;

	i = 0;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	i = 0;
	while (i < count - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i].value = 0;
}
