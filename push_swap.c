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
void	changes(t_liste *pile_a, t_liste *pile_b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("[%d]\t\t[%d]",pile_a[i].place, pile_b[i].place);
		printf("\n");
		i++;
	}
	printf(" _\t\t _\n");
	printf(" a\t\t b\n");
}

t_liste	*create_pile_a(char **argv, int len, t_liste *pile_a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < len)
	{
		pile_a[i].value = ft_atoi(argv[j]);
		j++;
		i++;
	}
	return (pile_a);
}

void	replace_number(t_liste *pile_a, int len)
{
	int	lower;
	int	i;
	int	pos;
	int	place;

	pos = 1;
	while(pos <= len)
	{
		i = -1;
		lower = 2147483647;
		while(++i < len)
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

int	main(int argc, char **argv)
{
	t_liste	*pile_a;
	t_liste *pile_b;
	int	len;

	len = argc - 1;
	pile_a = malloc((argc - 1) * sizeof(t_liste));
	pile_b = malloc((argc - 1) * sizeof(t_liste));
	pile_a = create_pile_a(argv, len, pile_a);
	replace_number(pile_a, len);
	// changes(pile_a, pile_b, len);
	if (len == 2)
		algo_2(pile_a);
	if (len == 3)
		algo_3(pile_a, len);
	if (len == 5)
		algo_5(pile_a, pile_b, len);
	if (len == 100)
		algo_100(pile_a, pile_b, len);
	// changes(pile_a, pile_b, len);
	// printf("count = %d", count);
	return (0);
}