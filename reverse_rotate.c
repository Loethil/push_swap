/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:44:34 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/23 13:44:35 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_liste *pile_a, int count)
{
	int	i;
	int	c;

	i = 0;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	c = pile_a[i].place;
	while (i > 0)
	{
		pile_a[i].place = pile_a[i - 1].place;
		i--;
	}
	pile_a[0].place = c;
	printf("rra\n");
}
//-1 car argc compte de 1 a 6 et i de 0 a 5
void	rrb(t_liste *pile_b, int count)
{
	int	i;
	int	c;

	i = 0;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	c = pile_b[i].place;
	while (i > 0)
	{
		pile_b[i].place = pile_b[i - 1].place;
		i--;
	}
	pile_b[0].place = c;
	printf("rrb\n");
}
void	rrr(t_liste *pile_a, t_liste *pile_b, int count)
{
	rra(pile_a, count);
	rrb(pile_b, count);
	printf("rrr\n");
}
