/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:13:40 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/23 13:13:41 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

<<<<<<< HEAD
void	ra(t_liste *pile_a, int count)
=======
//Décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
void	rotate_a(t_liste *pile_a, int count)
>>>>>>> 422a7dad2eeda4eef499369c3c336283e7119592
{
	int	i;
	int	c;

	i = 0;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	c = pile_a[i].value;
	while (i > 0)
	{
		pile_a[i].value = pile_a[i - 1].value;
		i--;
	}
	pile_a[0].value = c;
}
//-1 car argc compte de 1 a 6 et i de 0 a 5
<<<<<<< HEAD
void	rb(t_liste *pile_b, int count)
=======
//Décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
void	rotate_b(t_liste *pile_b, int count)
>>>>>>> 422a7dad2eeda4eef499369c3c336283e7119592
{
	int	i;
	int	c;

	i = 0;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	c = pile_b[i].value;
	while (i > 0)
	{
		pile_b[i].value = pile_b[i - 1].value;
		i--;
	}
	pile_b[0].value = c;
}
<<<<<<< HEAD
void	rr(t_liste *pile_a, t_liste *pile_b, int count)
=======
//ra et rb en même temps.
void	rotate_r(t_liste *pile_a, t_liste *pile_b, int count)
>>>>>>> 422a7dad2eeda4eef499369c3c336283e7119592
{
	ra(pile_a, count);
	rb(pile_b, count);
}