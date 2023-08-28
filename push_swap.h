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
void	go_down(t_liste *pile, int count);
void	go_up(t_liste *pile, int count);
void	replace_number(t_liste *pile_a, int count);
void	sa(t_liste *pile_a);
void	sb(t_liste *pile_b);
void	ss(t_liste *pile_a, t_liste *pile_b);
void	pa(t_liste *pile_a, t_liste *pile_b, int count);
void	pb(t_liste *pile_a, t_liste *pile_b, int count);
void	ra(t_liste *pile_a, int count);
void	rb(t_liste *pile_b, int count);
void	rr(t_liste *pile_a, t_liste *pile_b, int count);
void	ra(t_liste *pile_a, int count);
void	rb(t_liste *pile_b, int count);
void	rr(t_liste *pile_a, t_liste *pile_b, int count);

#endif