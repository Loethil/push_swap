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
#define ITAB pile_a[i].place >= liste->minchunk\
	&& pile_a[i].place <= liste->maxchunk
#define JTAB pile_a[j].place >= liste->minchunk\
	&& pile_a[j].place <= liste->maxchunk

void	go_to_b(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	int	i;
	int	j;

	i = 0;
	liste->height = taille(pile_a);
	j = liste->height;
	while (liste->cpt <= liste->maxchunk)
	{
		if (ITAB)
		{
			while (i != 0)
			{
				ra(pile_a, liste);
				i--;
			}
			pb(pile_a, pile_b, liste);
			(liste->cpt)++;
			(liste->height)--;
			i = -1;
		}
		else if (JTAB)
		{
			while (j != liste->height)
			{
				rra(pile_a, liste);
				j++;
			}
			rra(pile_a, liste);
			pb(pile_a, pile_b, liste);
			(liste->height)--;
			(liste->cpt)++;
		}
		i++;
		j--;
	}
}

void	tri_b(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	int	i;
	// int	j;
	int	nmb;

	i = 0;
	// liste->height = taille(pile_b);
	// j = liste->height;
	nmb = 100;
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
			(liste->height)--;
			i = -1;
			nmb--;
		}
		// else if (pile_b[j].place == nmb)
		// {
		// 	while (j != liste->height)
		// 	{
		// 		rrb(pile_b, liste);
		// 		j++;
		// 	}
		// 	rrb(pile_b, liste);
		// 	pa(pile_a, pile_b, liste);
		// 	(liste->height)--;
		// 	nmb--;
		// }
		i++;
		// j--;
	}
}

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
	tri_b(pile_a, pile_b, liste);
	// while (verif_suite(pile_a, liste) != 0)
	// {

	// }
}
