/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:47:21 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/21 14:47:23 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_liste
{
	int	value; // valeur reel grace a argv
	int	place; // postions dans la liste
}		t_liste;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void	push_a(t_liste *pile_a, t_liste *pile_b, int count);
void	push_b(t_liste *pile_a, t_liste *pile_b, int count);
void	go_down(t_liste *pile, int count);
void	go_up(t_liste *pile, int count);
void	swap_a(t_liste *pile_a);
void	swap_b(t_liste *pile_b);
void	swap_s(t_liste *pile_a, t_liste *pile_b);
void	rotate_a(t_liste *pile_a, int count);
void	rotate_b(t_liste *pile_b, int count);
void	rotate_r(t_liste *pile_a, t_liste *pile_b, int count);
void	reverse_rotate_a(t_liste *pile_a, int count);
void	reverse_rotate_b(t_liste *pile_b, int count);
void	reverse_rotate_r(t_liste *pile_a, t_liste *pile_b, int count);

#endif