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

void	rotate_a(t_data *try)
{
	int	i;
	int	c;

	i = 0;
	while (i < try->pilelen - 1)
		i++;
	if (i > try->pilelen)
		return ;
	c = try->pile_a[i];
	while (i > 0)
	{
		try->pile_a[i] = try->pile_a[i - 1];
		i--;
	}
	try->pile_a[0] = c;
}
//-1 car argc compte de 1 a 6 et i de 0 a 5
void	rotate_b(t_data *try)
{
	int	i;
	int	c;

	i = 0;
	while (i < try->pilelen - 1)
		i++;
	if (i > try->pilelen)
		return ;
	c = try->pile_b[i];
	while (i > 0)
	{
		try->pile_b[i] = try->pile_b[i - 1];
		i--;
	}
	try->pile_b[0] = c;
}
void	rotate_r(t_data *try)
{
	rotate_a(try);
	rotate_b(try);
}