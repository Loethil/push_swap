/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:28:13 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/22 14:28:15 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

<<<<<<< HEAD
void	sa(t_liste *pile_a)
=======
//Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
void	swap_a(t_liste *pile_a)
>>>>>>> 422a7dad2eeda4eef499369c3c336283e7119592
{
	int	c;

	c = pile_a[1].value;
	pile_a[1].value = pile_a[0].value;
	pile_a[0].value = c;
}

<<<<<<< HEAD
void	sb(t_liste *pile_b)
=======
// Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
void	swap_b(t_liste *pile_b)
>>>>>>> 422a7dad2eeda4eef499369c3c336283e7119592
{
	int	c;

	c = pile_b[1].value;
	pile_b[1].value = pile_b[0].value;
	pile_b[0].value = c;
}

<<<<<<< HEAD
void	ss(t_liste *pile_a, t_liste *pile_b)
=======
//sa et sb en même temps
void	swap_s(t_liste *pile_a, t_liste *pile_b)
>>>>>>> 422a7dad2eeda4eef499369c3c336283e7119592
{
	sa(pile_a);
	sb(pile_b);
}
