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

void	rotate_a(t_liste *pile_a, int count)
{
	int	i;
	int	c;

	i = 0;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	c = pile_a[i].value;
	while (i > 0)
	{
		pile_a[i].value = pile_a[i - 1].value;
		i--;
	}
	pile_a[0].value = c;
}
//-1 car argc compte de 1 a 6 et i de 0 a 5
void	rotate_b(t_liste *pile_b, int count)
{
	int	i;
	int	c;

	i = 0;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	c = pile_b[i].value;
	while (i > 0)
	{
		pile_b[i].value = pile_b[i - 1].value;
		i--;
	}
	pile_b[0].value = c;
}
void	rotate_r(t_liste *pile_a, t_liste *pile_b, int count)
{
	rotate_a(pile_a, count);
	rotate_b(pile_b, count);
}