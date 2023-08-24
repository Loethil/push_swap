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

void	swap_a(t_liste *pile_a)
{
	int	c;

	c = pile_a[1].value;
	pile_a[1].value = pile_a[0].value;
	pile_a[0].value = c;
}

void	swap_b(t_liste *pile_b)
{
	int	c;

	c = pile_b[1].value;
	pile_b[1].value = pile_b[0].value;
	pile_b[0].value = c;
}

void	swap_s(t_liste *pile_a, t_liste *pile_b)
{
	int	c;
	int	d;

	d = pile_b[1].value;
	c = pile_a[1].value;
	pile_a[1].value = pile_a[0].value;
	pile_b[1].value = pile_b[0].value;
	pile_a[0].value = c;
	pile_b[0].value = d;
}
