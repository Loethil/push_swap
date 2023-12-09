/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:17:19 by mbatteux          #+#    #+#             */
/*   Updated: 2023/09/12 14:17:20 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	set_cmd(t_data *pip, t_cmd *cmd, char **argv)
{
	int	i = 0;

	pip->pid = malloc (pip->nbr * sizeof(pid_t));
	find_path(pip);
	while (i < pip->nbr)
	{
		cmd[i].num = i;
		cmd[i].argv = ft_split(argv[i + 1], ' ');
		cmd[i].argv[1] = NULL;
		cmd[i].true_path = get_access(pip, cmd[i].argv[0]);
		// printf("moi %d, j'ai comme commande '%s', avec le path '%s'\n", i, cmd[i].argv[0], cmd[i].true_path);
		i++;
	}
}

void	first_proc(t_cmd cmd, char **env, int *pipe_fd)
{
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("error ");
		exit (0);
	}
	close(pipe_fd[1]);
	if (execve(cmd.true_path, cmd.argv, env) == -1)
	{
		perror("error ");
		exit (0);
	}
}

void	proc(t_cmd cmd, char **env, int *pipe_fd, int input_fd)
{
	printf("%s\n", cmd.argv[0]);
	close(pipe_fd[0]);
	if (dup2(input_fd, STDIN_FILENO) == -1)
	{
		perror("error ");
		exit (0);
	}
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("error ");
		exit (0);
	}
	close(pipe_fd[1]);
	if (execve(cmd.true_path, cmd.argv, env) == -1)
	{
		perror("error ");
		exit (0);
	}
}

void	last_proc(t_cmd cmd, char **env, int *pipe_fd, int input_fd)
{
	close(pipe_fd[0]);
	if (dup2(input_fd, STDIN_FILENO) == -1)
	{
		perror("error ");
		exit (0);
	}
	close(pipe_fd[1]);
	if (execve(cmd.true_path, cmd.argv, env) == -1)
	{
		perror("error ");
		exit (0);
	}
}

void	herewego(t_data *pip, t_cmd *cmd, char **env)
{
	int	status;
	int	input_fd;
	int	i = 0;

	input_fd = STDIN_FILENO;
	printf("%d\n", input_fd);
	while (i < pip->nbr)
	{
		int	pipe_fd[2];

		pipe(pipe_fd);
		pip->pid[i] = fork();
		if (pip->pid[i] == -1)
		{
			perror("error ");
			exit (0);
		}
		else if (pip->pid[i] == 0)
		{
			if (i == 0)
			{
				first_proc(cmd[i], env, pipe_fd);
			}
			else if (i == pip->nbr)
				// last_proc(cmd[i], env, pipe_fd, input_fd);
				return ;
			else
				proc(cmd[i], env, pipe_fd, input_fd);
		}
		else
		{
			waitpid(pip->pid[i], &status, 0);
			input_fd = pipe_fd[0];
		}
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	*pip;
	t_cmd	*cmd;

	if (argc != 4)
		return (0);
	(void)env;
	pip = malloc (sizeof(t_data));
	pip->nbr = argc - 1;
	cmd = malloc (pip->nbr * sizeof (t_cmd *));
	set_cmd(pip, cmd, argv);
	herewego(pip, cmd, env);
	return (0);
}
