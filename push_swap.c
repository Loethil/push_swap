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
int	*create_pile_a(char **argv, t_data *try)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < try->pilelen)
	{
		try->pile_a[i] = ft_atoi(argv[j + 1]);
		j++;
		i++;
	}
	i = 0;
	while (i < try->pilelen)
	{
		printf("pile_a %d = %d    ", i, try->pile_a[i]);
		printf("pile_b %d = %d\n", i, try->pile_b[i]);
		i++;
	}
	printf("\n");
	return (try->pile_a);
}

void	changes(t_data *try)
{
	int	i;

	i = 0;
	while (i < try->pilelen)
	{
		printf("pile_a %d = %d    ", i, try->pile_a[i]);
		printf("pile_b %d = %d\n", i, try->pile_b[i]);
		i++;
	}
	printf("\n");
}

void	test(t_data *try)
{
	push_b(try);
	printf("push_b\n");
	changes(try);
	rotate_b(try, try->pile_b);
	printf("rotate_b\n");
	changes(try);
	push_a(try);
	printf("push_a\n");
	changes(try);
	rotate_a(try, try->pile_a);
	printf("rotate_a\n");
	changes(try);
	rotate_r(try, try->pile_a, try->pile_b);
	printf("rotate_r\n");
	changes(try);
	reverse_rotate_r(try, try->pile_a, try->pile_b);
	printf("reverse_rotate_r\n");
	changes(try);

}

int	main(int argc, char **argv)
{
	t_data	try;

	try.pilelen = argc - 1;
	try.pile_a = malloc (try.pilelen * sizeof(int));
	try.pile_b = malloc (try.pilelen * sizeof(int));
	if (!try.pile_a || !try.pile_b)
		return (0);
	try.pile_a = create_pile_a(argv, &try);
	test(&try);
	// free (try.pile_a);
	// free (try.pile_b);
	return (0);
}