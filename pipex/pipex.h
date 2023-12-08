/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:12:39 by mbatteux          #+#    #+#             */
/*   Updated: 2023/09/20 18:12:41 by mbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define RDM "/dev/urandom"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft.h"

typedef struct s_cmd
{
	int		num;
	int		rd;
	int		wrt;
	char	**argv;
	char	*true_path;
}			t_cmd;

typedef struct s_data
{
	char	**all_path;
	char	*true_path;
	int		nbr;
	int		pipe_fd[2];
	pid_t	*pid;
	int		fdin;
	int		fdout;
	t_cmd 	*cmd;
}		t_data;


void	find_path(t_data *pip, char **env);
void	free_tabs(char **tab);
char	*theword(int *i, const char *s, char c);
char	*get_access(t_data *pip, t_cmd *cmd, char *argv);
int		countword(char const *s, char c);
void	oppenheimer(t_data *pip);
void	error(char *err, t_data *pip);
// void	proc_1(t_data *pip, char **env, char **argv, int *pipe_fd);
// void	proc_2(t_data *pip, char **env, char **argv, int *pipe_fd);
void	free_argv(t_data *pip);

#endif
