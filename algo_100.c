/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:14:18 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/30 13:14:22 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ra_or_rra(int nbr, int maxpile)
{
	if (nbr > maxpile)
		return (1);
	return (0);
}

void	tri(t_liste *pile_a, t_liste *pile_b, int len)
{
	int	i;
	int	maxchunk;

	i = 0;
	maxchunk = 19;
	while (maxchunk >= 0)
	{
		if (pile_b[i].place == maxchunk && i <= 9)
		{
			while (pile_b[i].place != pile_b[0].place)
			{
				rb(pile_b, len);
				i--;
			}
			pa(pile_a, pile_b, len);
			i = 0;
			maxchunk--;
		}
		else if (pile_b[i].place == maxchunk && i > 9)
		{
			while (pile_b[i].place != pile_b[19].place)
			{
				rrb(pile_b, len);
				i++;
			}
			rrb(pile_b, len);
			pa(pile_a, pile_b, len);
			i = 0;
			maxchunk--;
		}
		i++;
	}
}

void	algo_100(t_liste *pile_a, t_liste *pile_b, int len)
{
	int	minchunk;
	int	maxchunk;
	int	cpt;
	int	i;

	minchunk = 80;
	maxchunk = 100;
	cpt = 80;
	i = 0;
	while (cpt <= maxchunk)
	{
		if (pile_a[i].place >= minchunk && pile_a[i].place <= maxchunk)
		{
			// if (i < (len / 2))
			// {
				while (pile_a[i].place != pile_a[0].place)
				{
					ra(pile_a, len);					
					i--;
				}
				pb(pile_a, pile_b, len);
				i = 0;
				cpt++;
			// }
			// else if (i >= (len / 2))
			// {
			// 	while (i <= 99)
			// 	{
			// 		rra(pile_a, len);
			// 		i++;
			// 	}
			// 	rra(pile_a, len);
			// 	pb(pile_a, pile_b, len);
			// 	i = 0;
			// 	cpt++;
			// }
		}
		i++;
	}
	tri(pile_a, pile_b, len);
	// while (maxchunk >= minchunk)
	// {
	// 	tri(pile_a, pile_b, maxchunk, len);
	// 	maxchunk--;
	// }
}