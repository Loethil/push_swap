/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:13:40 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/23 13:13:41 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_liste *pile_a, t_struct *liste)
{
	int	i;
	int	c;

	i = 0;
	c = pile_a[0].place;
	while (i < liste->len - 1)
	{
		if (pile_a[i + 1].place == 0)
			break ;
		pile_a[i].place = pile_a[i + 1].place;
		i++;
	}
	pile_a[i].place = c;
	write(1, "ra\n", 3);
}
//-1 car argc compte de 1 a 6 et i de 0 a 5

void	rb(t_liste *pile_b, t_struct *liste)
{
	int	i;
	int	c;

	i = 0;
	c = pile_b[0].place;
	while (i < liste->len - 1)
	{
		if (pile_b[i + 1].place == 0)
			break ;
		pile_b[i].place = pile_b[i + 1].place;
		i++;
	}
	pile_b[i].place = c;
	write(1, "rb\n", 3);
}

void	rr(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	ra(pile_a, liste);
	rb(pile_b, liste);
	write(1, "rr\n", 3);
}
