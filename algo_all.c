/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:21:24 by mbatteux          #+#    #+#             */
/*   Updated: 2023/09/04 15:21:26 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	algo(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	int	i;
	int	nmb;

	i = 0;
	nmb = 1;
	while (pile_a[i].place)
	{
		if (pile_a[i].place == nmb)
		{
			while (i != 0)
			{
				ra(pile_a, liste);
				i--;
			}
			pb(pile_a, pile_b, liste);
			nmb++;
			i = -1;
		}
		i++;
	}
}

void	tri(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	int	i;
	int	nmb;

	i = 0;
	nmb = taille(pile_b) + 1;
	while (nmb != 0)
	{
		if (pile_b[i].place == nmb)
		{
			while (i != 0)
			{
				rb(pile_b, liste);
				i--;
			}
			pa(pile_a, pile_b, liste);
			i = -1;
			nmb--;
		}
		i++;
	}
}

void	algo_all(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	if (verif_suite(pile_a, liste) == 0)
		return ;
	algo(pile_a, pile_b, liste);
	tri(pile_a, pile_b, liste);
}
