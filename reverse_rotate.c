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

void	rra(t_liste *pile_a, t_struct *liste)
{
	int	i;
	int	c;

	i = 0;
	while (i < liste->len - 1)
	{
		if (pile_a[i + 1].place == 0)
			break ;
		i++;
	}
	c = pile_a[i].place;
	while (i > 0)
	{
		pile_a[i].place = pile_a[i - 1].place;
		i--;
	}
	pile_a[0].place = c;
	write(1, "rra\n", 4);
}
//-1 car argc compte de 1 a 6 et i de 0 a 5

void	rrb(t_liste *pile_b, t_struct *liste)
{
	int	i;
	int	c;

	i = 0;
	while (i < liste->len - 1)
	{
		if (pile_b[i + 1].place == 0)
			break ;
		i++;
	}
	c = pile_b[i].place;
	while (i > 0)
	{
		pile_b[i].place = pile_b[i - 1].place;
		i--;
	}
	pile_b[0].place = c;
	write(1, "rrb\n", 4);
}

void	rrr(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	rra(pile_a, liste);
	rrb(pile_b, liste);
	write(1, "rrr\n", 4);
}
