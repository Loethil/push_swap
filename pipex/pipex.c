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

// void	proc_1(t_data *pip, char **env, char **argv, int *pipe_fd)
// {
// 	pip->fdin = open(argv[1], O_RDONLY);
// 	if (pip->fdin == -1)
// 		error("Error file\n", pip);
// 	close(pipe_fd[0]);
// 	pip->true_path = get_access(pip, pip->argv1[0]);
// 	if (dup2(pip->fdin, STDIN_FILENO) == -1)
// 		error("Error dup2\n", pip);
// 	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
// 		error("Error dup2\n", pip);
// 	close(pipe_fd[1]);
// 	if (execve(pip->true_path, pip->argv1, env) == -1)
// 		error("Error execve\n", pip);
// }

// void	proc_2(t_data *pip, char **env, char **argv, int *pipe_fd)
// {
// 	pip->fdout = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
// 	if (pip->fdout == -1)
// 		error("Error file\n", pip);
// 	close(pipe_fd[1]);
// 	pip->true_path = get_access(pip, pip->argv2[0]);
// 	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
// 		error("Error dup2\n", pip);
// 	if (dup2(pip->fdout, STDOUT_FILENO) == -1)
// 		error("Error dup2\n", pip);
// 	close(pipe_fd[0]);
// 	if (execve(pip->true_path, pip->argv2, env) == -1)
// 		error("Error execve\n", pip);
// }

// void	herewego(t_data *pip, char **env, char **argv, int *pipe_fd)
// {
// 	int	status;
// 	pip->true_path = NULL;
// 	find_path(pip, env);
// 	pip->pid = fork();
// 	if (pip->pid == -1)
// 		error("Error pid\n", pip);
// 	else if (pip->pid == 0)
// 		proc_1(pip, env, argv, pipe_fd);
// 	else
// 		waitpid(pip->pid, &status, 0);
// 	pip->pid2 = fork();
// 	if (pip->pid2 == -1)
// 		error("Error pid\n", pip);
// 	else if (pip->pid2 == 0)
// 		proc_2(pip, env, argv, pipe_fd);
// 	else
// 		waitpid(pip->pid, &status, 0);
// }

int	set_pid(t_data *pip, t_cmd *cmd, char **argv, int *pipe_fd)
{
	int	i = 0;

	(void)argv;
	(void)pipe_fd;
	// pipe_fd = malloc (pip->nbr * sizeof(int[2]));
	// if (pipe(pipe_fd) == -1)
	// 	return (-1);
	while (i < pip->nbr)
	{
		cmd[i].num = i;
		cmd[i].rd = i * 2;
		cmd[i].wrt = i * 2 + 1;
		printf("moi %d, je lis sur %d, j'ecris sur %d\n", i, cmd[i].rd, cmd[i].wrt);
		i++;
	}
	return (0);
}

void	first_proc(t_data *pip, t_cmd *cmd, char **env, int *pipe_fd)
{
	close(pipe_fd[0]);
	pip->true_path = get_access(pip, cmd , cmd->argv[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		error("Error dup2\n", pip);
	close(pipe_fd[1]);
	if (execve(cmd->true_path, cmd->argv, env) == -1)
		error("Error execve\n", pip);
}

void	middle_proc(t_data *pip, t_cmd *cmd, char **env, int *pipe_fd)
{
	close(pipe_fd[1]);
	pip->true_path = get_access(pip, cmd , cmd->argv[0]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error("Error dup2\n", pip);
	close(pipe_fd[0]);
	// if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	// 	error("Error dup2\n", pip);
	if (execve(cmd->true_path, cmd->argv, env) == -1)
		error("Error execve\n", pip);
}

void	last_proc(t_data *pip, t_cmd *cmd, char **env, int *pipe_fd)
{
	close(pipe_fd[1]);
	pip->true_path = get_access(pip, cmd ,cmd->argv[0]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		error("Error dup2\n", pip);
	// if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	// 	error("Error dup2\n", pip);
	close(pipe_fd[1]);
	if (execve(cmd->true_path, cmd->argv, env) == -1)
		error("Error execve\n", pip);
}

void	proc(t_data *pip, t_cmd *cmd, char **env, int *pipe_fd)
{
	if (cmd->num == 0)
		first_proc(pip, cmd, env, pipe_fd);
	else if ( cmd->num == pip->nbr)
		return ;
		// last_proc(pip, cmd, env, pipe_fd);
	else
		middle_proc(pip, cmd, env, pipe_fd);
		// return ;
}

//tester avec un tableau de pipe, vairable deja dans la struct plus qu'a l'allouer

void	herewego(t_data *pip, t_cmd *cmd, char **env, int *pipe_fd)
{
	int	status;
	int	i = 0;
	pid_t	*pid;

	pip->true_path = NULL;
	find_path(pip, env);
	pid = malloc (pip->nbr * sizeof(pid_t));
	if (!pid)
		return ;
	while (i < pip->nbr)
	{
		pid[i] = fork();
		if (pid[i] == -1)
			error("Error pid\n", pip);
		else if (pid[i] == 0)
			proc(pip, &cmd[i], env, pipe_fd);
		else
			waitpid(pid[i], &status, 0);
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data	*pip;
	t_cmd	*cmd;
	int	i = 0;

	if (argc != 4)
		return (0);
	(void)env;
	pip = malloc (sizeof(t_data));
	pip->nbr = argc - 1;
	cmd = malloc (pip->nbr * sizeof (t_cmd *));
	set_pid(pip, cmd, argv, pip->pipe_fd);
	if (ft_strncmp(argv[1], RDM, ft_strlen(RDM)) == 0)
	{
		write(1, "urandom detected\n", 17);
		return (0);
	}
	if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0)
	{
		write(1, "missing arguments\n", 18);
		return (0);
	}
	while (i < pip->nbr)
	{
		cmd[i].argv = ft_split(argv[i + 1], ' ');
		i++;
	}
	herewego(pip, cmd, env, pip->pipe_fd);
	error("", pip);
	return (0);
}
