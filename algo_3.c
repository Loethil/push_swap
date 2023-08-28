/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:58:52 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/28 13:58:54 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	algo_3(t_liste *pile_a, t_liste *pile_b)
{
	int	fst;
	int	scn;

	fst = diff(pile_a[0].place, pile_a[1].place, res);
	scn = diff(pile_a[2].place, pile_a[1].place, res);
	if (fst == -1 && scn == 1)
	{
		sa(pile_a);
		rra(pile_a);
	}
}

int	diff(int a, int b, int res)
{
	res = a - b;
	return (res);
}