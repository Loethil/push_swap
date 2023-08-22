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

void	swap_a(t_data *try)
{
	int	c;

	c = try->pile_a[1];
	try->pile_a[1] = try->pile_a[0];
	try->pile_a[0] = c;
}

void	swap_b(t_data *try)
{
	int	c;

	c = try->pile_b[1];
	try->pile_b[1] = try->pile_b[0];
	try->pile_b[0] = c;
}

void	swap_s(t_data *try)
{
	int	c;
	int	d;

	d = try->pile_b[1];
	c = try->pile_a[1];
	try->pile_a[1] = try->pile_a[0];
	try->pile_b[1] = try->pile_b[0];
	try->pile_a[0] = c;
	try->pile_b[0] = d;
}
