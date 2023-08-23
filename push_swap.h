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

typedef struct s_data
{
	int	*pile_a;
	int	*pile_b;
	int	pilelen;
}		t_data;

int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void	swap_a(t_data *try);
void	swap_b(t_data *try);
void	swap_s(t_data *try);
void	push_b(t_data *try);
void	push_a(t_data *try);
void	go_up(t_data *try, int	*pile);
void	go_down(t_data *try, int *pile);
void	rotate_a(t_data *try);
void	rotate_b(t_data *try);
void	rotate_r(t_data *try);
void	reverse_rotate_r(t_data *try);
void	reverse_rotate_b(t_data *try);
void	reverse_rotate_a(t_data *try);


#endif