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
		printf("[%d]\t\t[%d]",pile_a[i].value, pile_b[i].value);
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

void	test(t_liste *pile_a, t_liste *pile_b, int count)
{
	printf("\n");
	push_b(pile_a, pile_b, count);
	printf("push_b\n\n");
	changes(pile_a, pile_b, count);
	printf("\n");
	push_b(pile_a, pile_b, count);
	printf("push_b\n\n");
	changes(pile_a, pile_b, count);
	printf("\n");
	push_a(pile_a, pile_b, count);
	printf("push_a\n\n");
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
	changes(pile_a, pile_b, count);
	test(pile_a, pile_b, count);
	return (0);
}