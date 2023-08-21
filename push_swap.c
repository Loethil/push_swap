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

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	tab[argc];

	i = 0;
	j = 1;
	while (i < argc - 1)
	{
		tab[i] = ft_atoi(argv[j]);
		j++;
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		printf("case %d = %d\n", i, tab[i]);
		i++;
	}
	return (0);
}