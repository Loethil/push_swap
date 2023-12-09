/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:15:37 by mbatteux          #+#    #+#             */
/*   Updated: 2023/09/20 18:15:39 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	find_path(t_data *pip)
{
	char 	*path;
	int		i;

	i = 0;
	path = getenv("PATH");
	pip->all_path = ft_split(path, ':');
	while (pip->all_path[i])
	{
		pip->all_path[i] = ft_strjoin(pip->all_path[i], "/");
		i++;
	}
}

char	*get_access(t_data *pip, char *str)
{
	char	*tab;
	int		i;
	i = 0;
	if (access(str, X_OK) == 0)
		return (str);
	while (pip->all_path[i])
	{
		tab = ft_strjoin(pip->all_path[i], str);
		if (access(tab, X_OK) == 0)
			return (tab);
		free(tab);
		i++;
	}
	write (1, "command not found\n", 18);
	exit(1);
}
