/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:28:46 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/31 15:28:48 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define B_TWIN pile_a[i].place >= liste->minchunk\
	&& pile_a[i].place <= liste->maxchunk



void	go_to_b(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	int	i;

	i = 0;
	while (liste->cpt <= liste->maxchunk)
	{
		if (B_TWIN && i <= 49)
		{
			while (i != 0)
			{
				ra(pile_a, liste);
				i--;
			}
			pb(pile_a, pile_b, liste);
			(liste->cpt)++;
		}
		if (B_TWIN && i >= 50)
		{
			while (i != 100)
			{
				rra(pile_a, liste);
				i++;
			}
			rra(pile_a, liste);
			pb(pile_a, pile_b, liste);
			i = -1;
			(liste->cpt)++;
		}
		i++;
	}
}

// void	tri_b(t_liste *pile_a, t_liste *pile_b, t_struct liste)
// {

// }

void	algo_100(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	liste->cpt = 1;
	liste->minchunk = 0;
	liste->maxchunk = liste->len / 5;
	while (liste->maxchunk <= liste->len)
	{
		go_to_b(pile_a, pile_b, liste);
		liste->maxchunk += liste->len / 5;
		liste->minchunk += liste->len / 5;
	}
	// tri_b(pile_a, pile_b, liste);
	// while (verif_suite(pile_a, liste) != 0)
	// {

	// }
}
