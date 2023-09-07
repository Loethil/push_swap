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

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	return (1);
}
