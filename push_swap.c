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
int	*createpilea(int argc, char **argv, t_data *try)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc - 1)
	{
		try->pilea[i] = ft_atoi(argv[j + 1]);
		j++;
		i++;
	}
	i = 0;
	while (i < argc - 1)
	{
		printf("case %d = %d\n", i, try->pilea[i]);
		i++;
	}
	return (try->pilea);
}
int	main(int argc, char **argv)
{
	t_data	try;
	try.pilea = malloc (argc * sizeof(int));
	if (!try.pilea)
		return (0);
	try.pilea = createpilea(argc, argv, &try);
	free (try.pilea);
	return (0);
}