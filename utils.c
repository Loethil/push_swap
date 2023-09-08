/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:29:12 by mbatteux          #+#    #+#             */
/*   Updated: 2023/09/07 17:29:15 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	verif_argv(char *argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] == '-')
			i++;
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (1);
	}
	return (0);
}

void	check_duplicate(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	while (j < liste->len)
	{
		c = pile_a[j].value;
		while (i < liste->len)
		{
			if (i == j)
				i++;
			if (c == pile_a[i].value)
			{
				printf("ERROR\n");
				oppenheimer(pile_a, pile_b);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}
