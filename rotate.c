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

void	rotate_a(t_data *try, int *pile)
{
	int	i;
	int	c;

	i = 0;
	while (i < try->pilelen - 1)
		i++;
	if (i > try->pilelen)
		return ;
	c = pile[i];
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[0] = c;
}
//-1 car argc compte de 1 a 6 et i de 0 a 5
void	rotate_b(t_data *try, int *pile)
{
	int	i;
	int	c;

	i = 0;
	while (i < try->pilelen - 1)
		i++;
	if (i > try->pilelen)
		return ;
	c = pile[i];
	while (i > 0)
	{
		pile[i] = pile[i - 1];
		i--;
	}
	pile[0] = c;
}
void	rotate_r(t_data *try, int *pile_a, int *pile_b)
{
	rotate_a(try, pile_a);
	rotate_b(try, pile_b);
}