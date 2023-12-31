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
# include <unistd.h>

typedef struct s_liste
{
	int	value;
	int	place;
}		t_liste;

typedef struct s_struct
{
	int			maxchunk;
	int			minchunk;
	int			len;
	int			cpt;
	int			place;
	int			pos;
	long int	lower;
	int			height;
	int			f;
	int			e;
	int			nbr;
}		t_struct;

long int	ft_atoi(const char *str);
int			ft_isdigit(char c);
void		changes(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
int			diff(int a, int b);
int			taille(t_liste *pile_a);
int			verif_argv(char *argv);
void		check_duplicate(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		gob(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
int			oppenheimer(t_liste *pile_a, t_liste *pile_b);
void		go_down(t_liste *pile, t_struct *liste);
void		go_up(t_liste *pile, t_struct *liste);
void		replace_number(t_liste *pile_a, t_struct *liste);
int			verif_suite(t_liste *pile_a, t_struct *liste);
void		algo_2(t_liste *pile_a);
void		algo_3(t_liste *pile_a, t_struct *liste);
void		algo_5(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		algo_100(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		algo_500(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		algo_all(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		end_to_a(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		first_to_a(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		first_to_b(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		end_to_b(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		sa(t_liste *pile_a);
void		sb(t_liste *pile_b);
void		ss(t_liste *pile_a, t_liste *pile_b);
void		pa(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		pb(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		ra(t_liste *pile_a, t_struct *liste);
void		rb(t_liste *pile_b, t_struct *liste);
void		rr(t_liste *pile_a, t_liste *pile_b, t_struct *liste);
void		rra(t_liste *pile_a, t_struct *liste);
void		rrb(t_liste *pile_b, t_struct *liste);
void		rrr(t_liste *pile_a, t_liste *pile_b, t_struct *liste);

#endif
