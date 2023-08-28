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
void	changes(t_liste *pile_a, t_liste *pile_b, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("[%d]\t\t[%d]",pile_a[i].place, pile_b[i].place);
		printf("\n");
		i++;
	}
	printf(" _\t\t _\n");
	printf(" a\t\t b\n");
}

t_liste	*create_pile_a(char **argv, int count, t_liste *pile_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < count)
	{
		pile_a[i].value = ft_atoi(argv[j]);
		j++;
		i++;
	}
	return (pile_a);
}

<<<<<<< HEAD
void	replace_number(t_liste *pile_a, int count)
{
	int	lower;
	int	i;
	int	pos;
	int	place;

	pos = 1;
	while(pos <= count)
	{
		i = -1;
		lower = 2147483647;
		while(++i < count)
		{
			if(pile_a[i].value < lower)
			{
				lower = pile_a[i].value;
				place = i;
				i = -1;
			}
		}
		pile_a[place].place = pos;
		pile_a[place].value = 2147483647;
		pos++;
	}
}

=======
>>>>>>> 422a7dad2eeda4eef499369c3c336283e7119592
void	test(t_liste *pile_a, t_liste *pile_b, int count)
{
	printf("\n");
	pb(pile_a, pile_b, count);
	printf("pb\n\n");
	changes(pile_a, pile_b, count);
	printf("\n");
	pb(pile_a, pile_b, count);
	printf("pb\n\n");
	changes(pile_a, pile_b, count);
	printf("\n");
	pa(pile_a, pile_b, count);
	printf("pa\n\n");
	changes(pile_a, pile_b, count);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_liste	*pile_a;
	t_liste *pile_b;
	int	count;

	count = argc - 1;
	pile_a = malloc((argc - 1) * sizeof(t_liste));
	pile_b = malloc((argc - 1) * sizeof(t_liste));
	pile_a = create_pile_a(argv, count, pile_a);
	replace_number(pile_a, count);
	changes(pile_a, pile_b, count);
	// test(pile_a, pile_b, count);
	return (0);
}