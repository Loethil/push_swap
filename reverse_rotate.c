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

void	ra(t_liste *pile_a, int count)
{
	int	i;
	int	c;

	i = 0;
	c = pile_a[0].value;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	i = 0;
	while (i < count - 1)
	{
		pile_a[i].value = pile_a[i + 1].value;
		i++;
	}
	pile_a[i].value = c;
}
//-1 car argc compte de 1 a 6 et i de 0 a 5
void	rb(t_liste *pile_b, int count)
{
	int	i;
	int	c;

	i = 0;
	c = pile_b[0].value;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	i = 0;
	while (i < count - 1)
	{
		pile_b[i].value = pile_b[i + 1].value;
		i++;
	}
	pile_b[i].value = c;
}
void	rr(t_liste *pile_a, t_liste *pile_b, int count)
{
	ra(pile_a, count);
	rb(pile_b, count);
}
