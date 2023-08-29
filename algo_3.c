/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_235.c                                           :+:      :+:    :+:   */
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

int	verif_suite(t_liste *pile_a, int len)
{
	int	i;
	
	i = 0;
	while(i < len - 1)
	{
		if (pile_a[i].place != (i + 1))
			return (1);
		i++;
	}
	return (0);
}

void	algo_2(t_liste *pile_a, int *count)
{
	int	res;

	res = diff(pile_a[0].place, pile_a[1].place);
	if (res == -1)
		return ;
	else if (res == 1)
		sa(pile_a, count);
}

void	algo_3(t_liste *pile_a, int len, int *count)
{
	int	fst;
	int	scn;

	if (verif_suite(pile_a, len) == 0)
		return ;
	fst = diff(pile_a[1].place, pile_a[0].place);
	scn = diff(pile_a[1].place, pile_a[2].place);
	if (scn == 1)
	{
		sa(pile_a, count);
		if (fst == -1)
			rra(pile_a, len, count);
		if (fst == 2)
			ra(pile_a, len, count);
	}
	else if (fst == 1 && scn == 2)
		rra(pile_a, len, count);
	else if (fst == -1 && scn == -2)
		sa(pile_a, count);
	else if (fst == -2 && scn == -1)
		ra(pile_a, len, count);
}

void	algo_5(t_liste *pile_a, t_liste *pile_b, int len, int *count)
{
	int	i;

	i = 0;
	if (verif_suite(pile_a, len) == 0)
		return ;
	while (i < len)
	{
		if (pile_a[0].place > 3)
			pb(pile_a, pile_b, len, count);
		else
			ra(pile_a, len, count);
		i++;
	}
	algo_3(pile_a, len, count);
	if (pile_b[0].place == 4)
		sb(pile_b, count);
	pa(pile_a, pile_b, len, count);
	pa(pile_a, pile_b, len, count);
	ra(pile_a, len, count);
	ra(pile_a, len, count);	
}