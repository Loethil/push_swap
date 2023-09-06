/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:46:46 by mbatteux          #+#    #+#             */
/*   Updated: 2023/08/21 14:46:48 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*probleme atoi nombre trop grand a regler*/
void	changes(t_liste *pile_a, t_liste *pile_b, t_struct *liste)
{
	int	i;

	i = 0;
	while (i < liste->len)
	{
		printf("[%d]\t\t[%d]", pile_a[i].place, pile_b[i].place);
		printf("\n");
		i++;
	}
	printf(" _\t\t _\n");
	printf(" a\t\t b\n");
}

t_liste	*create_pile_a(char **argv, t_struct *liste, t_liste *pile_a, t_liste *pile_b)
{
	int	j;
	int	i;

	j = 1;
	i = 0;
	while (i < liste->len)
	{
		if (verif_argv(argv[j]) == 0)
		{
			pile_a[i].value = ft_atoi(argv[j]);
			j++;
			i++;
		}
		else if (verif_argv(argv[j]) == 1)
		{
			printf("ERROR\nLETTRES INTERDITES");
			oppenheimer(pile_a, pile_b);
		}
	}
	return (pile_a);
}

void	replace_number(t_liste *pile_a, t_struct *liste)
{
	int	i;

	liste->pos = 1;
	while (liste->pos <= liste->len)
	{
		i = -1;
		liste->lower = 2147483647;
		while (++i < liste->len)
		{
			if (pile_a[i].value < liste->lower)
			{
				liste->lower = pile_a[i].value;
				liste->place = i;
				i = -1;
			}
		}
		pile_a[liste->place].place = liste->pos;
		pile_a[liste->place].value = 2147483647;
		(liste->pos)++;
	}
}

int	main(int argc, char **argv)
{
	t_liste		*pile_a;
	t_liste		*pile_b;
	t_struct	liste;

	liste.len = argc - 1;
	pile_a = malloc((argc - 1) * sizeof(t_liste));
	pile_b = malloc((argc - 1) * sizeof(t_liste));
	pile_a = create_pile_a(argv, &liste, pile_a, pile_b);
	replace_number(pile_a, &liste);
	if (liste.len < 1)
		return (0);
	if (liste.len == 2)
		algo_2(pile_a);
	if (liste.len == 3)
		algo_3(pile_a, &liste);
	if (liste.len == 5)
		algo_5(pile_a, pile_b, &liste);
	if (liste.len == 100)
		algo_100(pile_a, pile_b, &liste);
	else
		algo_all(pile_a, pile_b, &liste);
	return (0);
}
