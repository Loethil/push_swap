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

int	diff(int a, int b)
{
	int	res;

	res = a - b;
	return (res);
}

void	algo_3(t_liste *pile_a, t_liste *pile_b, int count)
{
	int	fst;
	int	scn;

	(void)pile_b;
	fst = diff(pile_a[1].place, pile_a[0].place);
	scn = diff(pile_a[1].place, pile_a[2].place);
	if (scn == 1)
	{
		sa(pile_a);
		if (fst == -1)
			rra(pile_a, count);		if (fst == 2)
			ra(pile_a, count);
	}
	else if (fst == 1 && scn == 2)
		rra(pile_a, count);
	else if (fst == -1 && scn == -2)
		sa(pile_a);
	else if (fst == -2 && scn == -1)
		ra(pile_a, count);
}
