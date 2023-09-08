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

t_liste	*create_pile_a(char **argv, t_struct *liste,
	t_liste *pile_a, t_liste *pile_b)
{
	int	j;
	int	i;

	j = 1;
	i = 0;
	while (i < liste->len)
	{
		if ((verif_argv(argv[j]) == 1))
		{
			printf("ERROR\n");
			oppenheimer(pile_a, pile_b);
		}
		else if ((ft_atoi(argv[j]) > 2147483647)
			|| (ft_atoi(argv[j]) < -2147483648))
		{
			printf("ERROR\n");
			oppenheimer(pile_a, pile_b);
		}
		else if (verif_argv(argv[j]) == 0)
			pile_a[i].value = ft_atoi(argv[j++]);
		i++;
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
		liste->lower = 2147483648;
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
	pile_a = malloc((argc) * sizeof(t_liste));
	pile_b = calloc(sizeof(t_liste), (argc));
	pile_a = create_pile_a(argv, &liste, pile_a, pile_b);
	check_duplicate(pile_a, pile_b, &liste);
	replace_number(pile_a, &liste);
	if (liste.len < 1)
		return (0);
	else if (liste.len == 3)
		algo_3(pile_a, &liste);
	else if (liste.len == 5)
		algo_5(pile_a, pile_b, &liste);
	else if (liste.len == 100)
		algo_100(pile_a, pile_b, &liste);
	else if (liste.len == 500)
		algo_500(pile_a, pile_b, &liste);
	else
		algo_all(pile_a, pile_b, &liste);
	oppenheimer(pile_a, pile_b);
	return (0);
}
