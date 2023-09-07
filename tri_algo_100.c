/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_algo_100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:57:38 by mbatteux          #+#    #+#             */
/*   Updated: 2023/09/07 16:57:43 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	first_to_b(t_liste *pile_a, t_liste *pile_b,
	t_struct *liste)
{
	while (liste->f != 0)
	{
		ra(pile_a, liste);
		liste->f--;
	}
	pb(pile_a, pile_b, liste);
	(liste->height)--;
	(liste->cpt)++;
	liste->f = -1;
}

void	end_to_b(t_liste *pile_a, t_liste *pile_b,
	t_struct *liste)
{
	while (liste->e != liste->height)
	{
		rra(pile_a, liste);
		(liste->e)++;
	}
	rra(pile_a, liste);
	pb(pile_a, pile_b, liste);
	(liste->cpt)++;
	(liste->height)--;
}

void	first_to_a(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	while (liste->f != 0)
	{
		rb(pile_b, liste);
		(liste->f)--;
	}
	pa(pile_a, pile_b, liste);
	liste->e = liste->height;
	(liste->height)--;
	liste->f = -1;
	(liste->nbr)--;
}

void	end_to_a(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	while (liste->e != liste->height)
	{
		rrb(pile_b, liste);
		(liste->e)++;
	}
	rrb(pile_b, liste);
	pa(pile_a, pile_b, liste);
	liste->f = -1;
	(liste->height)--;
	(liste->nbr)--;
}
