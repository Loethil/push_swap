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

void	reverse_rotate_a(t_data *try, int *pile)
{
	int	i;
	int	c;

	i = 0;
	c = pile[0];
	while (i < try->pilelen - 1)
		i++;
	if (i > try->pilelen)
		return ;
	i = 0;
	while (i < try->pilelen - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i] = c;
}
//-1 car argc compte de 1 a 6 et i de 0 a 5
void	reverse_rotate_b(t_data *try, int *pile)
{
	int	i;
	int	c;

	i = 0;
	c = pile[0];
	while (i < try->pilelen - 1)
		i++;
	if (i > try->pilelen)
		return ;
	i = 0;
	while (i < try->pilelen - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i] = c;
}
void	reverse_rotate_r(t_data *try, int *pile_a, int *pile_b)
{
	reverse_rotate_a(try, pile_a);
	reverse_rotate_b(try, pile_b);
}
