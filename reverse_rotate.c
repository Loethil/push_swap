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

void	reverse_rotate_a(t_data *try)
{
	int	i;
	int	c;

	i = 0;
	c = try->pile_a[0];
	while (i < try->pilelen - 1)
		i++;
	if (i > try->pilelen)
		return ;
	i = 0;
	while (i < try->pilelen - 1)
	{
		try->pile_a[i] = try->pile_a[i + 1];
		i++;
	}
	try->pile_a[i] = c;
}
//-1 car argc compte de 1 a 6 et i de 0 a 5
void	reverse_rotate_b(t_data *try)
{
	int	i;
	int	c;

	i = 0;
	c = try->pile_b[0];
	while (i < try->pilelen - 1)
		i++;
	if (i > try->pilelen)
		return ;
	i = 0;
	while (i < try->pilelen - 1)
	{
		try->pile_b[i] = try->pile_b[i + 1];
		i++;
	}
	try->pile_b[i] = c;
}
void	reverse_rotate_r(t_data *try)
{
	reverse_rotate_a(try);
	reverse_rotate_b(try);
}
