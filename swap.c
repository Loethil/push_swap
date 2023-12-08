/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:28:13 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/22 14:28:15 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_liste *pile_a)
{
	int	c;

	c = pile_a[1].place;
	pile_a[1].place = pile_a[0].place;
	pile_a[0].place = c;
	write(1, "sa\n", 3);
}

void	sb(t_liste *pile_b)
{
	int	c;

	c = pile_b[1].place;
	pile_b[1].place = pile_b[0].place;
	pile_b[0].place = c;
	write(1, "sb\n", 3);
}

void	ss(t_liste *pile_a, t_liste *pile_b)
{
	sa(pile_a);
	sb(pile_b);
	write(1, "ss\n", 3);
}
