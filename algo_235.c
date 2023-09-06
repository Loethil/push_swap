/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_235.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:58:52 by mbatteux          #+#    #+#             */
/*   Updated: 2023/09/06 16:23:12 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	verif_suite(t_liste *pile_a, t_struct *liste)
{
	int	i;

	i = 0;
	while (i < liste->len - 1)
	{
		if (pile_a[i].place != (i + 1))
			return (1);
		i++;
	}
	return (0);
}

void	algo_2(t_liste *pile_a)
{
	int	res;

	res = diff(pile_a[0].place, pile_a[1].place);
	if (res == -1)
		return ;
	else if (res == 1)
		sa(pile_a);
}

void	algo_3(t_liste *pile_a, t_struct *liste)
{
	int	fst;
	int	scn;

	if (verif_suite(pile_a, liste) == 0)
		return ;
	fst = diff(pile_a[1].place, pile_a[0].place);
	scn = diff(pile_a[1].place, pile_a[2].place);
	if (scn == 1)
	{
		sa(pile_a);
		if (fst == -1)
			rra(pile_a, liste);
		if (fst == 2)
			ra(pile_a, liste);
	}
	else if (fst == 1 && scn == 2)
		rra(pile_a, liste);
	else if (fst == -1 && scn == -2)
		sa(pile_a);
	else if (fst == -2 && scn == -1)
		ra(pile_a, liste);
}

void	algo_5(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	int	i;

	i = 0;
	if (verif_suite(pile_a, liste) == 0)
		return ;
	while (i < liste->len)
	{
		if (pile_a[0].place > 3)
			pb(pile_a, pile_b, liste);
		else
			ra(pile_a, liste);
		i++;
	}
	algo_3(pile_a, liste);
	if (pile_b[0].place == 4)
		sb(pile_b);
	pa(pile_a, pile_b, liste);
	pa(pile_a, pile_b, liste);
	ra(pile_a, liste);
	ra(pile_a, liste);
}
