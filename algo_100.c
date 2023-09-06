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


void	go_to_b(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	int	j;
	int	i;

	liste->height = taille(pile_a);
	j = liste->height;
	i = 0;
	while (liste->cpt <= liste->maxchunk)
	{
		if (pile_a[i].place >= liste->minchunk
			&& pile_a[i].place <= liste->maxchunk)
		{
			while (i != 0)
			{
				ra(pile_a, liste);
				i--;
			}
			pb(pile_a, pile_b, liste);
			(liste->height)--;
			(liste->cpt)++;
			i = -1;
		}
		else if (pile_a[j].place >= liste->minchunk
			&& pile_a[j].place <= liste->maxchunk)
		{
			while (j != liste->height)
			{
				rra(pile_a, liste);
				j++;
			}
			rra(pile_a, liste);
			pb(pile_a, pile_b, liste);
			(liste->cpt)++;
			(liste->height)--;
		}
		i++;
		j--;
	}
}

void	tri_b(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	liste->height = taille(pile_b);
	j = liste->height;
	nbr = 100;
	while (nbr >= 1)
	{
		if (pile_b[i].place == nbr)
		{
			while (i != 0)
			{
				rb(pile_b, liste);
				i--;
			}
			pa(pile_a, pile_b, liste);
			j = liste->height;
			(liste->height)--;
			i = -1;
			nbr--;
		}
		else if (pile_b[j].place == nbr)
		{
			while (j != liste->height)
			{
				rrb(pile_b, liste);
				j++;
			}
			rrb(pile_b, liste);
			pa(pile_a, pile_b, liste);
			i = -1;
			(liste->height)--;
			nbr--;
		}
		i++;
		j--;
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
}
