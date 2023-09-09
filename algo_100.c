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
#define CHUNK 6

void	go_to_b(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	liste->height = taille(pile_a);
	liste->e = liste->height;
	liste->f = 0;
	while (liste->cpt <= liste->maxchunk)
	{
		if (pile_a[liste->f].place >= liste->minchunk
			&& pile_a[liste->f].place <= liste->maxchunk)
			first_to_b(pile_a, pile_b, liste);
		else if (pile_a[liste->e].place >= liste->minchunk
			&& pile_a[liste->e].place <= liste->maxchunk)
			end_to_b(pile_a, pile_b, liste);
		(liste->f)++;
		(liste->e)--;
	}
}

void	tri_b(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	liste->f = 0;
	liste->height = taille(pile_b);
	liste->e = liste->height;
	liste->nbr = 100;
	while (liste->nbr >= 1)
	{
		if (pile_b[liste->f].place == liste->nbr)
			first_to_a(pile_a, pile_b, liste);
		else if (pile_b[liste->e].place == liste->nbr)
			end_to_a(pile_a, pile_b, liste);
		(liste->f)++;
		(liste->e)--;
	}
}

void	algo_100(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	liste->cpt = 1;
	liste->minchunk = 0;
	liste->maxchunk = liste->len / CHUNK;
	while (liste->maxchunk <= liste->len)
	{
		go_to_b(pile_a, pile_b, liste);
		liste->maxchunk += liste->len / CHUNK;
		liste->minchunk += liste->len / CHUNK;
	}
	gob(pile_a, pile_b, liste);
	tri_b(pile_a, pile_b, liste);
}
