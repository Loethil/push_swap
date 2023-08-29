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

void	pa(t_liste *pile_a, t_liste *pile_b, int len, int *count)
{
	go_down(pile_a, len);
	if (pile_a[0].place == 0)
	{
		pile_a[0].place = pile_b[0].place;
		pile_b[0].place = 0;
	}
	go_up(pile_b, len);
	printf("pa\n");
	(*count)++;
}

void	pb(t_liste *pile_a, t_liste *pile_b, int len, int *count)
{
	go_down(pile_b, len);
	if (pile_b[0].place == 0)
	{
		pile_b[0].place = pile_a[0].place;
		pile_a[0].place = 0;
	}
	go_up(pile_a, len);
	printf("pb\n");
	(*count)++;
}
//permet de faire descendre les maillons
void	go_down(t_liste *pile, int len)
{
	int	i;

	i = 0;
	while (i < len)
		i++;
	if (i > len)
		return ;
	while (i > 0)
	{
		pile[i].place = pile[i - 1].place;
		i--;
	}
	pile[0].place = 0;
}
//permet de monterles maillons
void	go_up(t_liste *pile, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
		i++;
	if (i > len)
		return ;
	i = 0;
	while (i < len - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i].place = 0;
}
