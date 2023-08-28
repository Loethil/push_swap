/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:44:34 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/23 13:44:35 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

<<<<<<< HEAD
void	ra(t_liste *pile_a, int count)
=======
//Décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
void	reverse_rotate_a(t_liste *pile_a, int count)
>>>>>>> 422a7dad2eeda4eef499369c3c336283e7119592
{
	int	i;
	int	c;

	i = 0;
	c = pile_a[0].value;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	i = 0;
	while (i < count - 1)
	{
		pile_a[i].value = pile_a[i + 1].value;
		i++;
	}
	pile_a[i].value = c;
}
//-1 car argc compte de 1 a 6 et i de 0 a 5
<<<<<<< HEAD
void	rb(t_liste *pile_b, int count)
=======
//Décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
void	reverse_rotate_b(t_liste *pile_b, int count)
>>>>>>> 422a7dad2eeda4eef499369c3c336283e7119592
{
	int	i;
	int	c;

	i = 0;
	c = pile_b[0].value;
	while (i < count - 1)
		i++;
	if (i > count)
		return ;
	i = 0;
	while (i < count - 1)
	{
		pile_b[i].value = pile_b[i + 1].value;
		i++;
	}
	pile_b[i].value = c;
}
<<<<<<< HEAD
void	rr(t_liste *pile_a, t_liste *pile_b, int count)
=======
//rra et rrb en même temps.
void	reverse_rotate_r(t_liste *pile_a, t_liste *pile_b, int count)
>>>>>>> 422a7dad2eeda4eef499369c3c336283e7119592
{
	ra(pile_a, count);
	rb(pile_b, count);
}
