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

void	free_tabs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	error(char *err, t_data *pip)
{
	(void)pip;
	write(1, err, ft_strlen(err));
	exit(1);
}

void	find_path(t_data *pip, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	pip->all_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (pip->all_path[i])
	{
		pip->all_path[i] = ft_strjoin(pip->all_path[i], "/");
		i++;
	}
}

char	*get_access(t_data *pip, t_cmd *cmd, char *argv)
{
	int	i;

	i = 0;
	if (access(argv, X_OK) == 0)
		return (argv);
	while (pip->all_path[i])
	{
		cmd->true_path = ft_strjoin(pip->all_path[i], argv);
		if (access(cmd->true_path, X_OK) == 0)
			return (cmd->true_path);
		free(cmd->true_path);
		i++;
	}
	free_tabs(cmd->argv);
	free_tabs(cmd->argv);
	free(pip->all_path);
	write (1, "command not found\n", 18);
	exit(1);
}
